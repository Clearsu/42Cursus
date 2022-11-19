/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:10:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/19 18:56:45 by jincpark         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t	thread;
	int			right_hand;
	int			left_hand;
	time_t		time_last_ate;
}	t_philo;

typedef struct s_time
{
	time_t	start;
	time_t	to_die;
	time_t	to_eat;
	time_t	to_sleep;
}	t_time;

typedef struct s_info
{
	pthread_mutex_t	*pork;
	t_philo			*philo;
	int				n;
	int				num_of_times_must_eat;
	t_time			time;
}	t_info;


int		arg_check(int argc, char **argv);
t_info	*init_info(char **argv);

time_t	get_time_diff(time_t then, time_t now);
void	print_status(time_t timestamp, int philo, int flag);
void	error_msg(int n, char *str);

int		ft_atoi(char *str);
int		is_all_num(char *str);

#endif
