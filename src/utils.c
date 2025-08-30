/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:09:56 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/06/25 20:09:56 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	set_died(t_table *table)
{
	pthread_mutex_lock(&table->died_mutex);
	table->died = 1;
	pthread_mutex_unlock(&table->died_mutex);
}

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + ((tv.tv_usec / 1000));
	return (time);
}

long	ft_time(t_philosopher *philo)
{
	long	time;

	time = get_time() - philo->table->start_time;
	return (time);
}

void	print_action(t_philosopher *philo, char *msg)
{
	if (!philo || !philo->table)
	{
		printf("ERROR: print_action recibió philo o table NULL\n");
		return ;
	}
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d %s\n", ft_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
