/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:02:00 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 22:29:37 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_movement(char **map, int direction)
{
	int	row;
	int	col;

	searching_char(map, 'P', &row, &col);
	if (direction == TOP || direction == BOTTOM)
	{
		if (map[row + direction][col] != '0')
			return (-1);
		map[row][col] = '0';
		map[row + direction][col] = 'P';
	}
	if (direction == LEFT || direction == RIGHT)
	{
		if (map[row][col + direction / 2] != '0')
			return (-1);
		map[row][col] = '0';
		map[row][col + direction / 2] = 'P';
	}
	return (0);
}
