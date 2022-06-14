/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:44:30 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/09 14:52:45 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_space_strlen(char **tab)
{
	char	*ptr;

	ptr = ft_strtrim(*tab, " ");
	if (ft_strlen(ptr) == 0)
		return (free(ptr), 0);
	return (free(ptr), 1);
}

int	check_space(char **argv)
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
