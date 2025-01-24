/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:59:03 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/02 18:08:12 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_ultimate_div_mod(int *a, int *b)
{
    int div;
    int res;

    if (*b != 0)
	{
		div = *a / *b;
		res = *a % *b;
        *a = div;
        *b = res;
	}
}
