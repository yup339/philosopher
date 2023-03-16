/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:34:43 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/16 18:52:26 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "print_philo.h"
#include "timer.h"

int	take_forks(t_philo *philo)
{
	if (philo->table->nbr_philo == 1)
		return (0);
	pthread_mutex_lock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	if (philo->right_fork->in_use == true || philo->left_fork->in_use == true)
	{
		pthread_mutex_unlock(&philo->right_fork->mutex);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		return (0);
	}
	philo->right_fork->in_use = true;
	print_fork_being_taken(philo);
	philo->left_fork->in_use = true;
	print_fork_being_taken(philo);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	return (1);
}

void	put_forks_down(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->right_fork->in_use = false;
	philo->left_fork->in_use = false;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
}
