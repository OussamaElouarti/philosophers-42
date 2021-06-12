 #include "philo_bonus.h"

void	*routine(t_phil *philosopher)
{
	
	
	philosopher->last_meal = get_time();
	while (1)
	{
		think(philosopher);
		eat(philosopher);
		ft_sleep(philosopher);
		// usleep(100);
	}
	return (NULL);
}

void	init_threads(t_threads *threads)
{
	int			i;
	pthread_t 	p_t;
	i = -1;
	threads->time = get_time();
	sem_unlink("writesem");
	threads->write = sem_open("writesem", O_CREAT, 0644, 1);
	sem_unlink("semeat");
	threads->eat = sem_open("semeat", O_CREAT, 0644, threads->philo_num / 2);
	while (++i < threads->philo_num)
	{
		threads->philosopher[i].pid = fork();
        if (threads->philosopher[i].pid < 0)
        {
            write(2, "fork failled!\n", 14);
            exit(1);
        }
        else if (threads->philosopher[i].pid == 0)
		{
			pthread_create(&p_t, NULL, &supervisor, &threads->philosopher[i]);
            routine(&threads->philosopher[i]);
			exit(1);
		}
        // usleep(100);
	}
	i = -1;
	int j;
	while (++i < threads->philo_num)
	{
		if (waitpid(-1, NULL, 0) <= 0)
			break ;
		j = -1;
		while (++j < threads->philo_num)
			kill(threads->philosopher[j].pid, SIGKILL);
	}
}

t_phil	*init_philo(t_threads *threads)
{
	int		i;
	t_phil	*philosopher;

	i = 0;
	philosopher = malloc(sizeof(t_phil) * threads->philo_num);
	while (i < threads->philo_num)
	{
		philosopher[i].id = i + 1;
		philosopher[i].number_of_time_eat = 0;
		philosopher[i].is_eating = 0;
		philosopher[i].thread = threads;
		i++;
	}
	return (philosopher);
}

int	ft_parse(int argc, char **argv, t_threads *threads)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (str_digit(argv[i]) < 0)
			return (1);
		i++;
	}
	if (argc == 5 || argc == 6)
	{
		if (argv[5])
			threads->number_of_time_to_eat = ft_atoi(argv[5]);
		else
			threads->number_of_time_to_eat = 0;
		threads->philo_num = ft_atoi(argv[1]);
		threads->time_to_die = ft_atoi(argv[2]);
		threads->time_to_sleep = ft_atoi(argv[4]);
		threads->time_to_eat = ft_atoi(argv[3]);
		threads->eat_counter = 0;
		sem_unlink("forkssem");
		threads->forks = sem_open("forkssem", O_CREAT, 0644, threads->philo_num);
	}
	else
		return (2);
	threads->philosopher = init_philo(threads);
	return (0);
}

int	main(int argc, char **argv)
{
	t_threads	threads;

	if (ft_parse(argc, argv, &threads))
	{
		write(2, "Not valid args!\n", 15);
		return (1);
	}
	init_threads(&threads);
	return (0);
}