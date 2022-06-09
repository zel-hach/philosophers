/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_big_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:43:53 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/09 14:15:25 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_big_integer(t_info *info)
{
	t_list	*tmp1;

	tmp1 = info->head;
	while (tmp1)
	{
		if (tmp1->data > INT_MAX || tmp1->data < INT_MIN)
			return (0);
		tmp1 = tmp1->next;
	}
	return (1);
}
