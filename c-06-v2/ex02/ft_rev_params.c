/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:03:07 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/15 11:16:02 by marioga2         ###   ########.fr       */
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
	int		arg_len;

	next = '\n';
	i = argc;
	while (i-- > 1)
	{
		arg_len = ft_len(argv[i]);
		write(1, argv[i], arg_len);
		write(1, &next, 1);
	}
	return (0);
}
