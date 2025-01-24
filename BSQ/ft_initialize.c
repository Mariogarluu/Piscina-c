/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inicialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:18:42 by ciespino          #+#    #+#             */
/*   Updated: 2024/10/16 20:34:41 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*ft_initialize_map(const char *file_content)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	i = ft_read_metadata(file_content, &i, map);
	if (i < 4)
	{
		free(map);
		return (NULL);
	}
	map->map_data = ft_allocate_map_data(map);
	if (!map->map_data)
	{
		free(map);
		return (NULL);
	}
	ft_read_map_data(file_content, &i, map);
	return (map);
}

int	ft_read_metadata(const char *file_content, int *i, t_map *map)
{
	while (file_content[*i] != '\n' && file_content[*i] != '\0')
		(*i)++;
	map->rows = ft_atoi(file_content);
	map->empty_char = file_content[*i - 3];
	map->obstacle_char = file_content[*i - 2];
	map->full_char = file_content[*i - 1];
	(*i)++;
	return (*i);
}

char	**ft_allocate_map_data(t_map *map)
{
	char	**data;

	data = (char **)malloc(map->rows * sizeof(char *));
	return (data);
}

void	ft_read_map_data(const char *file_content, int *i, t_map *map)
{
	int	row;

	row = 0;
	while (row < map->rows)
	{
		if (!ft_read_map_row(file_content, i, map, row))
		{
			ft_free_map(map);
			return ;
		}
		row++;
	}
}

int	ft_read_map_row(const char *file_content, int *i, t_map *map, int row)
{
	int	col;
	int	j;

	col = 0;
	j = 0;
	while (file_content[*i] != '\n' && file_content[*i] != '\0')
	{
		col++;
		(*i)++;
	}
	map->cols = col;
	map->map_data[row] = (char *)malloc((col + 1) * sizeof(char));
	if (!map->map_data[row])
	{
		return (0);
	}
	while (j < col)
	{
		map->map_data[row][j] = file_content[*i - col + j];
		j++;
	}
	map->map_data[row][col] = '\0';
	(*i)++;
	return (1);
}
