/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:35:04 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 15:54:22 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"

void	print_philo_thinks(t_philo *philo)
{
	printf ("%dms [%d] is  thinking\n", get_time_ms(), philo->nbr);
}

void	print_philo_eats(t_philo *philo)
{
	printf ("%dms [%d] is  eating\n", get_time_ms(), philo->nbr);
}

void	print_philo_sleeps(t_philo *philo)
{
	printf ("%dms [%d] is  sleeping\n", get_time_ms(), philo->nbr);
}

void	print_philo_death(t_philo *philo)
{
	printf ("%dms [%d] died\n", get_time_ms(), philo->nbr);
}

void	print_fork_being_taken(t_philo *philo)
{
	printf ("%dms [%d] has taken a fork\n", get_time_ms(), philo->nbr);
}
