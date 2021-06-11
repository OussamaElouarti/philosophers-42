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

int	supervisor(t_threads *threads)
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
				display("died", &threads->philosopher[i]);
				ft_free(threads);
				return (1);
			}
			else if (threads->eat_counter == threads->philo_num)
			{
				ft_free(threads);
				return (1);
			}
		}
		usleep(100);
	}
	return (0);
}
