/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:21:04 by imellali          #+#    #+#             */
/*   Updated: 2025/03/04 05:02:23 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_core *game)
{
	int	img_width;
	int	img_height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&img_width, &img_height);
	game->key = mlx_xpm_file_to_image(game->mlx, "textures/key.xpm",
			&img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&img_width, &img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm",
			&img_width, &img_height);
	if (!game->wall || !game->player || !game->key
		|| !game->exit || !game->ground)
		throw_error(game->map, "Failed to init textures");
}

void	render_textures(t_core *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->ground, x * 32, y * 50);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 32, y * 50);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, x * 32, y * 50);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->key, x * 32, y * 50);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 32, y * 50);
			x++;
		}
		y++;
	}
}

void	start_game(char **map, size_t height, t_cords *cords)
{
	t_core	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		throw_error(map, "MLX init failed");
	game.win = mlx_new_window(game.mlx, ft_strlen(map[0]) * 32, height * 50, "Window");
	if (!game.win)
	{
		free(game.mlx);
		throw_error(map, "MLX new window failed");
	}
	game.map = map;
	game.cords = *cords;
	init_textures(&game);
	render_textures(&game);
	mlx_loop(game.mlx);
}
