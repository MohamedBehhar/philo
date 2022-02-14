/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:34:06 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/14 18:34:22 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg){
	int i;
	i = *(int*)arg;
	printf("%d Thread Created\n", i);
	fflush(stdout);
	// lock(fork[philo->id]);
	// lock(fork[philo->id + 1 % philo->data->nbr_philos]);
	usleep(10000);
	// free(arg);
	return NULL;
}

void	create_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nbr_philo)
	{
		// usleep(100);
		// puts("here\n");
		pthread_create(&data->philo[i].ph_thread, NULL, &routine, &i);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(data->philo[i].ph_thread, NULL);
		i++;
	}
}

int	ft_init_philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = i + 1;
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
	if (data->nbr_philo < 0 || data->tt_die < 0 || data->tt_eat < 0
		|| data->tt_sleep < 0)
		put_error("Invalid Arguments\n");
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
			if (data->n_eat < 0)
				put_error("Invalid Arguments\n");
	ft_init_philo(data);
	create_threads(data);
	return (0);
}