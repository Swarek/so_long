/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:02:21 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 19:42:28 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# define TOP 			-1
# define BOTTOM 		1
# define LEFT 			-2
# define RIGHT 			2
# define SUCCESS 		0
# define WINDOW_WIDTH 	1920
# define WINDOW_HEIGHT 	1080
# define RED_PIXEL 		0xFF0000
# define GREEN_PIXEL 	0xFF00
# define WHITE_PIXEL 	0xFFFFFF
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_ESC		65307
# define KEY_SPACE		32
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_RIGHT		65363
# define KEY_LEFT		65361

typedef struct elements
{
	int	empty;
	int	wall;
	int	collectible;
	int	map_exit;
	int	starting_pos;
}	t_elements;

typedef struct s_vars
{
	void	*mlx;
	void	*win;

	void	*front;
	void	*left;
	void	*right;
	void	*back;

	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*toprint;

	int		img_width;
	int		img_height;
}	t_vars;
typedef struct s_image_info
{
	int	bpp;
	int	size_line;
	int	endian;
}	t_image_info;

typedef struct s_point
{
	int	x;
	int	y;
	int	pixel;
}	t_point;

typedef struct s_map
{
	char	**map;
	int		length;
	int		width;
}	t_map;

typedef struct s_data
{
	t_vars	*vars;
	t_map	*map;
}	t_data;

int		elems_on_the_line(t_list *map, t_elements *count_elems);
t_list	*get_map(int fd);
void	printmap(char **tab);
t_map	*parse_the_map(t_list *map, t_elements *count_elems);
char	**convertmap_chain_in_tabtab(t_list *map);
void	flood_fill(char **map, int row, int col);
int		verif_flood(char **flooded);
int		ft_strlen_2d(char **map);
char	**array_strcpy(char **src);
int		where_start_flood(char **map);
t_map	*doing_all(int fd);
void	flood_fill_for_exit(char **map, int row, int col);
int		verif_flood_for_exit(char **flooded);
int		map_closed(t_list *map);
int		player_movement(char **map, int direction);
int		key_hook(int keycode, t_data *data);
int		start_open_window(t_vars *vars);
int		mlx_looping(t_data *data);
int		launch_mlx(t_vars *vars, t_map *map);
int		set_img(t_vars *data);
int		draw_map(t_vars *vars, t_map *map);
void	hook_movements(int keycode, char **map);

#endif