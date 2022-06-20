/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:06:56 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/19 17:36:08 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_die_bonus(void *t)
{
	int				i;
	t_info_philo	*p;

	p = (t_info_philo *)t;
	i = 0;
	while (1)
	{
		if (get_time_bonus() - p->last_meal > p->t->time_to_die)
		{
			sem_wait(p->t->print);
			printf("%ld --- philo id : %d is die \n",
				get_time_bonus() - p->t->t0, p->id);
			p->t->d = 1;
			exit (1);
		}
		if (p->t->nmbr_eat == p->t->nbr_time_to_eat)
		{
			p->t->d = 1;
			exit (0);
		}
		usleep (100);
	}
	return (0);
}

void	_exit_processing(t_info_philo *p, t_philo *t)
{
	int	status;
	int	i;

	while (1)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) != 0 || p->count == t->number_of_philosophers)
		{
			i = -1;
			while (++i < t->number_of_philosophers)
				kill(p[i].philo, SIGTERM);
			break ;
		}
		else if (WEXITSTATUS(status) == 0)
			p->count++;
	}
	sem_close(t->fork);
	sem_close(t->print);
	sem_unlink("fork");
	sem_unlink("print");
}
