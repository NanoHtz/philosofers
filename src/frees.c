/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:26:23 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/07/01 10:26:23 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	free_philo(t_table *table, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < table->num_philosophers)
		pthread_mutex_destroy(&philos[i++].meal_mutex);
	free(philos);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philosophers)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_mutex);
	free(table->forks);
	free(table);
}
