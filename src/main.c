/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:10:05 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/12/05 15:14:50 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

int	is_number(char *av)
{
	int	i;

	i = 0;
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
	int	i;

	i = 1;
	if (ac != 5)
		return (-1);
	while (i < ac)
	{
		if (is_number(av[i]) != 0)
			return (-1);
		printf("El argumento %d es: %s.\n", i, av[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (check_args(ac, av) == -1)
		printf("Los argumentos no son válidos\n");
	else
		printf("Los argumentos son válidos\n");
}
