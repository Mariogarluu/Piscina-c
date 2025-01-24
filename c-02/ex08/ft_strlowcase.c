/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:00:02 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/04 14:07:03 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_uppercase(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	ft_to_lower(char c)
{
	if (ft_is_uppercase(c))
		return (c + 32);
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_uppercase(str[i]))
			str[i] = ft_to_lower(str[i]);
		i++;
	}
	return (str);
}
