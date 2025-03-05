/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:21:04 by imellali          #+#    #+#             */
/*   Updated: 2025/03/05 00:48:00 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_core *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&width, &height);
	game->key = mlx_xpm_file_to_image(game->mlx, "textures/key.xpm",
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm",
			&width, &height);
	game->ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm",
			&width, &height);
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
			mlx_put_image_to_window(game->mlx, game->win, game->ground, x * 40, y * 40);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 40, y * 40);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, x * 40, y * 40);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->key, x * 40, y * 40);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 40, y * 40);
			x++;
		}
		y++;
	}
}

int	close_window(t_core *game)
{
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->key);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_array(game->map);
	exit(0);
	return (0);
}

int	key_handler(int key, t_core *game)
{
	int	x;
	int	y;

	x = game->cords.player_x;
	y = game->cords.player_y;
	if (key == W)
		x--;
	else if (key == S)
		x++;
	else if (key == A)
		y--;
	else if (key == D)
		y++;
	else if (key == ESC)
		close_window(game);
	if (game->map[x][y] != '1' && (key == S || key == W || key == A || key == D))
	{
		if (game->map[x][y] == 'C')
			game->elems.col--;
		if (game->map[x][y] == 'E' && game->elems.col == 0)
		{
			game->moves++;
			ft_printf("Moves : %d\n", game->moves);
			close_window(game);
		}
		if (game->map[x][y] != 'E')
		{
			game->map[game->cords.player_x][game->cords.player_y] = '0';
			game->cords.player_x = x;
			game->cords.player_y = y;
			game->map[x][y] = 'P';
			game->moves++;
			ft_printf("Moves : %d\n", game->moves);
			render_textures(game);
		}
	}
	return (0);
}

void	start_game(char **map, size_t height, t_cords *cords, t_elems *elems)
{
	t_core	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		throw_error(map, "MLX init failed");
	game.win = mlx_new_window(game.mlx, ft_strlen(map[0]) * 40, height * 40, "SIMO L AMRIKI");
	if (!game.win)
	{
		free(game.mlx);
		throw_error(map, "MLX new window failed");
	}
	game.map = map;
	game.cords = *cords;
	game.elems = *elems;
	game.moves = 0;
	init_textures(&game);
	render_textures(&game);
	mlx_hook(game.win, DestroyNotify, 0, &close_window, &game);
	mlx_key_hook(game.win, &key_handler, &game);
	mlx_loop(game.mlx);
}
