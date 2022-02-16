/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:11:34 by mbehhar           #+#    #+#             */
/*   Updated: 2022/02/16 18:46:16 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#define MUTEX_ERR 1
#define PHTREAD_ERR 2

typedef struct s_philo
{
	int	id;
	int	left_fork;
	int right_fork;
	pthread_t thread_id;
	long long	last_eat;
	struct s_data *data;
}t_philo;

typedef struct s_data
{
	int	nbr_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	n_eat;
	int eating_counter;
	int	dieded;
	int	all_eat;
	long long first_time;
	pthread_mutex_t fork_mutex[210];
	pthread_mutex_t writing_mutex;
	pthread_mutex_t eating_mutex;
	t_philo philo[210];
}t_data;

// ERRORS 
void	put_error(char *str);

// UTILS 
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	print_state(t_data *data, int id, char *str);

// TIME 
long long	timestamp(void);
long long	time_diff(long long past, long long current);
void		smart_sleep(long long time, t_data *data);

// DATA 
int	ft_init_data(t_data *data, char **av, int ac);
int	ft_init_philo(t_data *data);

// THREADS MANAGEMENT
int	create_threads(t_data *data);
#endif