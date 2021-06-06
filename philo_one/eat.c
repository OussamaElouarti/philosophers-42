# include  "philo_one.h"

void    eat(t_phil *philo)
{
    pthread_mutex_lock(&philo->thread->forks[philo->lfork]);
    printf("take lfork id :%d\n" ,philo->id);
    pthread_mutex_lock(&philo->thread->forks[philo->rfork]);
    printf("take rfork id :%d\n" ,philo->id);
    printf("start eating id :%d\n" ,philo->id);
    usleep(philo->thread->time_to_eat);
}