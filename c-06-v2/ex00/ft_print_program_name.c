/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:47:16 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/15 11:17:00 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *ch)
{
	int	i;

	i = 0;
	while (ch[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	next;

	next = '\n';
	i = 0;
	argc = ft_len(argv[i]);
	write(1, argv[i], argc);
	write(1, &next, 1);
	i++;
	return (0);
}
