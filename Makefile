PHILO = philo
PHILO_BONUS = philo_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread


define HEADER

 _______  __   __  ___   ___      _______  _______  _______  _______  __   __  _______  ______    _______ 
|       ||  | |  ||   | |   |    |       ||       ||       ||       ||  | |  ||       ||    _ |  |       |
|    _  ||  |_|  ||   | |   |    |   _   ||  _____||   _   ||    _  ||  |_|  ||    ___||   | ||  |  _____|
|   |_| ||       ||   | |   |    |  | |  || |_____ |  | |  ||   |_| ||       ||   |___ |   |_||_ | |_____ 
|    ___||       ||   | |   |___ |  |_|  ||_____  ||  |_|  ||    ___||       ||    ___||    __  ||_____  |
|   |    |   _   ||   | |       ||       | _____| ||       ||   |    |   _   ||   |___ |   |  | | _____| |
|___|    |__| |__||___| |_______||_______||_______||_______||___|    |__| |__||_______||___|  |_||_______|

endef
export HEADER

SRC = philo_mondatory/philo.c  philo_mondatory/utile_libft.c philo_mondatory/split.c philo_mondatory/check_space.c philo_mondatory/check_is_int.c philo_mondatory/ft_create_thread.c philo_mondatory/utile_libft1.c philo_mondatory/utile_philo.c

SRC_BONUS = bonus/utile_libft_bonus.c bonus/split_bonus.c bonus/check_space_bonus.c bonus/check_is_int_bonus.c bonus/utile_libft1_bonus.c bonus/ft_create_thread_bonus.c bonus/utile_philo_bonus.c bonus/philo_bonus.c bonus/check_die_process.c

OBJECTS = $(SRC:.c=.o)

OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = philo_mondatory/philo.h

INCLUDES_BONUS = bonus/philo_bonus.h

all: $(PHILO)

bonus:$(PHILO_BONUS)

$(PHILO): print_header $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(PHILO)

$(PHILO_BONUS): print_header $(OBJECTS_BONUS)
		$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(PHILO_BONUS)

print_header:
	@echo "\033[0;35m $$HEADER \033[0;35m"

%.o : %.c $(INCLUDES) $(INCLUDES_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -rf $(PHILO) $(PHILO_BONUS)

re: fclean all