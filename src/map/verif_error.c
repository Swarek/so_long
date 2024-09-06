/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:37:07 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 17:52:06 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	only_ones(char *str)
{
	if (!str || *str == '\0')
		return (-1);
	while (*str)
	{
		if (*str != '1')
			return (-1);
		str++;
	}
	return (0);
}

int	first_end_ones(char *str)
{
	if (!str || *str == '\0')
		return (-1);
	if (*str != '1')
		return (-1);
	while (*str)
		str++;
	str--;
	if (*str != '1')
		return (-1);
	return (0);
}

int	map_closed(t_list *map)
{
	if (only_ones(map->content) == -1)
		return (ft_error_msg("Map not closed"), -1);
	while (map->next != NULL)
	{
		if (first_end_ones(map->content) == -1)
			return (ft_error_msg("Map not closed"), -1);
		map = map->next;
	}
	if (only_ones(map->content) == -1)
		return (ft_error_msg("Map not closed"), -1);
	return (0);
}

int	elems_on_the_line(t_list *map, t_elements *count_elems)
{
	int		i;
	char	*line;

	i = 0;
	line = (char *)map->content;
	while (line[i] != '\0')
	{
		if (line[i] == '0')
			count_elems->empty++;
		else if (line[i] == '1')
			count_elems->wall++;
		else if (line[i] == 'C')
			count_elems->collectible++;
		else if (line[i] == 'E')
			count_elems->map_exit++;
		else if (line[i] == 'P')
			count_elems->starting_pos++;
		else
			return (-1);
		i++;
	}
	return (1);
}

t_map	*parse_the_map(t_list *map, t_elements *count_elems)
{
	t_map	*data_map;

	data_map = ft_safe_malloc(sizeof(t_map));
	data_map->length = ft_strlen(map->content);
	data_map->width = 0;
	while (map != NULL)
	{
		if (data_map->length != (int)ft_strlen(map->content))
			return (ft_error_msg("Not rectangular / Too much newlines"), NULL);
		if (elems_on_the_line(map, count_elems) == -1)
			return (ft_error_msg("Not good count of elems"), NULL);
		map = map->next;
		data_map->width++;
	}
	if (count_elems->starting_pos != 1 || count_elems->map_exit != 1
		|| count_elems->collectible == 0)
		return (ft_printf("Problem elements count on map"), NULL);
	return (data_map);
}
