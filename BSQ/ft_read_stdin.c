/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciespino <ciespino@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:06:35 by ciespino          #+#    #+#             */
/*   Updated: 2024/10/17 13:13:14 by ciespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUFFER_SIZE 4096

char	*ft_append_content(char *fl_cnt,
							const char *buffer,
							int bytes_rd,
							int *total_size)
{
	int		i;
	char	*new_content;

	*total_size += bytes_rd;
	new_content = (char *)malloc(*total_size + 1);
	if (!new_content)
	{
		write(1, "Memory allocation error\n", 24);
		exit(1);
	}
	i = 0;
	while (i < *total_size - bytes_rd)
	{
		new_content[i] = fl_cnt[i];
		i++;
	}
	free(fl_cnt);
	i = 0;
	while (i < bytes_rd)
	{
		new_content[*total_size - bytes_rd + i] = buffer[i];
		i++;
	}
	new_content[*total_size] = '\0';
	return (new_content);
}

char	*ft_read_from_stdin(void)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_rd;
	char	*fl_cnt;
	int		total_size;

	fl_cnt = (char *)malloc(1);
	fl_cnt[0] = '\0';
	total_size = 0;
	while (1)
	{
		bytes_rd = read(0, buffer, BUFFER_SIZE);
		if (bytes_rd <= 0)
			break ;
		buffer[bytes_rd] = '\0';
		fl_cnt = ft_append_content(fl_cnt, buffer, bytes_rd, &total_size);
	}
	return (fl_cnt);
}
