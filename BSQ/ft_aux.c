/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciespino <ciespino@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:52:47 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/17 13:27:27 by ciespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

int	min3(int a, int b, int c)
{
	return (min(min(a, b), c));
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_handle_stdin(void)
{
	char	*file_content;

	file_content = ft_read_from_stdin();
	if (!file_content)
	{
		write(1, "Error: Could not read from stdin\n", 33);
		return ((1));
	}
	write(1, "\n", 1);
	ft_process_map(file_content);
	return (0);
}

int	ft_handle_files(int argc, char **argv)
{
	int		i;
	char	*file_content;

	i = 1;
	while (i < argc)
	{
		file_content = ft_read_file(argv[i]);
		if (!file_content)
		{
			write(1, "Error: Could not read file\n", 27);
			i++;
			continue ;
		}
		ft_process_map(file_content);
		i++;
	}
	return (0);
}
