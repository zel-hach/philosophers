/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:16:51 by zel-hach          #+#    #+#             */
/*   Updated: 2022/06/20 14:07:59 by zel-hach         ###   ########.fr       */
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
# include <sys/types.h>
# include <signal.h>
# include <limits.h>

typedef struct v_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_time_to_eat;
	int				nmbr_eat;
	long			t0;
	int				d;
	sem_t			*fork;
	sem_t			*print;
}					t_philo;

typedef struct v_info_philo
{
	pid_t		philo;
	int			id;
	int			count;
	long		last_meal;
	pthread_t	dead;
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
void			ft_print_bonus(t_info_philo *p, long time,
					int work, t_philo *t);
/******************* create philo ***********************************/
void			ft_philosophers_bonus(char **arg, int argc);
long			get_time_bonus(void);
void			*ft_check_die_bonus(void *t);
void			create_bonus(t_info_philo *p, int t, t_philo *ph);
void			routine_bonus(t_info_philo	*p, t_philo *t);
void			took_fork_bonus(t_info_philo *p, t_philo *t);
void			put_fork_bonus( t_philo *t);
void			_exit_processing(t_info_philo *p, t_philo *t);
/******************* utile philo ***********************************/
int				convert_to_integer_bonus(long long int *tab, char **arg);
void			init_var_bonus(t_philo *t, long long int *tab, int argc);
void			ft_free(t_info_philo *p, t_philo *t);

#endif