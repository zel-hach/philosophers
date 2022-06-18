PHILO = philo
PHILO_BONUS = philo_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC = philo_mondatory/philo.c  philo_mondatory/utile_libft.c philo_mondatory/split.c philo_mondatory/check_space.c philo_mondatory/check_is_int.c philo_mondatory/ft_create_thread.c philo_mondatory/utile_libft1.c philo_mondatory/utile_philo.c

SRC_BONUS = bonus/utile_libft_bonus.c bonus/split_bonus.c bonus/check_space_bonus.c bonus/check_is_int_bonus.c bonus/utile_libft1_bonus.c bonus/ft_create_thread_bonus.c bonus/utile_philo_bonus.c bonus/philo_bonus.c bonus/check_die_process.c

OBJECTS = $(SRC:.c=.o)

OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = philo_mondatory/philo.h

INCLUDES_BONUS = bonus/philo_bonus.h

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