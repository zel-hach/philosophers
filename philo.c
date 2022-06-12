/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/12 12:01:50 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *function(void *t)
{
   t_info_philo *p;

    p = (t_info_philo *)t; 
    printf("%d\n",p->id);
    pthread_mutex_lock(&p->t->fork[p->id]);
    pthread_mutex_lock(&p->t->fork[(p->id % 5) + 1]);
    // sleep(1);
    // pthread_mutex_unlock(&p->fork[p->id]);
    // pthread_mutex_unlock(&p->fork[(p->id % 5) + 1]);
    pthread_exit(EXIT_SUCCESS);
}

void    cree_thread(char **arg)
{
    t_info_philo    *p;
    int              i;
    int             *tab;
    t_philo            *t;
    
    i = 0;
    tab = malloc(sizeof(int));
    if (is_integer(arg) == 0)
		     write(1,"Error\n",6);
    else
    {  
        while(arg[i])
        {
        tab[i] = ft_atoi(arg[i]);
        i++;
        }
        t = malloc(sizeof(t_philo));
        p = malloc(sizeof(t_info_philo) * tab[0]);
        t->fork = malloc(sizeof(pthread_mutex_t) * tab[0]);
        pthread_mutex_init(p->t->fork,NULL);
        i = 0;
        while (i < tab[0])
        {
            p[i].id = i;
            p[i].t = t;
            pthread_create(&p->philo, NULL, &function, &p[i]);
            i++;
        }
         i = 0;
        while (i < tab[0])
        {
            pthread_join(p->philo, NULL);
            i++;
        }
        printf("Après la création du thread.\n");
    }
}

int main(int argc, char **argv)
{
    char             **arg;
    
    arg = ft_join_args(argv);
    argc = 0;
    if(check_space(argv) == 0)
        write(1,"Error\n",6);
    else
        cree_thread(arg);
    return(0);
}