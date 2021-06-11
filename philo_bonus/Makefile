NAME= philo_bonus
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
SRCS = *.c
all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
clean:
	@rm -rf $(NAME)
re: clean
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 