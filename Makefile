PHILO = philo
PHILO_BONUS = philo_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread


define HEADER

██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗
██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝
██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗
██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║
██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝

endef
export HEADER

SRC = philo_mondatory/philo.c  philo_mondatory/utile_libft.c philo_mondatory/split.c philo_mondatory/check_space.c philo_mondatory/check_is_int.c philo_mondatory/ft_create_thread.c philo_mondatory/utile_libft1.c philo_mondatory/utile_philo.c

SRC_BONUS = bonus/utile_libft_bonus.c bonus/split_bonus.c bonus/check_space_bonus.c bonus/check_is_int_bonus.c bonus/utile_libft1_bonus.c bonus/ft_create_thread_bonus.c bonus/utile_philo_bonus.c bonus/philo_bonus.c bonus/check_die_process.c

OBJECTS = $(SRC:.c=.o)

OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = philo_mondatory/philo.h

INCLUDES_BONUS = bonus/philo_bonus.h

.PHONY : all print_header clean fclean re

all: $(PHILO)

bonus:$(PHILO_BONUS)

$(PHILO): print_header $(OBJECTS)
		@$(CC) $(CFLAGS) $(OBJECTS) -o $(PHILO)
		@echo "\033[1;32m $(PHILO) created 👍 \033[1;32m"

$(PHILO_BONUS): print_header $(OBJECTS_BONUS)
		@$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(PHILO_BONUS)
		@echo "\033[1;32m $(PHILO_BONUS) created 👍 \033[1;32m"

print_header:
	@echo "\033[0;35m $$HEADER \033[0;35m"

%.o : %.c $(INCLUDES) $(INCLUDES_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;33m $@  created ✅ \033[0;35m"

clean: print_header
	@echo "\033[1;33m $(OBJECTS) \033[1;31m :is deleted 👍 \033[1;31m"
	@echo "\033[1;33m $(OBJECTS_BONUS) \033[1;31m :is deleted 👍 \033[1;31m"
	@echo "\033[1;33m $(PHILO_BONUS) \033[1;31m :is deleted 👍 \033[1;31m" 
	@echo "\033[1;33m $(PHILO)       \033[1;31m :is deleted 👍 \033[1;31m"
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	@rm -rf $(PHILO) $(PHILO_BONUS)
re: fclean all