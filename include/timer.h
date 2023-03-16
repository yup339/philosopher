/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 06:14:14 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 16:33:39 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

int		get_time_ms(void);
int		is_philo_dead(t_philo *philo);
bool	is_state_finish(t_philo	*philo, int action_time);

# define PHILO_CREATE_WAIT 10

#endif