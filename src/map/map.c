/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:03:24 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/06 18:06:45 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*get_map(int fd)
{
	t_list			*head;
	t_list			*current;
	char			*verif;

	head = ft_lstnew(get_next_line(fd));
	current = head;
	verif = get_next_line(fd);
	if (!verif)
	{
		ft_lstclear(&head);
		return (ft_error_msg("Problem getting the map"), NULL);
	}
	while (verif != NULL)
	{
		current->next = ft_lstnew(verif);
		if (!current->next)
		{
			free(verif);
			ft_lstclear(&head);
			return (NULL);
		}
		current = current->next;
		verif = get_next_line(fd);
	}
	return (head);
}

char	**convertmap_chain_in_tabtab(t_list *map)
{
	char	**tab;
	int		len;
	int		i;

	len = ft_lstsize(map);
	tab = malloc((len + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (map != NULL)
	{
		tab[i] = malloc((ft_strlen(map->content) + 1) * sizeof(char));
		if (!tab[i])
			return (free_array_iter_error(tab, i), NULL);
		ft_strcpy(tab[i++], map->content);
		map = map->next;
	}
	tab[i] = NULL;
	return (tab);
}

t_map	*clean_everything(t_elements *elements, t_list **map, char **newmap)
{
	if (newmap)
		free_all_strings(newmap);
	ft_lstclear(map);
	free(elements);
	return (NULL);
}

t_map	*doing_all(int fd)
{
	t_list		*map;
	t_elements	*elements;
	t_map		*final_map;

	elements = ft_safe_malloc(sizeof(t_elements));
	ft_memset(elements, 0, sizeof(t_elements));
	map = get_map(fd);
	if (!map)
		return (clean_everything(elements, &map, NULL));
	ft_lstmap_inplace(map, &remove_newline);
	final_map = parse_the_map(map, elements);
	if (final_map == NULL)
		return (clean_everything(elements, &map, NULL));
	final_map->map = convertmap_chain_in_tabtab(map);
	if (where_start_flood(final_map->map) == -1)
		return (clean_everything(elements, &map, final_map->map));
	if (map_closed(map) == -1)
		return (clean_everything(elements, &map, final_map->map));
	clean_everything(elements, &map, NULL);
	return (final_map);
}
