/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblanc <mblanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:34:24 by mblanc            #+#    #+#             */
/*   Updated: 2024/09/03 17:50:30 by mblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen_2d(char **map)
{
	int len;
	
	len = 0;
	while (map[len] != NULL)
		len++;
	return (len);
}

char **array_strcpy(char **src)
{
	size_t	i;
	char	**dest;
	
	i = 0;
	dest = malloc((ft_strlen_2d(src) + 1)* sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (src[i] != NULL)
	{
		dest[i] = malloc((ft_strlen(src[i]) + 1) * sizeof(char));
		if (dest[i] == NULL)
		{
			while(i > 0)
				free(dest[--i]);
			free(dest[i]);
			return (NULL);
		}
		ft_strcpy(dest[i], src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
