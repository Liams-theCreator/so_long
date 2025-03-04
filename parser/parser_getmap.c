/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_getmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:02:44 by imellali          #+#    #+#             */
/*   Updated: 2025/03/04 00:02:55 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
