/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/12 15:46:32 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct v_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nmbr_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_philo;

typedef struct v_activites
{
	int fork1;
	int	fork2;
	int	eat;
	int	sleep;
	int	think;
	int	die;
}		t_activites;

typedef struct v_info_philo
{
	pthread_t	philo;
	int			id;
	int			count;
	long		last_meal;
	t_philo		*t;
}				t_info_philo;


/******************** libft function *****************/
int				main(int argc, char **argv);
int				ft_isdigit(int c);
long long int	ft_atoi(const char *str);
char			**ft_join_args(char **av);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
int				check_space(char **argv);
size_t			ft_strlen(const char *str);
int				is_integer(char **argv);

#endif