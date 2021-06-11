#include "philo_one.h"

void	*routine(void *philosopher)
{
	t_phil	*philo;

	philo = (t_phil *)philosopher;
	philo->last_meal = get_time();
	while (1)
	{
		think(philo);
		eat(philo);
		ft_sleep(philo);
		usleep(100);
	}
	return (NULL);
}

void	init_threads(t_threads *threads)
{
	pthread_t	t_id;
	int			i;

	i = 0;
	threads->time = get_time();
	pthread_mutex_init(&threads->write, NULL);
	while (i < threads->philo_num)
	{
		pthread_create(&t_id, NULL, &routine, &threads->philosopher[i++]);
		usleep(100);
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
		philosopher[i].rfork = (i + 1) % threads->philo_num;
		philosopher[i].lfork = i;
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
	init_mutex(&threads);
	init_threads(&threads);
	supervisor(&threads);
	return (0);
}
