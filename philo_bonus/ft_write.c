#include "philo_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_print_number(int nb, int fd)
{
	int	num;
	int	length;

	length = 1;
	num = nb / 10;
	while (num > 0)
	{
		length *= 10;
		num /= 10;
	}
	num = nb;
	while (length)
	{
		ft_putchar_fd((char)((nb / length)) + '0', fd);
		nb %= length;
		length /= 10;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	if (nb >= 0)
	{
		ft_print_number(nb, fd);
	}
	else if (nb < 0 && nb != -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		ft_print_number(nb, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}
