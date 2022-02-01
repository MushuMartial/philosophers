/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:05 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/30 12:59:05 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		pth_id;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	int				id;
	int				meals;
	unsigned long	last_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	int				n_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_eat;
	int				stop;
	unsigned long	start;
}	t_data;

/* main */
int				start_threads(t_data *data);
void			*routine(void *arg);
void			check_threads(t_data *data);
void			check_eat(t_data *data);

/* parser */
int				parser(int argc, char **argv, t_data *data);
int				forks_init(t_data *data);
int				philos_init(t_data *data);
int				one_philo(t_data *data);

/* libft */
int				verif_long(const char *str, int i);
int				ft_atoi(const char *str);

/* utils */
unsigned long	current_time(void);
void			ft_usleep(int msec);
void			message(t_philo *philo, char *str);
int				p_error(int msg);
int				free_all(t_data *data);

#endif
