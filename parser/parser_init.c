/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:46:14 by imellali          #+#    #+#             */
/*   Updated: 2025/03/03 23:46:27 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct_elems(t_elems *elems)
{
	elems->player = 0;
	elems->exit = 0;
	elems->col = 0;
}

void	init_struct_cords(t_cords *cords)
{
	cords->player_x = -1;
	cords->player_y = -1;
	cords->exit_x = -1;
	cords->exit_y = -1;
	cords->col_x[0] = 0;
	cords->col_y[0] = 0;
}

void	init_and_store(char **map, size_t ht, t_elems *elems, t_cords *cords)
{
	init_struct_elems(elems);
	init_struct_cords(cords);
	store_elems(map, ht, elems);
	store_cords(map, ht, cords);
}
