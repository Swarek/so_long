/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:28:37 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 18:36:19 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	where_start_flood(char **map)
{
	int		row;
	int		col;
	int		result;
	char	**cpy_map;

	row = 0;
	col = 0;
	cpy_map = array_strcpy(map);
	searching_char(map, 'P', &row, &col);
	flood_fill(cpy_map, row, col);
	result = verif_flood(cpy_map);
	if (result == -1)
		return (free_all_strings(cpy_map), -1);
	flood_fill_for_exit(cpy_map, row, col);
	result = verif_flood_for_exit(cpy_map);
	ft_2dclear(cpy_map);
	return (result);
}

void	flood_fill(char **map, int row, int col)
{
	if(row < 0 || row > ft_strlen_2d(map) || col < 0 || col > (int)ft_strlen(map[0]))
		return ;
	if (map[row][col] == '0' || map[row][col] == 'C' || map[row][col] == 'P')
	{
		map[row][col] = '2';
		flood_fill(map, row - 1, col);
		flood_fill(map, row + 1, col);
		flood_fill(map, row, col - 1);
		flood_fill(map, row, col + 1);
	}
}

int	verif_flood(char **flooded)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (flooded[i] != NULL)
	{
		while (flooded[i][j] != '\0')
		{
			if (flooded[i][j] == '0' || flooded[i][j] == 'C'
				|| flooded[i][j] == 'P')
				return (ft_error_msg("Intouchable empty"), -1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void	flood_fill_for_exit(char **map, int row, int col)
{
	if (row < 0 || row > ft_strlen_2d(map) || col < 0
		|| col > (int)ft_strlen(map[0]))
		return ;
	if (map[row][col] == '2' || map[row][col] == 'E')
	{
		map[row][col] = '3';
		flood_fill_for_exit(map, row - 1, col);
		flood_fill_for_exit(map, row + 1, col);
		flood_fill_for_exit(map, row, col - 1);
		flood_fill_for_exit(map, row, col + 1);
	}
}

int	verif_flood_for_exit(char **flooded)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (flooded[i] != NULL)
	{
		while (flooded[i][j] != '\0')
		{
			if (flooded[i][j] == '0' || flooded[i][j] == 'C'
				|| flooded[i][j] == 'P' || flooded[i][j] == 'E')
				return (ft_error_msg("Player can't join exit"), -1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
