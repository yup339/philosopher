/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:08:34 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 20:07:27 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "print_philo.h"
#include "eating.h"
#include "timer.h"

void	philo_dies(t_philo	*philo)
{
	print_philo_death(philo);
	pthread_mutex_lock(&philo->table->death_check);
	philo->table->dead_philo = true;
	pthread_mutex_unlock(&philo->table->death_check);
}

void	philo_thinks(t_philo *philo)
{
	print_philo_thinks(philo);
	while (!take_forks(philo))
	{
		if (is_dead_at_table(philo->table, ASK))
			return ;
		if (is_philo_dead(philo))
			return (philo_dies(philo));
	}
	philo->state = EAT;
}

void	philo_eats(t_philo *philo)
{
	print_philo_eats(philo);
	while (is_state_finish(philo, philo->table->action_time.tte))
	{
		if (is_philo_dead(philo))
			return (philo_dies(philo));
		if (is_dead_at_table(philo->table, ASK))
			return ;
	}
	put_forks_down(philo);
	philo->time_of_last_meal = get_time_ms();
	philo->time_of_last_action = philo->time_of_last_meal;
	if (philo->meal_left > 0)
	{
		pthread_mutex_lock(&philo->table->meal_check);
		philo->meal_left--;
		if (philo->meal_left == 0)
		{
			pthread_mutex_unlock(&philo->table->meal_check);
			return ;
		}
		pthread_mutex_unlock(&philo->table->meal_check);
	}
	philo->state = SLEEP;
}

void	philo_sleeps(t_philo *philo)
{
	print_philo_sleeps(philo);
	while (is_state_finish(philo, philo->table->action_time.tts))
	{
		if (is_philo_dead(philo))
			return (philo_dies(philo));
		if (is_dead_at_table(philo->table, ASK))
			return ;
	}
	philo->time_of_last_action = get_time_ms();
	philo->state = THINK;
}

void	*philo_thread(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!is_dead_at_table(philo->table, ASK) && philo->meal_left)
	{
		if (philo->state == THINK)
			philo_thinks(philo);
		else if (philo->state == EAT)
			philo_eats(philo);
		else if (philo->state == SLEEP)
			philo_sleeps(philo);
	}
	return (0);
}
