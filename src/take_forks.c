/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:00:05 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/06/25 20:00:05 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	unlock_fork(t_philosopher *philo, int fork_index)
{
	pthread_mutex_unlock(&philo->table->forks[fork_index]);
	if (get_died(philo->table))
		print_action(philo, "put down a fork");
}

int	lock_fork(t_philosopher *philo, int fork_index)
{
	if (!get_died(philo->table))
		return (0);
	pthread_mutex_lock(&philo->table->forks[fork_index]);
	if (!get_died(philo->table))
	{
		pthread_mutex_unlock(&philo->table->forks[fork_index]);
		return (0);
	}
	print_action(philo, "has taken a fork");
	return (1);
}

/* [CHANGED] Orden híbrido:
   - N PAR  -> par/impar (estable para 4 filósofos)
   - N IMPAR-> índice menor primero (reduce hambre en 5 filósofos)
*/
void	take_forks(t_philosopher *philo)
{
	int			f1;
	int			f2;
	t_table		*t;

	t = philo->table;
	if (t->num_philosophers == 1)
	{
		/* [UNCHANGED] caso N=1: el monitor detectará la muerte */
		lock_fork(philo, philo->left_fork);
		return ;
	}
	/* [CHANGED] selección de orden según paridad de N */
	if ((t->num_philosophers % 2) == 0)
	{
		/* [CHANGED] N PAR: orden par/impar */
		if (philo->id % 2 == 0)
		{
			f1 = philo->left_fork;
			f2 = philo->right_fork;
		}
		else
		{
			f1 = philo->right_fork;
			f2 = philo->left_fork;
		}
	}
	else
	{
		/* [CHANGED] N IMPAR: índice menor primero */
		if (philo->left_fork < philo->right_fork)
		{
			f1 = philo->left_fork;
			f2 = philo->right_fork;
		}
		else
		{
			f1 = philo->right_fork;
			f2 = philo->left_fork;
		}
	}
	/* [UNCHANGED] coger f1 y luego f2 (bloqueante) */
	if (!lock_fork(philo, f1))
		return ;
	if (!lock_fork(philo, f2))
	{
		pthread_mutex_unlock(&t->forks[f1]);
		return ;
	}
}

void	unlock_forks(t_philosopher *philo)
{
	if (philo->table->num_philosophers == 1)
	{
		unlock_fork(philo, philo->left_fork);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		unlock_fork(philo, philo->left_fork);
		unlock_fork(philo, philo->right_fork);
	}
	else
	{
		unlock_fork(philo, philo->right_fork);
		unlock_fork(philo, philo->left_fork);
	}
}
