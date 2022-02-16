/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:18:03 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/16 17:39:18 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac != 5 && ac != 6)
		put_error("Insufficient Arguments\n");
	ft_init_data(&data, av, ac);
}