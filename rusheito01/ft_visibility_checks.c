/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visibility_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:05:23 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/06 12:10:23 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_visible_from_top(int grid[4][4], int col, int expected)
{
	int	i;
	int	max_seen;
	int	visible_count;

	i = 0;
	max_seen = 0;
	visible_count = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_seen)
		{
			max_seen = grid[i][col];
			visible_count++;
		}
		i++;
	}
	return (visible_count == expected);
}

int	ft_visible_from_bottom(int grid[4][4], int col, int expected)
{
	int	i;
	int	max_seen;
	int	visible_count;

	i = 3;
	max_seen = 0;
	visible_count = 0;
	while (i >= 0)
	{
		if (grid[i][col] > max_seen)
		{
			max_seen = grid[i][col];
			visible_count++;
		}
		i--;
	}
	return (visible_count == expected);
}

int	ft_visible_from_left(int grid[4][4], int row, int expected)
{
	int	i;
	int	max_seen;
	int	visible_count;

	i = 0;
	max_seen = 0;
	visible_count = 0;
	while (i < 4)
	{
		if (grid[row][i] > max_seen)
		{
			max_seen = grid[row][i];
			visible_count++;
		}
		i++;
	}
	return (visible_count == expected);
}

int	ft_visible_from_right(int grid[4][4], int row, int expected)
{
	int	i;
	int	max_seen;
	int	visible_count;

	i = 3;
	max_seen = 0;
	visible_count = 0;
	while (i >= 0)
	{
		if (grid[row][i] > max_seen)
		{
			max_seen = grid[row][i];
			visible_count++;
		}
		i--;
	}
	return (visible_count == expected);
}

int	ft_visibility_checks(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((!ft_visible_from_top(grid, i, clues[i]))
			|| (!ft_visible_from_bottom(grid, i, clues[i + 4])))
			return (0);
		if ((!ft_visible_from_left(grid, i, clues[i + 8]))
			|| (!ft_visible_from_right(grid, i, clues[i + 12])))
			return (0);
		i++;
	}
	return (1);
}
