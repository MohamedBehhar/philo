/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:19:36 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/11 13:18:32 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	put_error(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, "Error:\n", 7);
	write(1, str, len);
	exit(1);
}