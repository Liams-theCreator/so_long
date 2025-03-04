/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:59:14 by imellali          #+#    #+#             */
/*   Updated: 2025/03/03 23:59:25 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_cords(int x, int y, int *cord_x, int *cord_y)
{
	*cord_x = x;
	*cord_y = y;
}

void	set_cords2(int x, int y, int *cord_x, int *cord_y)
{
	int	index;

	index = cord_x[0];
	if (index < 44)
	{
		cord_x[index + 1] = x;
		cord_y[index + 1] = y;
		cord_x[0]++;
	}
}

void	store_cords(char **map, size_t height, t_cords *cords)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_struct_cords(cords);
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				set_cords(i, j, &cords->player_x, &cords->player_y);
			else if (map[i][j] == 'C')
				set_cords2(i, j, cords->col_x, cords->col_y);
			else if (map[i][j] == 'E')
				set_cords(i, j, &cords->exit_x, &cords->exit_y);
			j++;
		}
		i++;
	}
}

void	store_elems(char **map, size_t height, t_elems *elems)
{
	size_t	i;
	size_t	j;

	i = 0;
	init_struct_elems(elems);
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				elems->player += 1;
			else if (map[i][j] == 'C')
				elems->col += 1;
			else if (map[i][j] == 'E')
				elems->exit += 1;
			j++;
		}
		i++;
	}
}
