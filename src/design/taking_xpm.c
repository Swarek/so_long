/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:37:31 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 21:12:02 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	set_img(t_data *data)
// {
// 	data->img.height = 80;
// 	data->img.width = 80;
// 	data->img.floor = "./img/floor_texture.xpm";
// 	data->img.wall = "./img/wall_texture.xpm";
// 	data->img.collect = "./img/collect.xpm";
// 	data->img.player = "./img/zelda.xpm";
// 	data->img.exit = "./img/exit_texture.xpm";
// 	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
// 			&(data->img.width), &(data->img.height));
// 	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
// 			&(data->img.width), &(data->img.height));
// 	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
// 			&(data->img.width), &(data->img.height));
// 	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->img.collect, &(data->img.width), &(data->img.height));
// 	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->img.player, &(data->img.width), &(data->img.height));
// }

void	destroy_all_images(t_vars *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->front)
		mlx_destroy_image(data->mlx, data->front);
}

int	set_img(t_vars *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall_texture.xpm",
			&data->img_width, &data->img_height);
	if (!data->wall)
		return (destroy_all_images(data), 1);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./img/floor_texture.xpm",
			&data->img_width, &data->img_height);
	if (!data->floor)
		return (destroy_all_images(data), 1);
	data->front = mlx_xpm_file_to_image(data->mlx, "./img/front.xpm",
			&data->img_width, &data->img_height);
	if (!data->front)
		return (destroy_all_images(data), 1);
	return (0);
}
