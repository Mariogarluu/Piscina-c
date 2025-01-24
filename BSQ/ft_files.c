/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:45:54 by ciespino          #+#    #+#             */
/*   Updated: 2024/10/16 20:43:26 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

long	ft_get_file_size(int fd)
{
	long	size;
	long	offset;

	offset = lseek(fd, 0, SEEK_END);
	if (offset == -1)
	{
		return (-1);
	}
	size = offset;
	lseek(fd, 0, SEEK_SET);
	return (size);
}

char	*ft_read_file_content(int fd, long size)
{
	char	*content;
	ssize_t	read_size;

	content = (char *)malloc((size + 1) * sizeof(char));
	if (content == NULL)
	{
		return (NULL);
	}
	read_size = read(fd, content, size);
	if (read_size == -1)
	{
		free(content);
		return (NULL);
	}
	content[read_size] = '\0';
	return (content);
}

char	*ft_read_file(const char *filename)
{
	int		fd;
	long	size;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	size = ft_get_file_size(fd);
	if (size == -1)
	{
		close(fd);
		return (NULL);
	}
	content = ft_read_file_content(fd, size);
	close(fd);
	return (content);
}

void	ft_print_file_content(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(1, map->map_data[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}
