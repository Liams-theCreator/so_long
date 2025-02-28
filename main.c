/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:27:18 by imellali          #+#    #+#             */
/*   Updated: 2025/02/28 19:01:45 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_data;

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int key_handler(int key, t_data *data)
{
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
		return (0);
	}
	else if (key == 119 || key == 97 || key == 115 || key == 100)
		printf("KEY PRESSED : %c (keycode : %d)\n",key, key);
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (-1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Window");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (-1);
	}
	mlx_hook(data.win_ptr, DestroyNotify, 0, &close_window, &data);
	mlx_key_hook(data.win_ptr, &key_handler, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
