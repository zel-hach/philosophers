#include "philo.h"

void took_fork(t_info_philo *p)
{
            pthread_mutex_lock(&p->t->fork[p->id]);
			ft_print(p, get_time() , 0);
			pthread_mutex_lock(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
			ft_print(p, get_time() , 1);
			
}

void put_fork(t_info_philo *p)
{
			pthread_mutex_unlock(&p->t->fork[p->id]);
			pthread_mutex_unlock(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
}

void	*routine(void *t)
{
	t_info_philo	*p;

	p = (t_info_philo *)t;
	if (p->id % 2 == 0)
		usleep (10000);
	while (1)
	{
			took_fork(p);
			ft_print(p, get_time() , 2);
			usleep(p->t->time_to_eat * 1000);
            p->last_meal = get_time();
            p->t->nbr_time_to_eat++;
			put_fork(p);
			ft_print(p, get_time() , 3);
			usleep(p->t->time_to_sleep * 1000);
            ft_print(p, get_time() , 4);
	}
	return(NULL);
}

void	create(int tab[0], t_philo *t, t_info_philo *p)
{
	int	i;

	i = 0;
    pthread_mutex_init(&t->print,NULL);
	while (i < tab[0])
	{
		p[i].id = i;
		p[i].t = t;
		pthread_create(&p->philo, NULL, &routine, &p[i]);
        p[i].last_meal = get_time();
		i++;
	}
	ft_check_die(p);
}

void  ft_check_die(t_info_philo *p)
{
    int i;

    i = 0;
    while(i < p->t->number_of_philosophers)
    {
        if(i == (p->t->number_of_philosophers - 1))
        {
            i = 0;
            continue;
        }
        if(get_time() - p[i].last_meal > p->t->time_to_die || p->t->nbr_time_to_eat >= p->t->nmbr_eat)
        {
            ft_print(p, get_time() , 5);
            break;
        }
        i++;
        usleep(100);
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
        t->t0 = get_time();
		create(&tab[0], t, p);
		i = 0;
		while (i < tab[0])
			pthread_mutex_destroy(&t->fork[i++]);
	}
}