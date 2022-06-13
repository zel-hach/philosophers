#include "philo.h"

void took_fork(t_info_philo *p)
{
            pthread_mutex_lock(&p->t->fork[p->id]);
			ft_print(p, get_time() , p->act.fork1);
			pthread_mutex_lock(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
			ft_print(p, get_time() , p->act.fork2);
			
}

void put_fork(t_info_philo *p)
{
			pthread_mutex_unlock(&p->t->fork[p->id]);
			pthread_mutex_unlock(&p->t->fork[(p->id + 1) % p->t->number_of_philosophers]);
            printf("hello1\n");
}

void	*routine(void *t)
{
	t_info_philo	*p;

	p = (t_info_philo *)t;

	p->last_meal = get_time();
	if (p->id % 2 == 0)
		usleep (10000);
	while (1)
	{
			took_fork(p);
			ft_print(p, get_time() , p->act.eat);
			usleep(p->t->time_to_eat * 1000);
			put_fork(p);
			ft_print(p, get_time() , p->act.sleep);
			usleep(p->t->time_to_sleep * 1000);
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

void  ft_check_die(t_info_philo *p)
{
    int i;

    i = 0;
    p->last_meal = get_time();
    while(p[i].philo)
    {
        printf("%d\n", p->t->number_of_philosophers);
        if(i == p->t->number_of_philosophers)
        {
            i = 0;
            continue;
        }
        // else if(get_time() - p->last_meal <= p->t->time_to_die)
        // {
        //     ft_print(p, get_time() , p->act.die);
        //     break;
        // }
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
        pthread_mutex_init(&p->t->print,NULL);
        ft_check_die(p);
		i = 0;
		while (i < tab[0])
			pthread_mutex_destroy(&t->fork[i++]);
	}
}