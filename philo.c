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
	if(work == fork1)
	printf("time took fork1 is : %ld --- philo de id : %d \n",get_time(), p->id);


}
void took_fork(t_info_philo *p)
{
			ft_print(p, get_time() , fork1);
			pthread_mutex_lock(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
			printf("time took fork1 is : %ld --- philo de id : %d \n", get_time(), p->id);
}

void put_fork(t_info_philo *p)
{
			pthread_mutex_unlock(&p->t->fork[p->id]);
			printf("this time:%ld ---- philo de id : %d put fork1\n", get_time(), p->id);
			pthread_mutex_unlock(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
			printf("this time :%ld ---- philo de id : %d put fork2\n",get_time(), p->id);
}

void	*routine(void *t)
{
	t_info_philo	*p;

	p = (t_info_philo *)t;

	p->last_meal = get_time();
	pthread_mutex_init(&p->t->print,NULL);
	if (p->id % 2 == 0)
		usleep (10000);
	while (1)
	{
	
		if(get_time() - p->last_meal <=  p->t->time_to_die)
		{
			pthread_mutex_lock(&p->t->fork[p->id]);
			took_fork(p);
			printf("this time :%ld ---- philo de id : %d is eating\n",get_time(), p->id);
			usleep(p->t->time_to_eat * 1000);
			put_fork(p);
			printf("this time : %ld ---- philo de id : %d is sleeping\n", get_time(), p->id);
			usleep(p->t->time_to_sleep * 1000);
			printf("this time : %ld ---- philo de id : %d is thinking\n", get_time() , p->id);
		}
		else
		{
			printf("philo is die \n");
			break;
		}
	}
	return(NULL);
}

void	create(int tab[0], t_philo *t, t_info_philo *p)
{
	int	i;

	i = 0;
	p->last_meal = get_time();
	while (i < tab[0])
	{
		p[i].id = i;
		p[i].t = t;
		pthread_create(&p->philo, NULL, &routine, &p[i]);
		i++;
	}
	i = 0;
	while (i < tab[0])
	{
		pthread_join(p->philo, NULL);
		i++;
	}
}

void	ft_philosophers(char **arg)
{
	t_info_philo	*p;
	int			i;
	int			*tab;
	t_philo		*t;
	
	i = 0;
	tab = malloc(sizeof(int));
	if (is_integer(arg) == 0)
			  write(1, "Error\n", 6);
	else
	{
		while (arg[i])
		{
			tab[i] = ft_atoi(arg[i]);
			i++;
		}
		t = malloc(sizeof(t_philo) * tab[0]);
		t->number_of_philosophers = tab[0];
		t->time_to_die = tab[1];
		t->time_to_eat	= tab[2];
		t->time_to_sleep = tab[3];
		t->nmbr_eat	= tab[4];
		p = malloc(sizeof(t_info_philo) * tab[0]);
		t->fork = malloc(sizeof(pthread_mutex_t) * t->number_of_philosophers);
		i = 0;
		while (i < tab[0])
			pthread_mutex_init(&t->fork[i++], NULL);
		create(&tab[0], t, p);
		i = 0;
		while (i < tab[0])
			pthread_mutex_destroy(&t->fork[i++]);
	}
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