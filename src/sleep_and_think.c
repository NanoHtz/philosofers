/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:32:40 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/07/01 10:32:40 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	sleep_and_think(t_philosopher *philo)
{
	long	start;

	if (get_died(philo->table))
		print_action(philo, "is sleeping");
	start = get_time();
	while (get_died(philo->table)
		&& get_time() - start < philo->table->time_to_sleep)
		usleep(100);
	if (get_died(philo->table))
		print_action(philo, "is thinking");
}
