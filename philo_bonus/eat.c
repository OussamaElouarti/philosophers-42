#include  "philo_bonus.h"

void	eat(t_phil *philo)
{
	sem_wait(philo->thread->forks);
	display("taking lfork", philo);
	sem_wait(philo->thread->forks);
	display("taking rfork", philo);
	sem_wait(philo->thread->eat);
	display("start eating", philo);
	philo->last_meal = get_time();
	philo->is_eating = 1;
	philo->number_of_time_eat++;
	usleep(philo->thread->time_to_eat * 1000 - 14000);
	while ((get_time() - philo->last_meal)
		< (unsigned long long)philo->thread->time_to_eat);
	sem_post(philo->eat_m);
	sem_post(philo->thread->eat);
	philo->is_eating = 0;
}
