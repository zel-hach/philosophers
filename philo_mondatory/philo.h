/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/14 16:06:19 by zel-hach         ###   ########.fr       */
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
	int				nbr_time_to_eat;
	int				nmbr_eat;
	long			t0;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_philo;

typedef struct v_info_philo
{
	pthread_t	philo;
	int			id;
	int			count;
	long		last_meal;
	t_philo		*t;
}				t_info_philo;
/******************** libft function ********************************/
int				main(int argc, char **argv);
int				ft_isdigit(int c);
long long int	ft_atoi(const char *str);
char			**ft_join_args(char **av);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
int				check_space(char **argv);
size_t			ft_strlen(const char *str);
int				is_integer(char **argv);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen_deux_dim(char **arg);
/******************** print *****************************************/
void			ft_print(t_info_philo *p, long time, int work);
/******************* create philo ***********************************/
void			ft_philosophers(char **arg);
long			get_time(void);
void			ft_check_die(t_info_philo *p);
void			create(int tab[0], t_philo *t, t_info_philo *p);
void			*routine(void *t);
void			took_fork(t_info_philo *p);
void			put_fork(t_info_philo *p);
/******************* utile philo ***********************************/
void			convert_to_integer(int *tab, char **arg);
void			init_var(t_philo *t, int *tab);
#endif