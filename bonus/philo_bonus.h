/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:16:51 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/15 17:36:39 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/fcntl.h>

typedef struct v_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_time_to_eat;
	int				nmbr_eat;
	long			t0;
	sem_t			*fork;
	sem_t			print;
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
int				ft_isdigit_bonus(int c);
long long int	ft_atoi_bonus(const char *str);
char			**ft_join_args_bonus(char **av);
char			**ft_split_bonus(char const *s, char c);
char			*ft_strtrim_bonus(char const *s1, char const *set);
int				check_space_bonus(char **argv);
size_t			ft_strlen(const char *str);
int				is_integer_bonus(char **argv);
char			*ft_strjoin_bonus(char const *s1, char const *s2);
int				ft_strlen_deux_dim_bonus(char **arg);
/******************** print *****************************************/
void			ft_print_bonus(t_info_philo *p, long time, int work);
/******************* create philo ***********************************/
void			ft_philosophers_bonus(char **arg);
long			get_time_bonus(void);
void			ft_check_die_bonus(t_info_philo *p);
void			create_bonus(int tab[0], t_philo *t, t_info_philo *p);
void			*routine_bonus(void *t);
void			took_fork_bonus(t_info_philo *p);
void			put_fork_bonus(t_info_philo *p);
/******************* utile philo ***********************************/
void			convert_to_integer_bonus(int *tab, char **arg);
void			init_var_bonus(t_philo *t, int *tab);

#endif