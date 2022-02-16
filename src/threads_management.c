/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:53:04 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/16 18:56:47 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_eat(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&data->fork_mutex[philo->left_fork]);
	pthread_mutex_lock(&data->fork_mutex[philo->right_fork]);
	print_state(data, philo->id, "has taken a fork\n");
	print_state(data, philo->id, "has taken a fork\n");
	pthread_mutex_lock(&data->eating_mutex);
	print_state(data, philo->id, "is eating\n");
	philo->last_eat = timestamp();
	usleep(200 * 1000);
	printf("eat 2: %lld\n", philo->last_eat);
	
}

void	*routine(void *arg)
{
	int i;
	t_philo *philo;
	t_data *data;

	i = 0;
	philo = (t_philo *)arg;
	data = philo->data;
	while (data->dieded == 0)
	{
		ft_philo_eat(philo);
		
	}
	
	return (0);
}

int create_threads(t_data *data)
{
	int i;

	data->first_time = timestamp();
	i = 1;
	while (i <= data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].thread_id, NULL, &routine, &data->philo[i]) != 0)
			return (PHTREAD_ERR);
		usleep(10);
		i++;
	}
	return (0);
}