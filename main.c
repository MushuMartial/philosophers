/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:33:11 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/18 17:37:41 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock*/

/* number_of_philosophers ,time_to_die ,time_to_eat,
time_to_sleep ,[number_of_times_each_philosopher_must_eat]*/

/* typedef struct s_philo {
	int num_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int num_philo_eat;
}				t_philo;*/


int main(int argc, char **argv)
{
    t_philo philo;
    
    if (argc > 6 || argc < 5)
        write(1, "Wrong Arguments\n", 16);
    else
    {
        if (parser(argc, argv, &philo) == 1)
			return (0);
    }
    return (0);
}
