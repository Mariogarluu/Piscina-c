/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:47:21 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/06 13:08:42 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_rush_solver(int grid[4][4], int clues[16]);

int	ft_parse_input(char *input, int *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= '1' && input[i] <= '4')
		{
			clues[j] = input[i] - '0';
			j++;
		}
		else if (input[i] != ' ')
			return (0);
		i++;
	}
	return (j == 16);
}

void	ft_inicializar_grid(int (*grid)[4])
{
	grid[0][0] = 0;
	grid[0][1] = 0;
	grid[0][2] = 0;
	grid[0][3] = 0;
	grid[1][0] = 0;
	grid[1][1] = 0;
	grid[1][2] = 0;
	grid[1][3] = 0;
	grid[2][0] = 0;
	grid[2][1] = 0;
	grid[2][2] = 0;
	grid[2][3] = 0;
	grid[3][0] = 0;
	grid[3][1] = 0;
	grid[3][2] = 0;
	grid[3][3] = 0;
}

int	main(int argc, char **argv)
{
	int	clues[16];
	int	(*grid)[4];

	grid = malloc(4 * sizeof(*grid));
	if (!grid)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_inicializar_grid(grid);
	if (argc != 2 || !ft_parse_input(argv[1], clues))
	{
		write(1, "Error\n", 6);
		free(grid);
		return (1);
	}
	ft_rush_solver(grid, clues);
	free(grid);
	return (0);
}
