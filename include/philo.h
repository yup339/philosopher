/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:51:08 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:35 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "struct.h"
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo_act{
	int	ttd;
	int	tte;
	int	tts;
}	t_philo_act;

enum e_philo_state
{
	THINK = 0,
	EAT = 1,
	SLEEP = 2
};

typedef struct s_fork{
	pthread_mutex_t	mutex;
	bool			in_use;
	int				nbr;
}	t_fork;

typedef struct s_philo{
	pthread_t			thread;
	int					meal_left;
	int					nbr;
	enum e_philo_state	state;
	int					time_of_last_meal;
	int					time_of_last_action;
	t_fork				*left_fork;
	t_fork				*right_fork;
	struct s_table		*table;
}	t_philo;

typedef struct s_table{
	int				nbr_philo;
	bool			dead_philo;
	bool			allow_print;
	t_philo			*philo[201];
	t_fork			*fork[201];
	int				meal_needed;
	t_philo_act		action_time;
	pthread_mutex_t	printing;
	pthread_mutex_t	death_check;
	pthread_mutex_t	meal_check;
}	t_table;

# define ASK 1
# define TELL 2

void	*philo_thread(void	*ptr);
void	philo_thinks(t_philo *philo);
void	philo_sleeps(t_philo *philo);
void	philo_eats(t_philo *philo);
bool	is_dead_at_table(t_table *table, int task);

#endif
