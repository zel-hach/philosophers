/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/09 12:57:36 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct v_philo
{
    int             number_of_philosophers;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             nmbr_eat;
}                   t_philo;

typedef struct v_info_philo
{
    pthread_mutex_t fork;
    pthread_t philo;
    int             id;
    long            last_meal;
}                   t_info_philo;