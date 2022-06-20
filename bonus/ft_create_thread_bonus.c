/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:09:40 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/19 17:31:37 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	took_fork_bonus(t_info_philo *p, t_philo *t)
{
	sem_wait(t->fork);
	ft_print_bonus(p, get_time_bonus(), 0, t);
	sem_wait(t->fork);
	ft_print_bonus(p, get_time_bonus(), 1, t);
}

void	put_fork_bonus(t_philo *t)
{
	sem_post(t->fork);
	sem_post(t->fork);
}

long	get_time_bonus(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("error");
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_print_bonus(t_info_philo *p, long time, int work, t_philo *t)
{
	sem_wait(t->print);
	if (work == 0)
		printf("%ld --- philo id : %d take fork \n", time - t->t0, p->id);
	else if (work == 1)
		printf("%ld --- philo id : %d take fork\n", time - t->t0, p->id);
	else if (work == 2)
		printf("%ld --- philo id : %d is eating\n", time - t->t0, p->id);
	else if (work == 3)
		printf("%ld --- philo id : %d is sleeping\n", time - t->t0, p->id);
	else if (work == 4)
		printf("%ld --- philo id : %d is thinking\n", time - t->t0, p->id);
	sem_post(t->print);
}
