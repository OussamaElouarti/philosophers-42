#include  "philo_bonus.h"

void	think(t_phil *philo)
{
	display("is thinking", philo);
}

int	str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}
