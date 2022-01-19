/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:33:15 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/19 15:05:00 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

typedef struct s_philo {
    
    pthread_mutex_t lfork;
    pthread_mutex_t	rfork;
    int alive;
    int n_eat;
}				t_philo;

typedef struct s_data {
	pthread_mutex_t    *forks;
    pthread_mutex_t    lock;
    pthread_t        thread;
    t_philo            *philos;
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int n_philo_eat;
    unsigned long start; //gettime
}				t_data;

/* parser */
int	verif_long(const char *str, int i);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int parser(int argc, char **argv, t_data *data);


#endif