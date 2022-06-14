/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:33:46 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/14 16:08:34 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_var(t_philo *t, int *tab)
{
	t->number_of_philosophers = tab[0];
	t->time_to_die = tab[1];
	t->time_to_eat = tab[2];
	t->time_to_sleep = tab[3];
	t->nmbr_eat = tab[4];
}

void	convert_to_integer(int *tab, char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		tab[i] = ft_atoi(arg[i]);
		i++;
	}
}
