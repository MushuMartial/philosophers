/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:33:11 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/19 14:16:13 by tmartial         ###   ########.fr       */
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
    
    pthread_mutex_t		*lfork;
    pthread_mutex_t		*rfork;
    int alive;
	int n_eat;
}				t_philo;

typedef struct s_data {
	pthread_mutex_t    *fork;
    pthread_mutex_t    lock;
    pthread_t        thread;
    t_philo            *philos;
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int n_philo_eat;
    unsigned long start; //gettime
    
}				t_data;*/
int	init(t_data *data, int argc);

int main(int argc, char **argv)
{
    t_data data;
    
    if (argc > 6 || argc < 5)
        write(1, "Wrong Arguments\n", 16);
    else
    {
        if (parser(argc, argv, &data) == 1)
			return (0);
        init(&data, argc);
    }
    return (0);
}

int	init(t_data *data, int argc)
{
    int i;

    i = 0;
    data->philos = (t_philo *)malloc(data->n_philo * sizeof(t_philo));
	data->forks = (pthread_mutex_t *)malloc(data->n_philo * sizeof(pthread_mutex_t));
    if (!data->philos || !data->forks)
        return (1);
    while (i < data->n_philo)
    {
		data->philos[i].alive = 1;
		if (argc == 6)
			data->philos[i].n_eat = data->n_philo_eat;
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
    }
	return (0);
}