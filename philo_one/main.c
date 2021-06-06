# include "philo_one.h"

void    init_mutex(t_threads *threads)
{
    int i;

    i = 0;
    threads->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * threads->philo_num);
    if (threads->forks == NULL)
    {
        printf("boooo3\n"); return ;
    }
    // pthread_mutex_t* forks;
    // forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * threads->philo_num);
    // printf("naddiii\n"); exit(0);
    while (i < threads->philo_num)
    {
        pthread_mutex_init(&threads->forks[i], NULL);
        i++;
    }
}

void    *routine(void *philosopher)
{
    t_phil *philo;
    philo = (t_phil *)philosopher;
    pthread_t t_id;
    philo->last_meal = get_time();
    pthread_create(&t_id, NULL, &supervisor, &philosopher);
    while (1)
    {
        think(philo);
        eat(philo);
        ft_sleep(philo);
    }
    return (NULL);
}

void    init_threads(t_threads *threads)
{
    pthread_t t_id;
    int i;

    i = 0;
    while  (i < threads->philo_num)
        pthread_create(&t_id, NULL, &routine,  &threads->philosopher[i++]);
    while (1);
}

t_phil    *init_philo(t_threads *threads)
{
    int i;
    t_phil *philosopher;

    i = 0;
    philosopher = (t_phil *)malloc(sizeof(t_phil) * threads->philo_num);
    if (philosopher == NULL)
    {
        return NULL;
    }
    while (i < threads->philo_num)
    {
        philosopher[i].id = i + 1;
        philosopher[i].number_of_time_eat = 0;
        philosopher[i].last_meal = get_time();
        philosopher[i].lfork = (i + 1) % threads->philo_num;
        philosopher[i].rfork = i;
        philosopher[i].thread = threads;
        i++;
    }
    return (philosopher);
}

int str_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (-1);
        i++;
    }
    return (0);
}

int   ft_parse(int argc, char **argv, t_threads *threads)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (str_digit(argv[i]) < 0)
            return(1);
        i++;
    }   
    if (argc == 5 || argc == 6)
    {
        if(argv[5])
            threads->number_of_time_to_eat = ft_atoi(argv[5]);
        else
            threads->number_of_time_to_eat = 0;
        threads->philo_num = ft_atoi(argv[1]);
        threads->time_to_die = ft_atoi(argv[2]);
        threads->time_to_sleep = ft_atoi(argv[4]);
        threads->time_to_eat = ft_atoi(argv[3]);
    }
    else
        return (2);
    threads->philosopher = init_philo(threads);
    return (0);
}

int     main(int argc, char **argv)
{
    t_threads threads;

    if (ft_parse(argc, argv, &threads))
    {
        write(2, "Not valid args!\n", 15);
        return (1);
    }
    init_mutex(&threads);
    init_threads(&threads);
    return (0);
}