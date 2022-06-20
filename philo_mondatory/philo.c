/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/20 14:17:46 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *t)
{
	t_info_philo	*p;

	p = (t_info_philo *)t;
	p->count = 0;
	if (p->id % 2 == 0)
		usleep (10000);
	while (1)
	{
		took_fork(p);
		ft_print(p, get_time(), 2);
		usleep(p->t->time_to_eat * 1000);
		p->last_meal = get_time();
		p->count++;
		if (p->count == p->t->nmbr_eat)
			p->t->nbr_time_to_eat++;
		put_fork(p);
		ft_print(p, get_time(), 3);
		usleep(p->t->time_to_sleep * 1000);
		ft_print(p, get_time(), 4);
	}
	return (NULL);
}

void	create(int tab[0], t_philo *t, t_info_philo *p)
{
	int	i;

	i = 0;
	pthread_mutex_init(&t->print, NULL);
	while (i < tab[0])
	{
		p[i].id = i;
		p[i].t = t;
		pthread_create(&p->philo, NULL, &routine, &p[i]);
		p[i].last_meal = get_time();
		i++;
	}
	pthread_detach(p->philo);
	ft_check_die(p);
}

void	ft_philosophers(char **arg, int argc)
{
	t_info_philo	*p;
	int				i;
	long long int	*tab;
	t_philo			*t;

	tab = malloc(sizeof(long long int) * ft_strlen_deux_dim(arg));
	if (convert_to_integer(tab, arg) == 0)
		printf("erreur max_int or min_int");
	else
	{
		t = malloc(sizeof(t_philo) * tab[0]);
		init_var(t, tab, argc);
		p = malloc(sizeof(t_info_philo) * t->number_of_philosophers);
		t->fork = malloc(sizeof(pthread_mutex_t) * t->number_of_philosophers);
		i = 0;
		while (i < t->number_of_philosophers)
			pthread_mutex_init(&t->fork[i++], NULL);
		t->t0 = get_time();
		create(&t->number_of_philosophers, t, p);
		i = 0;
		while (i < t->number_of_philosophers)
			pthread_mutex_destroy(&t->fork[i++]);
		ft_free(p, t, tab);
	}
}

int	main(int argc, char **argv)
{
	char	**arg;

	arg = ft_join_args(argv);
	if (argc > 6 || argc < 5)
	{
		printf("le nombre d'arguments incorrect\n");
		return (0);
	}
	else
	{
		if (check_space(argv) == 0)
			write(1, "Error\n", 6);
		else
		{
			if (is_integer(arg) == 0)
				write(1, "Error\n", 6);
			else
				ft_philosophers(arg, argc);
		}
	}
	return (0);
}
