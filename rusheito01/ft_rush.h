/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:05:34 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/06 12:19:05 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <stdlib.h>

int		ft_parse_input(char *input, int *clues);
void	ft_rush_solver(int grid[4][4], int clues[16]);
void	ft_print_grid(int grid[4][4]);

int		ft_is_safe(int grid[4][4], int row, int col, int num);
int		ft_solve_grid(int grid[4][4], int clues[16], int row, int col);
int		ft_visibility_checks(int grid[4][4], int clues[16]);

int		ft_visible_from_top(int grid[4][4], int col, int expected);
int		ft_visible_from_bottom(int grid[4][4], int col, int expected);
int		ft_visible_from_left(int grid[4][4], int row, int expected);
int		ft_visible_from_right(int grid[4][4], int row, int expected);

#endif
