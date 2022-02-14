/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:11:34 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/14 18:05:49 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo
{
	int	id;
	int	left_fork;
	pthread_t ph_thread;
	struct s_data *data;
}t_philo;

typedef struct s_data
{
	int	nbr_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	n_eat;
	long int frst_time;
	int	dieded;
	pthread_mutex_t fork_mutex[210];
	t_philo philo[210];
}t_data;

// ERRORS 
void	put_error(char *str);

// UTILS 
int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_strlen(const char *s);
int	ft_atoi(const char *str);

// DATA 
int	ft_init_data(t_data *data, char **av, int ac);
int	ft_init_philo(t_data *data);
#endif