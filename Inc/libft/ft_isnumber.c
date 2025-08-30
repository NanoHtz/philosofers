/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:19:18 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/08/30 13:19:18 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
