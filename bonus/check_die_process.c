/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:06:56 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/18 20:28:16 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_die_bonus(void *t)
{
	int	i;
	t_info_philo *p;
	p = (t_info_philo *)t;
	i = 0;
	while (1)
	{
		if (get_time_bonus() - p->last_meal > p->t->time_to_die
			|| p->t->nbr_time_to_eat == p->t->number_of_philosophers)
		{
			ft_print_bonus(p, get_time_bonus(), 5,p->t);
			p->t->d = 1;
            exit(1);
		}
		usleep(100);
	}

}

void _exit_processing(t_info_philo *p)
{
    int status;
	int	i;
    
	i = -1;
	while(1)
	{
    	waitpid(-1, &status, 0);
    	if(status != 0 && p->count == p->t->number_of_philosophers)
		{
			while(++i < (p->t->number_of_philosophers - 1))
				kill(p[i].philo,SIGTERM);
			break;
		}
		if(status == 0 && p->t->nmbr_eat == -1)
			p->count++;
	}
	sem_close(p->t->fork);
	sem_close(p->t->print);
	sem_unlink("fork");
	sem_unlink("print");
}