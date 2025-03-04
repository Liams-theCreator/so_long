/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:56:46 by imellali          #+#    #+#             */
/*   Updated: 2025/03/04 00:36:45 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copying(char **map, size_t height)
{
	size_t	i;
	char	**cpy;

	cpy = malloc(sizeof(char *) * (height + 1));
	if (!cpy)
		ft_error("Malloc Failed");
	i = 0;
	while (i < height)
	{
		cpy[i] = ft_strdup(map[i]);
		if (!cpy[i])
			throw_error(cpy, "Malloc Failed");
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	flood_fill(char **map, int px, int py, t_elems *elems)
{
	if (px < 0 || py < 0 || map[px][py] == '1' || map[px][py] == 'V')
		return ;
	if (map[px][py] == 'C')
		elems->col--;
	if (map[px][py] == 'E')
		elems->exit--;
	map[px][py] = 'V';
	flood_fill(map, px - 1, py, elems);
	flood_fill(map, px + 1, py, elems);
	flood_fill(map, px, py - 1, elems);
	flood_fill(map, px, py + 1, elems);
}

int	check_path(char **map, size_t height, t_cords *cords, t_elems *elems)
{
	char	**cmap;

	cmap = copying(map, height);
	if (!cmap)
		ft_error("Malloc Failed");
	flood_fill(cmap, cords->player_x, cords->player_y, elems);
	if (elems->col > 0 || elems->exit > 0)
	{
		free_array(cmap);
		return (-1);
	}
	free_array(cmap);
	return (0);
}
