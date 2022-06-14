/* ************************************************************************** */
/*	                                                                         */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:30:42 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/14 11:48:36 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	took_fork(t_info_philo *p)
{
	pthread_mutex_lock(&p->t->fork[p->id]);
	ft_print(p, get_time(), 0);
	pthread_mutex_lock(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
	ft_print(p, get_time(), 1);
}		

void	put_fork(t_info_philo *p)
{
	pthread_mutex_unlock(&p->t->fork[p->id]);
	pthread_mutex_unlock(&p->t->fork[(p->id + 1)
		% p->t->number_of_philosophers]);
}

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("error");
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_print(t_info_philo *p, long time, int work)
{
	pthread_mutex_lock(&p->t->print);
	if (work == 0)
		printf("%ld --- philo id : %d take fork \n", time - p->t->t0, p->id);
	else if (work == 1)
		printf("%ld --- philo id : %d take fork\n", time - p->t->t0, p->id);
	else if (work == 2)
		printf("%ld --- philo id : %d is eating\n", time - p->t->t0, p->id);
	else if (work == 3)
		printf("%ld --- philo id : %d is sleeping\n", time - p->t->t0, p->id);
	else if (work == 4)
		printf("%ld --- philo id : %d is thinking\n", time - p->t->t0, p->id);
	else if (work == 5)
		printf("%ld --- philo id : %d is die \n", time - p->t->t0, p->id);
	pthread_mutex_unlock(&p->t->print);
}

void	ft_check_die(t_info_philo *p)
{
	int	i;

	i = 0;
	while (1)
	{
		if (get_time() - p->last_meal > p->t->time_to_die
			|| p->t->nbr_time_to_eat >= p->t->nmbr_eat)
		{
			ft_print(p, get_time(), 5);
			break ;
		}
		usleep(100);
	}
}
