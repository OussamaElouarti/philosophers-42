#include "philo_one.h"

void	ft_free(t_threads *threads)
{
	int	i;

	i = 0;
	if (threads)
	{
		while (i < threads->philo_num)
			pthread_mutex_destroy(&threads->forks[i++]);
		free(threads->forks);
		pthread_mutex_destroy(&threads->write);
	}
}

void	supervisor(t_threads *threads)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < threads->philo_num)
		{
			if ((get_time() >= ((unsigned long long)threads->time_to_die
						+ threads->philosopher[i].last_meal))
				&& threads->philosopher[i].is_eating == 0)
			{
				pthread_mutex_lock(&threads->philosopher[i].eat);
				display("died", &threads->philosopher[i]);
				pthread_mutex_unlock(&threads->philosopher[i].eat);
				ft_free(threads);
				return ;
			}
			else if (threads->eat_counter == threads->philo_num)
			{
				ft_free(threads);
				return ;
			}
		}
		usleep(100);
	}
}

void	init_mutex(t_threads *threads)
{
	int	i;

	i = 0;
	threads->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* threads->philo_num);
	while (i < threads->philo_num)
	{
		pthread_mutex_init(&threads->forks[i], NULL);
		i++;
	}
}
