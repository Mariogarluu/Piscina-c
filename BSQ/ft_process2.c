/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:46:00 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/16 20:47:00 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_process_map(char *content)
{
	t_map	*map;

	map = ft_initialize_map(content);
	if (!map || !ft_validate_map(map))
	{
		write(1, "Error: map error\n", 18);
		if (map)
			ft_free_map(map);
		free(content);
		return ;
	}
	ft_find_largest_square(map);
	ft_print_file_content(map);
	ft_free_map(map);
	free(content);
}

void	ft_update_dp(t_map *map, int **dp, int k[], t_square_info *square_info)
{
	int	i;
	int	j;

	i = k[0];
	j = k[1];
	if (map->map_data[i][j] == map->empty_char)
	{
		if (i == 0 || j == 0)
			dp[i][j] = 1;
		else
			dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
		if (dp[i][j] > square_info->max_size)
		{
			square_info->max_size = dp[i][j];
			square_info->max_row = i;
			square_info->max_col = j;
		}
	}
	else
		dp[i][j] = 0;
}
