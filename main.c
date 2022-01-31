/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:22:32 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/31 14:16:02 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 6 || argc < 5)
		return (p_error(2));
	else if (parser(argc, argv, &data) == 1)
		return (1);
	else if (forks_init(&data) == 1)
		return (free_all(&data));
	else if (philos_init(&data) == 1)
		return (free_all(&data));
	else if (data.n_philos == 1)
		one_philo(&data);
	else if (start_threads(&data) == 1)
		return (free_all(&data));
	free_all(&data);
	return (0);
}

int	start_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start = current_time();
	while (i < data->n_philos)
	{
		data->philos[i].last_meal = current_time();
		if (pthread_create(&data->philos[i].pth_id, NULL, routine,
				&(data->philos[i])))
			return (p_error(4));
		i++;
	}
	check_threads(data);
	pthread_mutex_unlock(&(data->write));
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_join(data->philos[i].pth_id, NULL) != 0)
			return (p_error(4));
		i++;
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 != 0)
		ft_usleep(2);
	while (philo->data->stop == 0 && philo->data->full == 0)
	{
		pthread_mutex_lock(philo->rfork);
		message(philo, "has taken a fork");
		pthread_mutex_lock(philo->lfork);
		message(philo, "has taken a fork");
		philo->last_meal = current_time();
		message(philo, "is eating");
		ft_usleep(philo->data->time_eat);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		philo->meals++;
		message(philo, "is sleeping");
		ft_usleep(philo->data->time_sleep);
		message(philo, "is thinking");
	}
	return (NULL);
}

void	check_threads(t_data *data)
{
	int	i;
	int	count;

	while (data->full == 0)
	{
		i = 0;
		count = 0;
		while (i < data->n_philos && data->stop == 0)
		{
			if ((int)(current_time() - data->philos[i].last_meal)
			> data->time_die)
			{
				message(&(data->philos[i]), "is dead");
				pthread_mutex_lock(&(data->write));
				data->stop = 1;
				return ;
			}
			if (data->philos[i].meals >= data->n_eat && data->n_eat != 0)
				count++;
			i++;
		}
		if (count == i)
			check_eat(data);
	}
}

void	check_eat(t_data *data)
{
	data->full = 1;
	data->stop = 1;
	pthread_mutex_lock(&(data->write));
	printf("All the philos ate at least %d times\n", data->n_eat);
}
