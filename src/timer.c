/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 05:43:16 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 19:57:09 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_ms(void)
{
	static struct timeval	start = {0, 0};
	struct timeval			now;
	int						time;

	if (start.tv_sec == 0 && start.tv_usec == 0)
		gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	time = (now.tv_sec - start.tv_sec) * 1000;
	time += (now.tv_usec - start.tv_usec) / 1000;
	return (time);
}

int	is_philo_dead(t_philo *philo)
{
	if (get_time_ms() - philo->time_of_last_meal
		> philo->table->action_time.ttd)
		return (1);
	return (0);
}

bool	is_state_finish(t_philo	*philo, int action_time)
{
	if (philo->time_of_last_action + action_time >= get_time_ms())
		return (true);
	return (false);
}
