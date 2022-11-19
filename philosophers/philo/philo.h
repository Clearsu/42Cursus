/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:10:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/19 17:51:14 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_info
{
	pthread_mutex_t	*pork;
	t_philo			*philo;
	int				n;
	t_time			time;
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	int			right_hand;
	int			left_hand;
	time_t		time_left;
}	t_philo;

typedef struct s_time
{
	time_t	start_time;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	time_to_think;
	time_t	time_to_die;
}	t_time;

int	ft_atoi(char *str);
int	arg_check(int argc, char **argv);
#endif