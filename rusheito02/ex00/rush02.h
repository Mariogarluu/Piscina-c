/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:06:52 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/13 13:56:35 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
#define RUSH02_H

typedef struct s_dict
{
    char *number;
    char *word;
}   t_dict;

int     ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
char    *ft_strcpy(char *dest, char *src);
char    *ft_strdup(const char *src);
char    *ft_strtok(char *str, const char *delim);
int     ft_atoi(char *str);
void    convert_number(char *number, t_dict *dict, int count);
t_dict  *read_dictionary(const char *filename, int *count);
void    free_dictionary(t_dict *dict, int count);
char    *ft_strchr(const char *str, int c);
int     ft_atoi(char *str);
void    process_line(char *line, t_dict *dict_entry);
int     count_lines(const char *buffer);
void    decompose_number(char *num_str, t_dict *dict, int dict_count);
void    print_digit_word(char *number, t_dict *dict, int dict_count);
char    *ft_strncpy(char *dest, const char *src, int n);

#endif
