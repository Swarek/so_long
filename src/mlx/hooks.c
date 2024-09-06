/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:18:27 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 21:05:08 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	t_map	*map;
	t_vars	*vars;

	map = data->map;
	vars = data->vars;
	if (!vars || !map || !map->map)
		return (ft_error_msg("Error: Invalid pointers passed to key_hook\n"), 1);
	if (keycode == KEY_ESC)
	{
		if (vars->win && vars->mlx)
		{
			mlx_loop_end(vars->mlx);
			mlx_destroy_window(vars->mlx, vars->win);
			vars->win = NULL;
		}
		else
			return (ft_error_msg("Error: Window or mlx not initialized\n"), 1);
	}
	hook_movements(keycode, map->map);
	return (0);
}

void	hook_movements(int keycode, char **map)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		player_movement(map, TOP);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		player_movement(map, LEFT);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_movement(map, RIGHT);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		player_movement(map, BOTTOM);
}
