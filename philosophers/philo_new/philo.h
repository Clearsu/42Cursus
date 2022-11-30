/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:10:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/30 21:50:02 by jincpark         ###   ########.fr       */
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
	int				*alive;
	int				n;
	int				left_idx;
	pthread_t		thread;
	pthread_mutex_t	*right_hand;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*mutex_start;
	pthread_mutex_t	*mutex_time;
	pthread_mutex_t	*mutex_alive;
	pthread_mutex_t	*mutex_eat;
	t_time			*time;
	time_t			limit;
	int				eat_reps;
	int				*eat_left;
	int				opt_flag;
}	t_philo;

typedef struct s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_start;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_alive;
	pthread_mutex_t	mutex_eat;
	t_philo			*philo;
	int				n;
	int				alive;
	int				eat_left;
	t_time			time;
}	t_info;

int			arg_check(int argc, char **argv);
t_info		*init_info(char **argv);

void		set_left_hand_by_idx(t_info *info, int i);
void		set_eat_reps(t_info *info, char **argv);
int			set_time_in_microsec(char **argv, t_info *info);

void		philo_think_and_get_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);

int			get_right_fork(t_philo *philo);
int			get_left_fork(t_philo *philo);
void		put_forks_down(t_philo *philo);

void		monitor_state(t_info *info);

int			check_alive(t_philo *philo);
void		check_eat_left(t_philo *philo);
int			check_dead(t_philo *philo);

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
