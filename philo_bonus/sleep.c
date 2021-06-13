#include "philo_bonus.h"

void	ft_sleep(t_phil *philo)
{
	unsigned long long	time;

	sem_post(philo->thread->forks);
	sem_post(philo->thread->forks);
	display("is sleeping", philo);
	time = get_time();
	usleep(philo->thread->time_to_sleep * 1000 - 14000);
	while ((get_time() - time)
		< (unsigned long long)philo->thread->time_to_sleep);
}
