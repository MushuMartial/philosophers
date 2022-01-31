/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:59:02 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/30 12:59:02 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(int argc, char **argv, t_data *data)
{
	data->n_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->stop = 0;
	data->full = 0;
	if (argc == 6)
	{
		data->n_eat = ft_atoi(argv[5]);
		if (data->n_eat <= 0)
			return (p_error(1));
	}
	else
		data->n_eat = 0;
	if (data->n_philos > 200 || data->n_philos <= 0 || data->time_die < 60
		|| data->time_eat < 60 || data->time_sleep < 60)
		return (p_error(2));
	return (0);
}

int	forks_init(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (p_error(0));
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&(data->forks[i++]), NULL))
			return (p_error(3));
	}
	if (pthread_mutex_init(&(data->write), NULL))
		return (p_error(3));
	return (0);
}

int	philos_init(t_data *data)
{
	int		i;

	i = 1;
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philos)
		return (p_error(0));
	data->philos[0].id = 1;
	data->philos[0].data = data;
	data->philos[0].meals = 0;
	data->philos[0].rfork = &data->forks[0];
	data->philos[0].lfork = &data->forks[data->n_philos - 1];
	while (i < data->n_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].meals = 0;
		data->philos[i].rfork = &data->forks[i];
		data->philos[i].lfork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

int	one_philo(t_data *data)
{
	write(1, "0 1 has only one fork\n", 22);
	ft_usleep(data->time_die);
	printf("%d 1 is dead\n", data->time_die);
	return (1);
}
