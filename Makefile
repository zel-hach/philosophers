PHILO = philo
PHILO_BONUS = philo_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC = philo.c  utile_libft.c split.c check_space.c check_is_int.c ft_create_thread.c

SRC_BONUS = 

OBJECTS = $(SRC:.c=.o)

OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = philo.h

INCLUDES_BONUS = philo_bonus.h

all: $(PHILO)

bonus:$(PHILO_BONUS)

$(PHILO): $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(PHILO)

$(PHILO_BONUS):$(OBJECTS_BONUS)
		$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(PHILO_BONUS)

%.o : %.c $(INCLUDES) $(INCLUDES_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -rf $(PHILO) $(PHILO_BONUS)

re: fclean all