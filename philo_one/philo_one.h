#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_phil
{
    int id;
    unsigned long long last_meal;
    int lfork;
    int rfork;
    int number_of_time_eat;
    int is_eating;
    pthread_mutex_t eat;
    struct s_threads *thread;
}              t_phil;

typedef struct s_threads
{ 
    unsigned long long time;
    int philo_num;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    int number_of_time_to_eat;
    int eat_counter;
    pthread_mutex_t write;
    struct s_phil *philosopher;
    pthread_mutex_t *forks;
}               t_threads;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
unsigned long long	get_time();
void    ft_sleep(t_phil *philo);
void    eat(t_phil *philo);
void    think(t_phil *philo);
void	display(char *msg, t_phil *philo);
int str_digit(char *str);
void    ft_free(t_threads *threads);

#endif