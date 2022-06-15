/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:58:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/15 17:54:11 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine_bonus(void *t)
{
	t_info_philo	*p;

	p = (t_info_philo *)t;
	p->count = 0;
	if (p->id % 2 == 0)
		usleep (10000);
	while (1)
	{
		took_fork_bonus(p);
		ft_print_bonus(p, get_time_bonus(), 2);
		usleep(p->t->time_to_eat * 1000);
		p->last_meal = get_time_bonus();
		p->count++;
		if (p->count == p->t->nmbr_eat)
			p->t->nbr_time_to_eat++;
		put_fork_bonus(p);
		ft_print_bonus(p, get_time(), 3);
		usleep(p->t->time_to_sleep * 1000);
		ft_print_bonus(p, get_time(), 4);
	}
	return (NULL);
}

void	create_bonus(int tab[0], t_philo *t, t_info_philo *p)
{
	int	i;

	i = 0;
	sem_init(&t->print, 0, 1);
	while (i < tab[0])
	{
		p[i].id = i;
		p[i].t = t;
		pthread_create(&p->philo, NULL, &routine_bonus, &p[i]);
		p[i].last_meal = get_time();
		i++;
	}
	ft_check_die_bonus(p);
}

void	ft_philosophers_bonus(char **arg)
{
	t_info_philo	*p;
	int				i;
	int				*tab;
	t_philo			*t;

	tab = malloc(sizeof(int ) * ft_strlen_deux_dim(arg));
	convert_to_integer(tab, arg);
	t = malloc(sizeof(t_philo) * tab[0]);
	init_var_bonus(t, tab);
	p = malloc(sizeof(t_info_philo) * t->number_of_philosophers);
	t->fork = malloc(sizeof(sem_t) * t->number_of_philosophers);
	sem_open(t->fork, O_CREAT, 0664,t->number_of_philosophers);
	sem_open(t->print, O_CREAT, 0664, 1);
	i = 0;
	while (i < t->number_of_philosophers)
        sem_init(&t->fork[i++], 0, 1);
	t->t0 = get_time_bonus();
	create_bonus(&t->number_of_philosophers, t, p);
	i = 0;
	while (i < t->number_of_philosophers)
		sem_destroy(&t->fork[i++]);
}


int	main(int argc, char **argv)
{
	char	**arg;
	pid_t pid;
    pid = fork();

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