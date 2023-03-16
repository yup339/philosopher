/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:00 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 19:58:18 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "timer.h"

void	assign_forks(t_philo *philo, t_table *table)
{
	philo->right_fork = table->fork[philo->nbr];
	if (philo->nbr == 0)
		philo->left_fork = table->fork[table->nbr_philo - 1];
	else
		philo->left_fork = table->fork[philo->nbr - 1];
}

t_philo	*init_philosopher(int philo_nbr, t_table *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->nbr = philo_nbr;
	philo->state = THINK;
	philo->meal_left = table->meal_needed;
	philo->table = table;
	philo->time_of_last_action = 0;
	assign_forks(philo, table);
	philo->time_of_last_meal = get_time_ms();
	if (pthread_create(&philo->thread, NULL, philo_thread, philo))
		printf("Problem creating thread");
	return (philo);
}

t_fork	*init_fork(int fork_nbr)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	fork->nbr = fork_nbr;
	fork->in_use = false;
	pthread_mutex_init(&fork->mutex, NULL);
	return (fork);
}

void	create_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		table->fork[i] = init_fork(i);
		i++;
	}
		table->fork[i] = NULL;
	i = 0;
	while (i < table->nbr_philo)
	{
		table->philo[i] = init_philosopher(i, table);
		if (!table->philo[i])
			return ;
		i++;
		//usleep(PHILO_CREATE_WAIT);
	}
	table->philo[i] = NULL;
}
