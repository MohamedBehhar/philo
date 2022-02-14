/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:18:03 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/14 16:51:42 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac != 5 && ac != 6)
		put_error("Insufficient Arguments\n");
	ft_init_data(&data, av, ac);
	// int i = 0;
	// while (++i <= data.nbr_philo)
	// 	printf("Philo_id: %d\nleft_fork: %d\nright_fork: %d\n------------\n", data.philo[i].id, data.philo[i].left_fork, data.philo[i].right_fork );
	
}