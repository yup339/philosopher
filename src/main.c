/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:50:53 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/14 16:22:01 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parsing.h"
#include "init.h"
#include "terminate.h"

bool	is_dead_at_table(t_table *table, int task)
{
	bool	answer;

	pthread_mutex_lock(&table->death_check);
	if (task == ASK)
		answer = table->dead_philo;
	else
	{
		table->dead_philo = true;
		answer = 1;
	}
	pthread_mutex_unlock(&table->death_check);
	return (answer);
}

bool	is_dinner_finish(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->meal_check);
	while (table->philo[i])
	{
		if (table->philo[i]->meal_left)
		{
			pthread_mutex_unlock(&table->meal_check);
			return (false);
		}
		i++;
	}
	pthread_mutex_unlock(&table->meal_check);
	return (true);
}

int	main(int ac, char **av)
{
	t_table	table;

	table.meal_needed = -1;
	table.dead_philo = false;
	table.allow_print = true;
	pthread_mutex_init(&table.printing, NULL);
	pthread_mutex_init(&table.death_check, NULL);
	pthread_mutex_init(&table.meal_check, NULL);
	if (check_param(ac, av, &table))
		return (0);
	create_philo(&table);
	while (!is_dead_at_table(&table, ASK) && !is_dinner_finish(&table))
		usleep (1000);
	free_table(&table);
	return (1);
}
