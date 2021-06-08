# include "philo_one.h"

void    ft_free(t_threads *threads)
{
    if (threads)
    {
        if (threads->forks)
            free(threads->forks);
        pthread_mutex_destroy(threads->forks);
        pthread_mutex_destroy(&threads->write);
        pthread_mutex_destroy(&threads->philosopher->eat);

    }
}