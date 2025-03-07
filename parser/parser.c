/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:45:37 by imellali          #+#    #+#             */
/*   Updated: 2025/03/06 19:57:09 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (check_text(map, height) == -1)
		throw_error(map, "Putting invalid element");
	if (check_rectangle(map, height) == -1)
		throw_error(map, "Map is not rectangle");
	if (check_walls(map, height, ft_strlen(map[0])) == -1)
		throw_error(map, "Map is not rounded by Walls");
	if (check_map(map, height) == -1)
		throw_error(map, "Map is not playable");
	init_and_store(map, height, &elems, &cords);
	if (check_path(map, height, &cords, &elems) == -1)
		throw_error(map, "Invalid path");
	store_elems(map, height, &elems);
	start_game(map, height, &cords, &elems);
	free_array(map);
	return (0);
}
