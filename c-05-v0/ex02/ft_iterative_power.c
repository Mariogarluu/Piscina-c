/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:40:45 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/11 14:52:29 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	tmp;

	if (power == 0)
		return (1);
	if (nb <= 0 || power < 0)
		return (0);
	i = 1;
	tmp = nb;
	while (i < power)
	{
		tmp *= nb;
		i++;
	}
	return (tmp);
}
