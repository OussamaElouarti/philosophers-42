#include "philo_one.h"

void    ft_sleep(t_phil *philo)
{
    printf("is sleeping id :%d\n" ,philo->id);
    pthread_mutex_unlock(&philo->thread->forks[philo->lfork]);
    pthread_mutex_unlock(&philo->thread->forks[philo->rfork]);
    usleep(philo->thread->time_to_sleep);
}