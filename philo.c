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

void get_arg(int *tab, t_philo *t)
{
	int i;
	
	i = 0;
	while(tab[i])
	{
		t->number_of_philosophers = tab[0];
		t->time_to_die = tab[1];
		t->time_to_eat	= tab[2];
		t->time_to_sleep = tab[3];
		t->nmbr_eat	= tab[4];
	}
}

void	*routine(void *t)
{
	t_info_philo	*p;

	p = (t_info_philo *)t;

printf("%ld ------- %ld ---------%d\n ",get_time(),p->last_meal,p->t->time_to_die);
	if (p->id % 2 == 0)
		usleep (10000);
	while (1)
	{
	
		if(get_time() - p->last_meal >=  p->t->time_to_die)
		{
			pthread_mutex_lock(&p->t->fork[p->id]);
			printf("philo de id : %d took fork 1\n",p->id);
			pthread_mutex_lock(&p->t->fork[(p->id + 1) % 4]);
			printf("philo de id : %d took fork 2\n", p->id);
			printf("philo de id : %d is eating\n", p->id);
			p->last_meal = get_time();
			usleep(60000);
			pthread_mutex_unlock(&p->t->fork[p->id]);
			printf("philo de id : %d put fork\n", p->id);
			pthread_mutex_unlock(&p->t->fork[(p->id + 1) % 4]);
			printf("philo de id : %d put fork\n", p->id);
			usleep(60000);
			printf("philo de id : %d is sleeping\n", p->id);
			usleep(60000);
			printf("philo de id : %d is thinking\n", p->id);
		}
		// else
		// {
		// 	printf("philo is die \n");
		// }
	}
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
		printf("hello\n");
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
	// if(argc <= 6)
	// {
		
		if(check_space(argv) == 0)
			write(1, "Error\n", 6);
		else
			ft_philosophers(arg);
	// }
	return(0);
}