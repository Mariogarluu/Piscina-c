/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:58:59 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/16 20:40:07 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty_char;
	char	obstacle_char;
	char	full_char;
	char	**map_data;
}	t_map;

typedef struct s_square_info
{
	int	max_size;
	int	max_row;
	int	max_col;
}	t_square_info;

t_map	*ft_initialize_map(const char *file_content);
int		ft_validate_map(t_map *map);
void	ft_find_largest_square(t_map *map);
void	ft_print_file_content(t_map *map);
void	ft_free_map(t_map *map);
long	ft_get_file_size(int fd);
char	*ft_read_file(const char *filename);
char	*ft_read_file_content(int fd, long size);
int		ft_atoi(const char *str);
int		min(int a, int b);
int		min3(int a, int b, int c);
size_t	ft_strlen(const char *str);
char	*ft_read_from_stdin(void);
void	ft_process_map(char *content);
int		ft_handle_files(int argc, char **argv);
int		ft_handle_stdin(void);
int		ft_read_metadata(const char *file_content, int *i, t_map *map);
char	**ft_allocate_map_data(t_map *map);
void	ft_read_map_data(const char *file_content, int *i, t_map *map);
int		ft_read_map_row(const char *file_content, int *i, t_map *map, int row);
int		ft_validate_line(char *line, t_map *map);
void	ft_allocate_dp(int **dp, t_map *map);
void	ft_free_dp(int **dp, int rows);
void	ft_calculate_dp(t_map *map, int **dp, t_square_info *square_info);
void	ft_mark_largest_square(t_map *map, t_square_info *square_info);
void	ft_update_dp(t_map *map, int **dp, int k[], t_square_info *square_info);

#endif
