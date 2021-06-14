NAME= philo_bonus
CC = gcc
FLAGS = -g
SRCS = main.c eat.c exit.c philo_bonus_tools.c sleep.c think.c ft_write.c
all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
clean:
	@rm -rf $(NAME)
re: clean
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 