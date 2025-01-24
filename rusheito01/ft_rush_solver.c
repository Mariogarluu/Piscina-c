/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:05:51 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/06 12:16:37 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"
#include <unistd.h>

void	ft_print_grid(int grid[4][4]);
int		ft_visibility_checks(int grid[4][4], int clues[16]);

int	ft_is_safe(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve_grid(int grid[4][4], int clues[16], int row, int col)
{
	int	num;

	if (row == 4)
		return (ft_visibility_checks(grid, clues));
	if (col == 4)
		return (ft_solve_grid(grid, clues, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (ft_is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (ft_solve_grid(grid, clues, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	ft_rush_solver(int grid[4][4], int clues[16])
{
	if (ft_solve_grid(grid, clues, 0, 0))
		ft_print_grid(grid);
	else
		write(1, "Error\n", 6);
}
