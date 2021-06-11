NAME= philo
CC = gcc
FLAGS = -pthread -Wall -Werror -Wextra -g
SRCS = main.c eat.c exit.c philo_one_tools.c sleep.c think.c
all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
clean:
	@rm -rf $(NAME)
re: clean
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 