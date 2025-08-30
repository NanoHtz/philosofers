/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:24:16 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/08/29 12:24:16 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	*one_philo(t_philosopher *philo, t_table *t)
{
	long	start;

	start = philo->last_meal;
	lock_fork(philo, philo->left_fork);
	while (get_time() - start < t->time_to_die)
		usleep(100);
	print_action(philo, "died");
	set_died(t);
	return (NULL);
}

/* [ADDED] Desfase para N impar: reparte turnos (evita hambre al inicio de cada ciclo) */
static void	stagger_if_odd(t_philosopher *philo)
{
	t_table	*t;
	long	start;

	t = philo->table;
	if ((t->num_philosophers % 2) == 1 && (philo->id % 2) == 0)  /* pares se desfasan */
	{
		start = get_time();
		while (get_died(t) && get_time() - start < (t->time_to_eat / 2))
			usleep(100);
	}
}

/* [ADDED] Desfase de primera vuelta para N PAR (evita colisión exacta) */
static void	stagger_even_first_turn(t_philosopher *philo)
{
	t_table	*t;
	long	start;

	t = philo->table;
	/* pares se desfasan media comida SOLO si aún no han comido */
	if ((t->num_philosophers % 2) == 0
		&& (philo->id % 2) == 1
		&& philo->meals_eaten == 0)
	{
		start = get_time();
		while (get_died(t) && get_time() - start < (t->time_to_eat / 2))
			usleep(100);
	}
}

void	*routine(void *arg)
{
	t_philosopher	*philo;
	t_table			*t;

	philo = arg;
	t = philo->table;
	while (get_time() < t->start_time && get_died(t))
		usleep(100);
	while (get_died(t))
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (t->must_eat >= 0
			&& philo->meals_eaten >= t->must_eat)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		if (t->num_philosophers == 1)
			return (one_philo(philo, t));
		//dbg_event(philo, "before_take");
		stagger_even_first_turn(philo);     /* [ADDED] */
		stagger_if_odd(philo);
		take_forks(philo);
		eat(philo);
		//dbg_event(philo, "after_eat");
		unlock_forks(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}
