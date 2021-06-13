#include "philo_bonus.h"

int	ft_check(unsigned long pt, int s)
{
	if (pt > 9223372036854775807 && s == -1)
		return (0);
	else if (pt > 9223372036854775807)
		return (-1);
	return (pt * s);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	j;
	unsigned long long int	t_p;
	int						tt;

	tt = 1;
	j = 0;
	t_p = 0;
	while (*str >= 8 && *str <= 32)
	{
		if (*str == 27)
			return (0);
		str++;
	}
	if (*str == '-')
	{
		tt = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		t_p = t_p * 10 + (unsigned long long int)(*(str + j++) - '0');
	return (ft_check(t_p, tt));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

unsigned long long	get_time(void)
{
	unsigned long long	mili_sec;
	struct timeval		current_time;

	gettimeofday(&current_time, NULL);
	mili_sec = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (mili_sec);
}

void	display(char *msg, t_phil *philo)
{
	unsigned long long	time;

	sem_wait(philo->thread->write);
	time = get_time() - philo->thread->time;
	ft_putnbr_fd(time, 1);
	ft_putstr_fd(" philosopher ", 1);
	ft_putnbr_fd(philo->id, 1);
	write (1, " ", 1);
	ft_putstr_fd(msg, 1);
	write (1, "\n", 1);
	if (strcmp(msg, "died"))
		sem_post(philo->thread->write);
}
