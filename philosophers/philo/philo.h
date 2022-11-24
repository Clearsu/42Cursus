/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:10:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/24 20:45:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_time
{
	time_t	start;
	time_t	to_die;
	time_t	to_eat;
	time_t	to_sleep;
}	t_time;

typedef struct s_philo
{
	int				id;
	int				alive;
	int				n;
	int				left_idx;
	pthread_t		thread;
	pthread_mutex_t	*right_hand;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*print;
	pthread_mutex_t	*before_start;
	t_time			*time;
	time_t			curr;
	time_t			limit;
	char			*table;
	int				eat_reps;
	int				opt_flag;
}	t_philo;

typedef struct s_info
{
	pthread_mutex_t	*pork;
	pthread_mutex_t	print;
	pthread_mutex_t	before_start;
	t_philo			*philo;
	int				n;
	char			*table;
	t_time			time;
}	t_info;

int			arg_check(int argc, char **argv);
t_info		*init_info(char **argv);

void		set_eat_reps(t_info *info, char **argv);
int			set_time_in_microsec(char **argv, t_info *info);
int			set_table(t_info *info);

int			philo_eat(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);

int			is_porks_available(t_philo *philo);
int			get_right_pork(t_philo *philo);
int			get_left_pork(t_philo *philo);
void		put_porks_down(t_philo *philo);

void		detect_dead_and_quit(t_info *info);

time_t		get_timestamp(t_philo *philo);
time_t		get_time_in_mili(void);
void		error_msg(int n, char *str);
void		print_in_mutex(t_philo *philo, char *str);
void		lengthen_life(t_philo *philo, time_t now);

int			get_left_idx(t_philo *philo);
int			ft_atoi(char *str);
long long	ft_atol(char *str);
int			is_all_num(char *str);

#endif
