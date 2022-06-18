/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:58:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/18 20:41:23 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine_bonus(t_info_philo	*p, t_philo *t)
{
	p->count = 0;
	printf("hello\n");
	took_fork_bonus(p,t);
	ft_print_bonus(p, get_time_bonus(), 2, t);
	usleep(t->time_to_eat * 1000);
	p->last_meal = get_time_bonus();
	p->count++;
	if (p->count == t->nmbr_eat)
		t->nbr_time_to_eat++;
	put_fork_bonus(t);
	ft_print_bonus(p, get_time_bonus(), 3, t);
	usleep(t->time_to_sleep * 1000);
	ft_print_bonus(p, get_time_bonus(), 4, t);
}
void start_routine_bonus(t_info_philo *p, t_philo *t)
{
	pthread_t dead;
	
	if (pthread_create(&dead, NULL, &ft_check_die_bonus, p))
	{
		printf("error");
		exit(0);
	}
	while(1)
		routine_bonus(p, t);
}

void	create_bonus(t_info_philo *p, int t , t_philo *ph)
{
	int			i;
	
	i = 0;
	p->count = 0;
	while (i < t)
	{
		p[i].id = i;
		p[i].philo = fork();
		p[i].t = ph;
		if (p[i].philo < 0)
		{
			write(2, "error!\n", 7);
			exit(1);
		}
		else if (p[i].philo == 0)
			start_routine_bonus(&p[i], ph);
		usleep(100);
		i++;
	}
	_exit_processing(p);
}

void	ft_philosophers_bonus(char **arg)
{
	t_info_philo	*p;
	int				*tab;
	t_philo			*t;
	
	tab = malloc(sizeof(int ) * ft_strlen_deux_dim_bonus(arg));
	convert_to_integer_bonus(tab, arg);
	t = malloc(sizeof(t_philo) * tab[0]);
	init_var_bonus(t, tab);
	p = (t_info_philo *)malloc(sizeof(t_info_philo) * t->number_of_philosophers);
	sem_unlink("fork");
	sem_unlink("print");
	t->fork = sem_open("fork", O_CREAT, 0664,t->number_of_philosophers);
	t->print = sem_open("print", O_CREAT, 0664, 1);
	t->t0 = get_time_bonus();
	create_bonus(p, t->number_of_philosophers, t);
}


int	main(int argc, char **argv)
{
	char	**arg;

	arg = ft_join_args_bonus(argv);
	argc = 0;
	if (argc <= 6)
	{
		if (check_space_bonus(argv) == 0)
			write(1, "Error\n", 6);
		else
		{
			if (is_integer_bonus(arg) == 0)
				write(1, "Error\n", 6);
			else
				ft_philosophers_bonus(arg);
		}
	}
	return (0);
}