/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:24:00 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/18 17:32:12 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_var_bonus(t_philo *t, int *tab)
{
	t->number_of_philosophers = tab[0];
	t->time_to_die = tab[1];
	t->time_to_eat = tab[2];
	t->time_to_sleep = tab[3];
	t->nmbr_eat = tab[4];
	t->d = 0;
}

void	convert_to_integer_bonus(int *tab, char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		tab[i] = ft_atoi_bonus(arg[i]);
		i++;
	}
}
