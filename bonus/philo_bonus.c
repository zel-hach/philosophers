/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:58:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/20 13:54:23 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine_bonus(t_info_philo	*p, t_philo *t)
{
	took_fork_bonus(p, t);
	ft_print_bonus(p, get_time_bonus(), 2, t);
	p->last_meal = get_time_bonus();
	usleep(t->time_to_eat * 1000);
	t->nbr_time_to_eat++;
	put_fork_bonus(t);
	ft_print_bonus(p, get_time_bonus(), 3, t);
	usleep(t->time_to_sleep * 1000);
	ft_print_bonus(p, get_time_bonus(), 4, t);
}

void	start_routine_bonus(t_info_philo *p, t_philo *t)
{
	if (pthread_create(&p->dead, NULL, &ft_check_die_bonus, p))
	{
		write(2, "error in create threads\n", 25);
		exit(1);
	}
	pthread_detach(p->dead);
	while (t->d == 0)
		routine_bonus(p, t);
}

void	create_bonus(t_info_philo *p, int t, t_philo *ph)
{
	int	i;

	i = 0;
	p->count = 0;
	while (i < t)
	{
		p[i].philo = fork();
		if (p[i].philo < 0)
		{
			write(2, "error!\n", 7);
			exit(1);
		}
		else if (p[i].philo == 0)
		{
			p[i].id = i;
			p[i].t = ph;
			p[i].last_meal = get_time_bonus();
			start_routine_bonus(&p[i], ph);
		}
		i++;
	}
	_exit_processing(p, ph);
}

void	ft_philosophers_bonus(char **arg, int argc)
{
	t_info_philo	*p;
	long long int	*tab;
	t_philo			*t;

	tab = malloc(sizeof(long long int ) * ft_strlen_deux_dim_bonus(arg));
	if (convert_to_integer_bonus(tab, arg) == 0)
		printf("error for max_int or min_int\n");
	else
	{
		t = malloc(sizeof(t_philo) * tab[0]);
		init_var_bonus(t, tab, argc);
		p = (t_info_philo *)malloc(sizeof(t_info_philo)
				* t->number_of_philosophers);
		sem_unlink("fork");
		sem_unlink("print");
		t->fork = sem_open("fork", O_CREAT, 0664, t->number_of_philosophers);
		t->print = sem_open("print", O_CREAT, 0664, 1);
		t->t0 = get_time_bonus();
		t->d = 0;
		create_bonus(p, t->number_of_philosophers, t);
		ft_free(p, t);
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	char	**arg;

	arg = ft_join_args_bonus(argv);
	if (argc == 6 || argc == 5)
	{
		if (check_space_bonus(argv) == 0)
			write(1, "Error\n", 6);
		else
		{
			if (is_integer_bonus(arg) == 0)
				write(1, "Error\n", 6);
			else
				ft_philosophers_bonus(arg, argc);
		}
	}
	return (0);
}
