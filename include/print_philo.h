/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:35:27 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/16 18:52:00 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_PHILO_H
# define PRINT_PHILO_H

void	print_philo_thinks(t_philo *philo);
void	print_philo_eats(t_philo *philo);
void	print_philo_sleep(t_philo *philo);
void	print_philo_death(t_philo *philo);
void	print_fork_being_taken(t_philo *philo);

#endif