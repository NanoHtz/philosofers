/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:52:02 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/06/27 16:52:02 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	eat(t_philosopher *philo)
{
	t_table	*t;
	long	start;

	t = philo->table;
	start = get_time();
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = start;
	if (get_died(t))
	{
		print_action(philo, "is eating");
		philo->meals_eaten++;
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	while (get_died(t) && get_time() - start < t->time_to_eat)
		usleep(100);
}
