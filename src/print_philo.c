/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:35:04 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/16 18:52:12 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"

void	print_philo_thinks(t_philo *philo)
{
	printf ("%dms %s[%d]\033[0;35m is thinking\n\033[0m",
		get_time_ms(), philo->name, philo->nbr);
}

void	print_philo_eats(t_philo *philo)
{
	printf ("%dms %s[%d]\033[0;33m is eating\n\033[0m",
		get_time_ms(), philo->name, philo->nbr);
}

void	print_philo_sleep(t_philo *philo)
{
	printf ("%dms %s[%d]\033[0;94m is sleeping\n\033[0m",
		get_time_ms(), philo->name, philo->nbr);
}

void	print_philo_death(t_philo *philo)
{
	printf ("%dms %s[%d]\033[1;31m died\n\033[0m", get_time_ms(),
		philo->name, philo->nbr);
}

void	print_fork_being_taken(t_philo *philo)
{
	printf ("%dms %s[%d]\033[0;90m has taken a fork \n\033[0m",
		get_time_ms(), philo->name, philo->nbr);
}
