/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:28:22 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/07 07:13:13 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

int	check_param(int ac, char **av, t_table *table)
{
	if (ac != 5 && ac != 6)
		return (printf("Wrong number of args\n"));
	if (!is_str_int(av[1]) ||!is_str_int(av[2]) || !is_str_int(av[3])
		|| !is_str_int(av[4]))
		return (printf("args are not all INT\n"));
	if (ac == 6)
		if (!is_str_int(av[5]))
			return (printf("args are not all INT\n"));
	table->nbr_philo = ft_atoi(av[1]);
	table->action_time.ttd = ft_atoi(av[2]);
	table->action_time.tte = ft_atoi(av[3]);
	table->action_time.tts = ft_atoi(av[4]);
	if (table->action_time.ttd <= 0 || table->action_time.tte <= 0
		|| table->action_time.tts <= 0 || table->nbr_philo <= 0)
		return (printf("args are smaller than 1\n"));
	if (ac == 6)
	{
		table->meal_needed = ft_atoi(av[5]);
		if (table->meal_needed <= 0)
			return (printf("args are smaller than 1\n"));
	}
	return (0);
}
