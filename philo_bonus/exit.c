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
	t_phil *philo;

	philo = (t_phil *)philosopher;
	while (1)
	{
		if ((get_time() >= ((unsigned long long)philo->thread->time_to_die
					+ philo->last_meal))
			&& philo->is_eating == 0)
		{
			// sem_wait(philo->thread->eat);
			display("died", philo);
			// sem_post(philo->thread->eat);
			//ft_free(philo->thread);
			exit(1);
		}
		else if (philo->thread->eat_counter == philo->thread->philo_num)
		{
			//ft_free(philo->thread);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}
