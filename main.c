/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:33:11 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/25 12:15:50 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* eat sleep think*/

/* memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock*/

/* number_of_philosophers ,time_to_die ,time_to_eat,
time_to_sleep ,[number_of_times_each_philosopher_must_eat]*/

/*typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	int				meals;
	unsigned long	last_meal;
	struct s_data	*env;
}	t_philo;

typedef struct s_data
{
	int				nbr;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				cycles;
	int				full;
	int				stop;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	eat;
	unsigned long	start;
}	t_data;*/


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
		forks_init(&data);
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
		data->philos[i].id = i + 1;
		if (argc == 6)
			data->philos[i].n_eat = data->n_philo_eat;
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
    }
	return (0);
}
