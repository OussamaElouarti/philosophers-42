#include "philo_bonus.h"

void	ft_free(t_threads *threads)
{
	int	i;

	i = 0;
	if (threads)
	{
		sem_post(threads->write);
		sem_close(threads->forks);
		sem_close(threads->eat);
		sem_close(threads->write);
	}
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
		else if (philo->number_of_time_eat
			== philo->thread->number_of_time_to_eat)
		{
			while (philo->last_meal >= 0)
				;
			exit(2);
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
		if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
			continue ;
		else if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			j = -1;
			while (++j < threads->philo_num)
				kill(threads->philosopher[j].pid, SIGKILL);
		}
	}
	j = -1;
	while (++j < threads->philo_num)
		kill(threads->philosopher[j].pid, SIGKILL);
	exit(0);
}
