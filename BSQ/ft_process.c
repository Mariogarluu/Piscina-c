/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:19:23 by ciespino          #+#    #+#             */
/*   Updated: 2024/10/16 20:45:57 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_find_largest_square(t_map *map)
{
	int				**dp;
	t_square_info	square_info;

	dp = (int **)malloc(map->rows * sizeof(int *));
	ft_allocate_dp(dp, map);
	square_info.max_size = 0;
	square_info.max_row = 0;
	square_info.max_col = 0;
	ft_calculate_dp(map, dp, &square_info);
	ft_mark_largest_square(map, &square_info);
	ft_free_dp(dp, map->rows);
}

void	ft_mark_largest_square(t_map *map, t_square_info *square_info)
{
	int	i;
	int	j;

	i = square_info->max_row;
	j = square_info->max_col;
	while (i > square_info->max_row - square_info->max_size)
	{
		j = square_info->max_col;
		while (j > square_info->max_col - square_info->max_size)
		{
			map->map_data[i][j] = map->full_char;
			j--;
		}
		i--;
	}
}

void	ft_allocate_dp(int **dp, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		dp[i] = (int *)malloc(map->cols * sizeof(int));
		i++;
	}
}

void	ft_free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

void	ft_calculate_dp(t_map *map, int **dp, t_square_info *square_info)
{
	int	i[2];

	i[0] = 0;
	while (i[0] < map->rows)
	{
		i[1] = 0;
		while (i[1] < map->cols)
		{
			ft_update_dp(map, dp, i, square_info);
			i[1]++;
		}
		i[0]++;
	}
}
