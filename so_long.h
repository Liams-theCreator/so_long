/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:19:15 by imellali          #+#    #+#             */
/*   Updated: 2025/03/06 19:54:46 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./srcs/printf/ft_printf.h"
# include "./srcs/gnl/get_next_line_bonus.h"
# include "./srcs/libft/libft.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct elems
{
	int	player;
	int	col;
	int	exit;
}	t_elems;

typedef struct cords
{
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
}	t_cords;

typedef struct core
{
	void	*mlx;
	void	*win;
	char	**map;
	t_cords	cords;
	t_elems	elems;
	void	*player;
	void	*key;
	void	*exit;
	void	*wall;
	void	*ground;
	int		moves;
}	t_core;

/* Parsing Part */
int		check_walls(char **map, size_t height, size_t width);
int		check_rectangle(char **map, size_t height);
int		check_text(char **map, size_t height);
int		check_map(char **map, size_t height);
int		check_valid_elems(t_elems elems);
int		check_ext(const char *file_name);
int		check_path(char **map, size_t height, t_cords *cords, t_elems *elems);
char	**get_map(char *path, size_t *height);
char	**copy_map(char *path, char **map, size_t height);
char	**copying(char **map, size_t height);
void	init_struct_elems(t_elems *elems);
void	init_struct_cords(t_cords *cords);
void	init_and_store(char **map, size_t ht, t_elems *elems, t_cords *cords);
void	set_cords(int x, int y, int *cord_x, int *cord_y);
void	set_cords2(int x, int y, int *cord_x, int *cord_y);
void	store_cords(char **map, size_t height, t_cords *cords);
void	store_elems(char **map, size_t height, t_elems *elems);
void	flood_fill(char **map, int px, int py, t_elems *elems);

/* Errors handling functions */
void	ft_error(char *error_msg);
void	throw_error(char **array, char *msg);
void	free_array(char **array);

/* Game core functions*/
void	start_game(char **map, size_t height, t_cords *cords, t_elems *elems);
void	init_game(t_core *game, t_cords *cords, t_elems *elems, char **map);
void	init_textures(t_core *game);
void	end_game(t_core *game);
int		close_window(t_core *game);

#endif
