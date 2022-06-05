/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:58:51 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/31 14:19:17 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	current_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (1000 * t.tv_sec + t.tv_usec / 1000);
}

void	ft_usleep(int msec)
{
	unsigned long	time;

	time = current_time();
	while (current_time() < time + msec)
		usleep(500);
}

void	message(t_philo *philo, char *str)
{
	unsigned long	time;

	pthread_mutex_lock(&(philo->data->write));
	if (philo->data->stop == 0)
	{
		time = current_time() - philo->data->start;
		printf("%lu %d %s\n", time, philo->id, str);
	}
	pthread_mutex_unlock(&(philo->data->write));
}

int	p_error(int msg)
{
	if (msg == 0)
		write(1, "Error : Malloc error\n", 21);
	else if (msg == 1)
		write(1, "Error : Argv[5] must be > 0\n", 28);
	else if (msg == 2)
		write(1, "Error : Wrong Arguments\n", 24);
	else if (msg == 3)
		write(1, "Error : Mutex init error\n", 25);
	else if (msg == 4)
		write(1, "Error : Pthread error\n", 22);
	return (1);
}

int	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos)
		free(data->philos);
	if (data->forks)
	{
		while (i < data->n_philos)
		{
			if (pthread_mutex_destroy(&(data->forks[i])) != 0)
				return (free_all(data));
			i++;
		}
		free(data->forks);
	}
	i = pthread_mutex_unlock(&(data->write));
	if (i == 0)
	{
		if (pthread_mutex_destroy(&(data->write)) != 0)
			return (free_all(data));
	}
	return (1);
}
