/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:18:12 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/14 18:18:18 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "philo_bonus.h"

static int	is_int(char *arg)
{
	int	i;

	i = -1;
	if ((arg[0] == '-' || arg[0] == '+') && arg[1] != '\0')
		i++;
	while (arg[++i])
		if (ft_isdigit(arg[i]) == 0)
			return (0);
	return (1);
}

int	is_integer(char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (argv[i])
	{
		i++;
		size++;
	}
	i = -1;
	while (++i < size)
		if (is_int(argv[i]) == 0 || argv[i][0] == '\0')
			return (0);
	return (1);
}
