/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:34:33 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/06/24 11:34:33 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '\0')
		return (ft_perror(E_EMPTY, -1));
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int		i;
	long	nbr;

	i = 1;
	if (ac != 5 && ac != 6)
		return (ft_perror(E_ARGS, -1));
	while (i < ac)
	{
		if (is_number(av[i]) != 0)
			return (ft_perror(E_SIGN, -1));
		nbr = ft_atol(av[i]);
		if ((nbr <= 0) || nbr > INT_MAX)
			return (ft_perror(E_RANGE, -1));
		if (i == 1 && nbr < 1)
			return (ft_perror(E_PHILO, -1));
		i++;
	}
	return (0);
}
