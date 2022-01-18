/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:33:15 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/18 17:37:22 by tmartial         ###   ########.fr       */
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
	int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int n_philo_eat;
}				t_philo;

/* parser */
int	verif_long(const char *str, int i);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int parser(int argc, char **argv, t_philo *philo);


#endif