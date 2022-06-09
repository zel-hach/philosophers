/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/09 17:03:07 by zel-hach         ###   ########.fr       */
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
    pthread_t       philo[5]; 
    int             id;
    long            last_meal;
}                   t_info_philo;

/******************** libft function *****************/
int             main(int argc, char **argv);
int             ft_isdigit(int c);
long long int	ft_atoi(const char *str);
char	        **ft_join_args(char **av);
char	        **ft_split(char const *s, char c);
char	        *ft_strtrim(char const *s1, char const *set);
int	            check_space(char **argv);
size_t	        ft_strlen(const char *str);
int	            is_integer(char **argv);