/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:53:26 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/04 13:20:28 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_uppercase(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_is_uppercase(str[i]))
			return (0);
		i++;
	}
	return (1);
}
