/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:50:15 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/25 11:58:45 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parser(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->n_philo_eat = ft_atoi(argv[5]);
		if (data->n_philo_eat == 0)
		{
			write(1, "Wrong Arguments\n", 16);
			return (1);
		}
	}
	if (data->n_philo > 200 || data->n_philo == 0 || data->t_die < 60
	|| data->t_eat < 60 || data->t_sleep < 60)
	{
		write(1, "Wrong Arguments\n", 16);
		return (1);
	}
    return (0);
}

int forks_init(t_data *data)
{
	int i;

	i = 1;
	while(i < data->n_philo)
	{
		data->philos[i].lfork = data->forks[i - 1];
		data->philos[i].rfork = data->forks[i];
		i++;
	}
	data->philos[0].lfork = data->forks[data->n_philo - 1];
	data->philos[0].rfork = data->forks[0];
	return(0);
}