/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:48:51 by imellali          #+#    #+#             */
/*   Updated: 2025/03/06 19:55:57 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_text(char **map, size_t height)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' || map[i][j] != '1' || map[i][j] != 'P' ||
					map[i][j] != 'C' || map[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_error(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(-1);
}

void	throw_error(char **array, char *msg)
{
	free_array(array);
	ft_error(msg);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
