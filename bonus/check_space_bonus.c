/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:18:29 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/19 17:31:58 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_space_strlen(char **tab)
{
	char	*ptr;

	ptr = ft_strtrim_bonus(*tab, " ");
	if (ft_strlen(ptr) == 0)
		return (free(ptr), 0);
	return (free(ptr), 1);
}

int	check_space_bonus(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_space_strlen(&argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
