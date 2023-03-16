/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:00 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/16 19:01:55 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "timer.h"

char	*get_name(int i)
{
	static char	*names[] = {
		"Aristotle", "Plato", "Socrates", "René Descartes", "Immanuel Kant",
		"Friedrich Nietzsche", "MAXIME GG", "ZACH PABLO", "Jean-Jacques",
		"DAVE OF GPT", "Baruch Spinoza", "Georg Wilhelm Friedrich Hegel",
		"Ludwig Wittgenstein", "Martin Heidegger", "Søren Kierkegaard",
		"Friedrich Wilhelm Joseph Schelling", "Gottfried Wilhelm Leibniz",
		"Arthur Schopenhauer", "John Stuart Mill", "Bertrand Russell",
		"Michel Foucault", "ANTOINNUS", "Gilles Deleuze", "MATH THE KING",
		"OLIVER CROMWEL", "Simone de Beauvoir", "Judith Butler", "Edward Said",
		"Frantz Fanon", "GGIIIIGGGAA CHAD🗿 🗿 🗿 ", "Maurice Merleau-Ponty",
		"Jean-Paul Sartre", "Albert Camus", "RAPHAELLO SANTI", "Max Weber",
		"Karl Marx", "Friedrich Engels", "PASCAL BLAISE", "Louis Althusser",
		"Herbert Marcuse", "BRIAN of ALEXANDRIA", "Che Guevara", "Leon Trotsky",
		"Jean-François Lyotard", "Richard Rorty", "Noam Chomsky",
		"ROBBERT DIJKGRAAF", "Paul Feyerabend", "Michel Serres", "LISA SIMPSON"
	};
	int			num_names;

	num_names = sizeof(names) / sizeof(names[0]);
	return (names[i % num_names]);
}

void	assign_forks(t_philo *philo, t_table *table)
{
	philo->right_fork = table->fork[philo->nbr];
	if (philo->nbr == 0)
		philo->left_fork = table->fork[table->nbr_philo - 1];
	else
		philo->left_fork = table->fork[philo->nbr - 1];
}

t_philo	*init_philosopher(int philo_nbr, t_table *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->nbr = philo_nbr;
	philo->state = THINK;
	philo->meal_left = table->meal_needed;
	philo->table = table;
	philo->name = get_name(philo_nbr);
	assign_forks(philo, table);
	philo->time_of_last_action = get_time_ms();
	philo->time_of_last_meal = get_time_ms();
	if (pthread_create(&philo->thread, NULL, philo_thread, philo))
		printf("Problem creating thread");
	return (philo);
}

t_fork	*init_fork(int fork_nbr)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	fork->nbr = fork_nbr;
	fork->in_use = false;
	pthread_mutex_init(&fork->mutex, NULL);
	return (fork);
}

void	create_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		table->fork[i] = init_fork(i);
		i++;
	}
		table->fork[i] = NULL;
	i = 0;
	while (i < table->nbr_philo)
	{
		table->philo[i] = init_philosopher(i, table);
		if (!table->philo[i])
			return ;
		i++;
		usleep(1000);
	}
	table->philo[i] = NULL;
}
