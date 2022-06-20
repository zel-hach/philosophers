/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:33:46 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/20 11:23:00 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_var(t_philo *t, long long int *tab, int argc)
{
	t->number_of_philosophers = tab[0];
	t->time_to_die = tab[1];
	t->time_to_eat = tab[2];
	t->time_to_sleep = tab[3];
	if (argc == 6)
		t->nmbr_eat = tab[4];
	else
		t->nmbr_eat = -1;
}

int	convert_to_integer(long long int *tab, char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		tab[i] = ft_atoi(arg[i]);
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
