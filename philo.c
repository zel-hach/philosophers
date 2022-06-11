/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/09 18:06:33 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *function(void *t)
{
   t_info_philo *p;

    p = (t_info_philo *)t; 
    pthread_mutex_lock(&p->fork[*p->id]);
    pthread_mutex_lock(&p->fork[(*p->id % 5) + 1]);
    // sleep(1);
    pthread_exit(EXIT_SUCCESS);
}

void    cree_thread(char **arg)
{
    t_info_philo    *p;
    int              i;
    int             *tab;
    int               j;
    
    i = 0;
    j=0;
    tab = malloc(sizeof(int) * 6);
    if (is_integer(arg) == 0)
		     write(1,"Error\n",6);
    else
    {  
        while(arg[i])
         {
            tab[i] = ft_atoi(arg[i]);
            i++;
         }
        p = malloc(sizeof(t_info_philo));
        p->fork = malloc(sizeof(pthread_mutex_t) * 4);
        p->philo = malloc(sizeof(pthread_t) * 4);
        pthread_mutex_init(p->fork,NULL);
        i = 0;
        while (i < tab[0])
        {
            p->id = malloc(sizeof(int));
            p->id[j] = i;
            pthread_create(&p->philo[i], NULL, &function, &p);
            printf("hello : %d\n",p->id[j]);
            i++;
            j++;
        }
         i = 0;
        while (i < tab[0])
        {
            pthread_join(p->philo[i], NULL);
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