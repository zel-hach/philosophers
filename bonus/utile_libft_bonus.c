/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_libft_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:18:57 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/15 17:32:42 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_strlen_deux_dim_bonus(char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		while (arg[j])
			j++;
		i++;
	}
	return (j);
}

static int	ft_cherche(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim_bonus(char const *s1, char const *set)
{
	int		a;
	int		b;
	int		i;
	char	*ptr;

	a = 0;
	if (!s1)
		return (NULL);
	while (s1[a] != '\0' && ft_cherche(s1[a], set))
		a++;
	b = ft_strlen(s1);
	while (b > a && ft_cherche(s1[b - 1], set))
		b--;
	ptr = malloc(sizeof(*s1) * (b - a + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (a < b)
	{
		ptr[i++] = s1[a++];
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strjoin_bonus(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
