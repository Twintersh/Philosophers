CC = gcc
NAME = philo
SRC = main.c utils.c setup.c threads.c actions.c running_settings.c checker.c
OBJ=$(SRC:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g3 -pthread
LFLAGS = -lpthread

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(LFLAGS) $(INCL) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

re : fclean all

clean :
	rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

f : fclean

.PHONY : clean re fclean all
