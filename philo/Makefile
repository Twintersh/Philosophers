CC = gcc
NAME = philo
SRC = main.c utils.c setup.c threads.c
OBJ=$(SRC:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g -pthread
LFLAGS = -lpthread

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(LFLAGS) $(INCL) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

re : fclean all

clean :
	@rm -rf $(OBJ)
	@echo Done

fclean : clean
	@rm -rf $(NAME)

f : fclean

.PHONY : clean re fclean all
