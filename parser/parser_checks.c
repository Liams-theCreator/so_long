/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:49:56 by imellali          #+#    #+#             */
/*   Updated: 2025/03/03 23:50:05 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(char **map, size_t height, size_t width)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_rectangle(char **map, size_t height)
{
	size_t	i;
	size_t	width;

	i = 1;
	if (!map[0])
		return (-1);
	width = ft_strlen(map[0]);
	while (i < height)
	{
		if (ft_strlen(map[i]) != width)
			return (-1);
		i++;
	}
	if (height >= width)
		return (-1);
	return (0);
}

int	check_valid_elems(t_elems elems)
{
	if (elems.player != 1 || elems.exit != 1 || elems.col < 1)
		return (-1);
	return (0);
}

int	check_map(char **map, size_t height)
{
	t_cords	cords;
	t_elems	elems;

	store_elems(map, height, &elems);
	if (check_valid_elems(elems) == -1)
		return (-1);
	store_cords(map, height, &cords);
	return (0);
}

int	check_ext(const char *file_name)
{
	int		i;

	i = 0;
	if (ft_strlen(file_name) < 5)
		return (-1);
	if (file_name[0] == '.')
		i++;
	while (file_name[i])
	{
		if (file_name[i] == '.')
			break ;
		i++;
	}
	if (ft_strncmp(&file_name[i], ".ber", 5) != 0)
		return (-1);
	return (0);
}
