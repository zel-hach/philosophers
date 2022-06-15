/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_libft1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:11:05 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/15 17:34:53 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit_bonus(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

long long int	ft_atoi_bonus(const char *str)
{
	int				i;
	long long int	res;
	int				signe;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (res * signe);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_join_args_bonus(char **av)
{
	char	*res;
	char	**str;
	char	*ptr;
	char	*s;
	int		i;

	i = 0;
	res = ft_strdup("");
	while (av[++i])
	{
		s = ft_strjoin_bonus(av[i], " ");
		ptr = res;
		res = ft_strjoin_bonus(res, s);
		free(ptr);
		free(s);
	}
	str = ft_split_bonus(res, ' ');
	free(res);
	return (str);
}
