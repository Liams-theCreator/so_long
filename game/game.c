/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:21:04 by imellali          #+#    #+#             */
/*   Updated: 2025/03/06 19:45:34 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_texture(t_core *game, int x, int y, char elem)
{
	void	*img;

	img = NULL;
	if (elem == '0')
		img = game->ground;
	else if (elem == '1')
		img = game->wall;
	else if (elem == 'P')
		img = game->player;
	else if (elem == 'C')
		img = game->key;
	else if (elem == 'E')
		img = game->exit;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * 40, y * 40);
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
			put_texture(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

void	update_player_loc(t_core *game, int x, int y)
{
	game->map[game->cords.player_x][game->cords.player_y] = '0';
	game->cords.player_x = x;
	game->cords.player_y = y;
	game->map[x][y] = 'P';
	game->moves++;
	ft_printf("Moves : %d\n", game->moves);
	render_textures(game);
}

int	key_handler(int k, t_core *game)
{
	int	x;
	int	y;

	x = game->cords.player_x;
	y = game->cords.player_y;
	if (k == W)
		x--;
	else if (k == S)
		x++;
	else if (k == A)
		y--;
	else if (k == D)
		y++;
	else if (k == ESC)
		close_window(game);
	if (game->map[x][y] != '1' && (k == S || k == W || k == A || k == D))
	{
		if (game->map[x][y] == 'C')
			game->elems.col--;
		if (game->map[x][y] == 'E' && game->elems.col == 0)
			end_game(game);
		if (game->map[x][y] != 'E')
			update_player_loc(game, x, y);
	}
	return (0);
}

void	start_game(char **map, size_t height, t_cords *cords, t_elems *elems)
{
	t_core	game;
	size_t	width;

	game.mlx = mlx_init();
	if (!game.mlx)
		throw_error(map, "MLX init failed");
	width = ft_strlen(map[0]);
	game.win = mlx_new_window(game.mlx, width * 40, height * 40, "SO LONG");
	if (!game.win)
	{
		free(game.mlx);
		throw_error(map, "MLX new window failed");
	}
	init_game(&game, cords, elems, map);
	init_textures(&game);
	render_textures(&game);
	mlx_hook(game.win, DestroyNotify, 0, &close_window, &game);
	mlx_key_hook(game.win, &key_handler, &game);
	mlx_loop(game.mlx);
}
