# include  "philo_one.h"

void    eat(t_phil *philo)
{
    pthread_mutex_lock(&philo->thread->forks[philo->lfork]);
    display("taking lfork", philo);
    pthread_mutex_lock(&philo->thread->forks[philo->rfork]);
    display("taking rfork", philo);
    display("start eating", philo);
    pthread_mutex_lock(&philo->eat);
    philo->last_meal = get_time();
    philo->is_eating = 1;
    philo->number_of_time_eat++;
    if (philo->number_of_time_eat == philo->thread->number_of_time_to_eat)
        philo->thread->eat_counter++;
    usleep(philo->thread->time_to_eat * 1000 - 14000);
    while ((get_time() - philo->last_meal)  < (unsigned long long)philo->thread->time_to_eat);
    pthread_mutex_unlock(&philo->eat);
    philo->is_eating = 0;
}