/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:12:06 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/07 09:38:12 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_lowercase(char c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

char	ft_to_upper(char c)
{
	if (ft_is_lowercase(c))
		return (c - 32);
	return (c);
}

int	ft_is_separator(char c)
{
	if ((c >= 32 && c <= 47)
		|| (c >= 58 && c <= 64)
		|| (c >= 91 && c <= 96)
		|| (c >= 123 && c <= 126))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || ft_is_separator(str[i - 1]))
			if (ft_is_lowercase(str[i]))
				str[i] = ft_to_upper(str[i]);
		i++;
	}
	return (str);
}
