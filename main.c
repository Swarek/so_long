/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:07 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 21:10:43 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_vars *vars, t_map *map)
{
	if (vars->mlx)
	{
		if (vars->win)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			vars->win = NULL;
		}
		destroy_all_images(vars);
		mlx_loop_end(vars->mlx);
		mlx_destroy_display(vars->mlx);
		ft_safe_free((void **)&vars->mlx);
	}
	free_all_strings(map->map);
	ft_safe_free((void **)&map);
	ft_safe_free((void **)&vars);
}


int	main(void)
{
	int		fd;
	t_map	*map;
	t_vars	*vars;

	// Faire condition pour verifier le nom du fichier qui finit bien par .ber
	fd = open("maps/test.ber", O_RDONLY);
	map = doing_all(fd);
	if (map == NULL)
		return (close(fd), -1);
	close(fd);
	ft_print_array(map->map);
	vars = ft_safe_malloc(sizeof(t_vars));
	launch_mlx(vars, map);
	free_all(vars, map);
	return (0);
}
