/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:09:40 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/15 17:38:26 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	took_fork_bonus(t_info_philo *p)
{
	sem_wait(&p->t->fork[p->id]);
	ft_print_bonus(p, get_time_bonus(), 0);
	sem_wait(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
	ft_print_bonus(p, get_time_bonus(), 1);
}		

void	put_fork_bonus(t_info_philo *p)
{
	sem_post(&p->t->fork[p->id]);
	sem_post(&p->t->fork[(p->id + 1)
		% p->t->number_of_philosophers]);
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

void	ft_print_bonus(t_info_philo *p, long time, int work)
{
	sem_wait(&p->t->print);
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
	sem_post(&p->t->print);
}

void	ft_check_die_bonus(t_info_philo *p)
{
	int	i;

	i = 0;
	while (1)
	{
		if (get_time_bonus() - p->last_meal > p->t->time_to_die
			|| p->t->nbr_time_to_eat == p->t->number_of_philosophers)
		{
			ft_print_bonus(p, get_time_bonus(), 5);
			break ;
		}
		usleep(100);
	}
}
