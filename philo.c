/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:49 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/09 13:12:33 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *function(void *t)
{
    t = NULL;
    sleep(1);
    pthread_exit(EXIT_SUCCESS);
}
int main(int argc, char **argv)
{
    t_info_philo    *p;
    int              i;
    
    argc = 0;
    i = 0;
    p = malloc(sizeof(t_info_philo));
    while(i < 5)
    {
    printf("Avant la création du thread.\n");
        pthread_create(&p->philo, NULL, &function, argv);
        i++;
    }
	printf("Après la création du thread.\n");
    return(0);
}