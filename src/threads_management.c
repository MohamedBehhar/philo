/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:53:04 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/15 16:22:16 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	int i = *(int*)arg;
	printf("hello: %d\n", i);
	return (0);
}

int create_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].thread_id, NULL, &routine, &data->philo[i].id) != 0)
			return (PHTREAD_ERR);
		i++;
	}
	return (0);
}