/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:19:15 by imellali          #+#    #+#             */
/*   Updated: 2025/03/03 21:49:28 by imellali         ###   ########.fr       */
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
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line_bonus.h"
# include "./libft/libft.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct elems
{
	int	player;
	int	enemy;
	int	col;
	int	exit;
}	t_elems;

typedef struct cords
{
	int	player_x;
	int	player_y;
	int	enemy_x[45];
	int	enemy_y[45];
	int	col_x[45];
	int	col_y[45];
	int	exit_x;
	int	exit_y;
}	t_cords;

#endif
