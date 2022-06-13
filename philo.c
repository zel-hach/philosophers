/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/12 18:46:28 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void ft_print(t_info_philo *p, long time , int work)
{
	pthread_mutex_lock(&p->t->print);
	if(work == p->act.fork1)
		printf("time took fork1 is : %ld --- philo de id : %d \n",time, p->id);
	else if(work == p->act.fork2)
		printf("time took fork2 is : %ld --- philo de id : %d \n", time, p->id);
	else if(work == p->act.eat)
		printf("this time :%ld ---- philo de id : %d is eating\n",time, p->id);
	else if(work == p->act.sleep)
		printf("this time : %ld ---- philo de id : %d is sleeping\n", time, p->id);
	else if (work == p->act.think)
		printf("this time : %ld ---- philo de id : %d is thinking\n", time , p->id);
	else if(work == p->act.die)
		printf("this time : %ld ---- philo de id : %d is die \n", time , p->id);
	pthread_mutex_unlock(&p->t->print);
}

int	main(int argc, char **argv)
{
	char	**arg;
	
	arg = ft_join_args(argv);
	argc = 0;
	if(argc <= 6)
	{
		
		if(check_space(argv) == 0)
			write(1, "Error\n", 6);
		else
			ft_philosophers(arg);
	}
	return(0);
}