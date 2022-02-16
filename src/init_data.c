/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:34:06 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/16 17:06:50 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL) != 0)
			return (MUTEX_ERR);
		i++;
	}
	return (0);
}


int	ft_init_philo(t_data *data)
{
	int i;

	i = 1;
	while (i <= data->nbr_philo)
	{
		data->philo[i].id = i  ;
		data->philo[i].left_fork = i ;
		data->philo[i].right_fork = (i % data->nbr_philo ) + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	ft_init_data(t_data *data, char **av, int ac)
{
	data->nbr_philo = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	data->dieded = 0;
	data->all_eat = 0;
	if (data->nbr_philo < 0 || data->tt_die < 0 || data->tt_eat < 0
		|| data->tt_sleep < 0)
		put_error("Invalid Arguments\n");
	if (ac == 6)
	{
		data->n_eat = ft_atoi(av[5]);
			if (data->n_eat < 0)
				put_error("Invalid Arguments\n");
	}
	ft_init_philo(data);
	if (ft_init_mutex(data) == MUTEX_ERR)
		return (1);
	if (create_threads(data) == PHTREAD_ERR)
		return (1);
	return (0);
}