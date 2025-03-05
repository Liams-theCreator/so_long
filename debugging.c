/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:37:23 by imellali          #+#    #+#             */
/*   Updated: 2025/03/05 00:44:25 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

void	print_elems(t_elems elems)
{
	ft_printf("Player: %d\n", elems.player);
	ft_printf("Exit: %d\n", elems.exit);
	ft_printf("Collectibles: %d\n", elems.col);
}

void	print_cords(t_cords cords)
{
	ft_printf("Player coordinates: (%d, %d)\n", cords.player_x, cords.player_y);
	ft_printf("Exit coordinates: (%d, %d)\n", cords.exit_x, cords.exit_y);
}
