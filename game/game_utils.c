/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:09:02 by imellali          #+#    #+#             */
/*   Updated: 2025/03/06 17:12:45 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_core *game, t_cords *cords, t_elems *elems, char **map)
{
	game->map = map;
	game->cords = *cords;
	game->elems = *elems;
	game->moves = 0;
	game->wall = NULL;
	game->ground = NULL;
	game->player = NULL;
	game->key = NULL;
	game->exit = NULL;
}

void	texture_error(t_core *game, char *msg)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->key)
		mlx_destroy_image(game->mlx, game->key);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_array(game->map);
	ft_printf("%s\n", msg);
	exit(-1);
}

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
		texture_error(game, "init texture failed");
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

void	end_game(t_core *game)
{
	game->moves++;
	ft_printf("Moves : %d\n", game->moves);
	close_window(game);
}
