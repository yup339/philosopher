/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:02 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 19:57:43 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (table->fork[i])
	{
		pthread_mutex_destroy(&table->fork[i]->mutex);
		i++;
	}
	free_double_array((void **)table->fork);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	printf ("exiting \n");
	while (table->philo[i])
	{
		pthread_join(table->philo[i]->thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&table->meal_check);
	pthread_mutex_destroy(&table->death_check);
	pthread_mutex_destroy(&table->printing);
	free_forks(table);
	free_double_array((void **)table->philo);
}
