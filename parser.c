/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:45:37 by imellali          #+#    #+#             */
/*   Updated: 2025/03/03 21:37:31 by imellali         ###   ########.fr       */
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
			ft_error("GNL Failed");
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
		ft_error("Open failed");
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
		ft_error("Malloc Failed");
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

void	init_struct_cords(t_cords *cords)
{
	cords->player_x = -1;
	cords->player_y = -1;
	cords->enemy_x[0] = 0;
	cords->enemy_y[0] = 0;
	cords->exit_x = -1;
	cords->exit_y = -1;
	cords->col_x[0] = 0;
	cords->col_y[0] = 0;
}

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
			else if (map[i][j] == 'N')
				set_cords2(i, j, cords->enemy_x, cords->enemy_y);
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

void print_elems(t_elems elems)
{
    ft_printf("Player: %d\n", elems.player);
    ft_printf("Exit: %d\n", elems.exit);
    ft_printf("Collectibles: %d\n", elems.col);
    ft_printf("Enemies: %d\n", elems.enemy);
}

void print_cords(t_cords cords)
{
    ft_printf("Player coordinates: (%d, %d)\n", cords.player_x, cords.player_y);
    ft_printf("Exit coordinates: (%d, %d)\n", cords.exit_x, cords.exit_y);

	for (int i = 1; i <= cords.col_x[0]; i++)
    	ft_printf("Collectible %d: (%d, %d)\n", i, cords.col_x[i], cords.col_y[i]);

	for (int i = 1; i <= cords.enemy_x[0]; i++)
    	ft_printf("Enemy %d: (%d, %d)\n", i, cords.enemy_x[i], cords.enemy_y[i]);

}
*/

void	init_and_store(char **map, size_t height, t_elems *elems, t_cords *cords)
{
	init_struct_elems(elems);
	init_struct_cords(cords);
	store_elems(map, height, elems);
	store_cords(map, height, cords);
}

void	throw_error(char **array, char *msg)
{
	free_array(array);
	ft_error(msg);
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
		elems->exit = 1;
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
	if (elems->col > 0 || elems->exit == 1)
	{
		free_array(cmap);
		return (-1);
	}
	free_array(cmap);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	size_t	height;
	t_elems	elems;
	t_cords	cords;

	if (argc != 2)
		ft_error("Invalid arguments !");
	if (check_ext(argv[1]) == -1)
		ft_error("Wrong extenstion !");
	map = get_map(argv[1], &height);
	if (check_rectangle(map, height) == -1)
		throw_error(map, "Map is not rectangle");
	if (check_walls(map, height, ft_strlen(map[0])) == -1)
		throw_error(map, "Map is not rounded by Walls");
	if (check_map(map, height) == -1)
		throw_error(map, "Map is not playable");
	init_and_store(map, height, &elems, &cords);
	if (check_path(map, height, &cords, &elems) == -1)
		throw_error(map, "Invalid path");
	//print_map(map, height);
	//print_elems(elems);
	//print_cords(cords);
	free_array(map);
	ft_printf("Game is playable\n");
	return (0);
}
