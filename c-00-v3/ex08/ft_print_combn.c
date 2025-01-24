/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:17:48 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/02 17:07:28 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
	if (arr[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_recursive_combn(int *arr, int n, int index, int current)
{
	int	i;

	if (index == n)
	{
		ft_print_number(arr, n);
		return ;
	}
	i = current;
	while (i <= 9)
	{
		arr[index] = i;
		ft_recursive_combn(arr, n, index + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n > 0 && n < 10)
		ft_recursive_combn(arr, n, 0, 0);
}
