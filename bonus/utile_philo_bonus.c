/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:24:00 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/20 13:01:54 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_var_bonus(t_philo *t, long long int *tab, int argc)
{
	t->d = 0;
	t->number_of_philosophers = tab[0];
	t->time_to_die = tab[1];
	t->time_to_eat = tab[2];
	t->time_to_sleep = tab[3];
	if (argc == 6)
		t->nmbr_eat = tab[4];
	else
		t->nmbr_eat = -1;
}

int	convert_to_integer_bonus(long long int *tab, char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		tab[i] = ft_atoi_bonus(arg[i]);
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
