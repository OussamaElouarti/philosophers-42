#include "philo_bonus.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n--)
	{
		if (*str1 == '\0' && *str2 == '\0')
			return (0);
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	return (0);
}

void	*eat_count(void	*thread_)
{
	t_threads	*threads;
	int			total;
	int			i;

	total = 0;
	threads = (t_threads *)thread_;
	while (total < threads->number_of_time_to_eat)
	{
		i = 0;
		while (i < threads->philo_num)
		{
			sem_wait(threads->philosopher[i].eat_m);
			i++;
		}
		total++;
	}
	sem_wait(threads->write);
	i = -1;
	while (++i < threads->philo_num)
		kill(threads->philosopher[i].pid, SIGKILL);
	return (NULL);
}

void	*supervisor(void *philosopher)
{
	t_phil	*philo;

	philo = (t_phil *)philosopher;
	while (1)
	{
		if ((get_time() >= ((unsigned long long)philo->thread->time_to_die
					+ philo->last_meal))
			&& philo->is_eating == 0)
		{
			display("died", philo);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	ft_kill(t_threads *threads)
{
	int	i;
	int	j;
	int	status;

	i = -1;
	while (++i < threads->philo_num)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			j = -1;
			while (++j < threads->philo_num)
				kill(threads->philosopher[j].pid, SIGKILL);
		}
	}
	exit(0);
}
