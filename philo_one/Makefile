NAME= philo_one
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = *.c
all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
clean:
	@rm -rf $(NAME)
re: clean
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 