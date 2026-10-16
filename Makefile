NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes

RM = rm -rf

SRC =	src/main.c \
		src/utils.c \
		src/time.c \
		src/initialize.c \
		src/simulation.c \
		src/routine.c \
		src/monitor_routine.c \
		src/destroy_all.c \
		src/status.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
