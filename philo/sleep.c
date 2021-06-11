#include "philo_one.h"

void	ft_sleep(t_phil *philo)
{
	unsigned long long	time;
	
	pthread_mutex_unlock(&philo->thread->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->thread->forks[philo->rfork]);
	display("is sleeping", philo);
	time = get_time();
	usleep(philo->thread->time_to_sleep * 1000 - 14000);
	while ((get_time() - time)
		< (unsigned long long)philo->thread->time_to_sleep);
}
