/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:10:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/22 20:55:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

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
	pthread_t		thread;
	pthread_mutex_t	*right_hand;
	pthread_mutex_t	*left_hand;
	t_time			*time;
	time_t			curr;
	time_t			limit;
	char			*table;
	int				n;
	int				eat_reps;
}	t_philo;

typedef struct s_info
{
	pthread_mutex_t	*pork;
	t_philo			*philo;
	int				n;
}	t_info;

int			arg_check(int argc, char **argv);
t_info		*init_info(char **argv);

int			philo_eat(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);
void		detect_dead_and_quit(t_info *info);

time_t		get_timestamp(t_philo *philo);
time_t		get_time_diff(time_t then, time_t now);
time_t		get_time_in_mili(void);
void		error_msg(int n, char *str);

int			ft_atoi(char *str);
long long	ft_atol(char *str);
int			is_all_num(char *str);

#endif
