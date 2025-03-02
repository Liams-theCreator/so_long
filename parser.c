/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:45:37 by imellali          #+#    #+#             */
/*   Updated: 2025/03/02 21:11:33 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(-1);
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

char	**copy_map(char *path, char **map, size_t height)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free_array(map);
			ft_error("GNL Failed\n");
		}
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**get_map(char *path, size_t *height)
{
	char	**map;
	char	*line;
	int		fd;

	*height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Open failed\n");
	line = get_next_line(fd);
	while (line)
	{
		(*height) += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = malloc(sizeof(char *) * (*height + 1));
	if (!map)
		ft_error("Malloc Failed\n");
	copy_map(path, map, *height);
	return (map);
}

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
	width = ft_strlen(map[0]);
	while (i < height)
	{
		if (ft_strlen(map[i]) != width)
			return (-1);
		i++;
	}
	if (i >= width - 1)
		return (-1);
	return (0);
}

void	init_struct_cords(t_cords *cords)
{
	cords->player_x = -1;
	cords->player_y = -1;
	cords->enemy_x = -1;
	cords->enemy_y = -1;
	cords->exit_x = -1;
	cords->exit_y = -1;
	cords->col_x = -1;
	cords->col_y = -1;
}

void	set_cords(int x, int y, int *cord_x, int *cord_y)
{
	*cord_x = x;
	*cord_y = y;
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
				set_cords(i, j, &cords->col_x, &cords->col_y);
			else if (map[i][j] == 'E')
				set_cords(i, j, &cords->exit_x, &cords->exit_y);
			else if (map[i][j] == 'N')
				set_cords(i, j, &cords->enemy_x, &cords->enemy_y);
			j++;
		}
		i++;
	}
}

void	init_struct_elems(t_elems *elems)
{
	elems->player = 0;
	elems->enemy = 0;
	elems->exit = 0;
	elems->col = 0;
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
			else if (map[i][j] == 'N')
				elems->enemy += 1;
			j++;
		}
		i++;
	}
}

int	check_valid_elems(t_elems elems)
{
	if (elems.player != 1 || elems.exit != 1)
		return (-1);
	if (elems.col < 1 || elems.enemy < 1)
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

/*
void	print_map(char **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
*/

int	main(int argc, char **argv)
{
	char	**map;
	size_t	height;

	if (argc != 2)
		ft_error("Invalid arguments ! > Usage : ./so_long map.ber\n");
	map = get_map(argv[1], &height);
	if (check_rectangle(map, height) == -1)
	{
		free_array(map);
		ft_error("Map is not rectangle\n");
	}
	if (check_walls(map, height, ft_strlen(map[0])) == -1)
	{
		free_array(map);
		ft_error("Map is not rounded by walls\n");
	}
	if (check_map(map, height) == -1)
	{
		free_array(map);
		ft_error("The game map is not playable\n");
	}
	free_array(map);
	ft_printf("Game is playable\n");
	return (0);
}
