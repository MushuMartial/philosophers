/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:50:15 by tmartial          #+#    #+#             */
/*   Updated: 2022/01/19 13:42:19 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_long(const char *str, int i)
{
	unsigned long long	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i++] - '0');
		if (num > 2147483647)
			return (0);
	}
	if (str[i] != '\0')
		return(0);
	return ((int)(num));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	num;

	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			return (0);
	}
	num = (verif_long(str, i));
	return (num);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

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