/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:19:05 by ciespino          #+#    #+#             */
/*   Updated: 2024/10/16 20:35:04 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_validate_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->rows <= 0 || map->cols <= 0)
		return (0);
	while (i < map->rows)
	{
		if (!map->map_data[i])
			return (0);
		if (!ft_validate_line(map->map_data[i], map))
			return (0);
		i++;
	}
	return (1);
}

int	ft_validate_line(char *line, t_map *map)
{
	size_t	line_length;
	size_t	j;

	line_length = ft_strlen(line);
	j = 0;
	if (line_length == 0)
		return (0);
	while (j < line_length)
	{
		if (line[j] != map->empty_char && line[j] != map->obstacle_char)
			return (0);
		j++;
	}
	return (1);
}
