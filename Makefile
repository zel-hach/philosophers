PHILO = philo
PHILO_BONUS = philo_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC = philo_mondatory/philo.c  philo_mondatory/utile_libft.c philo_mondatory/split.c philo_mondatory/check_space.c philo_mondatory/check_is_int.c philo_mondatory/ft_create_thread.c philo_mondatory/utile_libft1.c philo_mondatory/utile_philo.c

SRC_BONUS = philo_bonus/utile_libft_bonus.c philo_bonus/split_bonus.c philo_bonus/check_space_bonus.c philo_bonus/check_is_int_bonus.c philo_bonus/utile_libft1_bonus.c

OBJECTS = $(SRC:.c=.o)

OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = philo_mondatory/philo.h

INCLUDES_BONUS = philo_bonus/philo_bonus.h

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