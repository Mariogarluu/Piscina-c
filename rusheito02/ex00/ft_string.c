/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:40:32 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/13 13:55:56 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "rush02.h"

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

char *ft_strdup(const char *src)
{
    int len = ft_strlen((char *)src);
    char *dup;
    int i = 0;

    dup = malloc(len + 1);
    if (!dup)
        return 0;

    while (i < len)
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';

    return dup;
}

char *ft_strtok(char *str, const char *delim)
{
    static char *input = 0;
    char *result;

    if (str != 0)
        input = str;

    if (input == 0 || *input == '\0')
        return 0;

    // Ignorar delimitadores al inicio
    while (*input && ft_strchr(delim, *input))
        input++;

    if (*input == '\0')  // Si solo hay delimitadores al final
        return 0;

    result = input;  // Inicio del token

    // Avanzar hasta el siguiente delimitador
    while (*input && !ft_strchr(delim, *input))
        input++;

    if (*input != '\0')
    {
        *input = '\0';
        input++;
    }

    return result;
}

// Busca el primer carácter 'c' en la cadena 'str'
char *ft_strchr(const char *str, int c)
{
    while (*str)
    {
        if (*str == (char)c)
            return (char *)str;
        str++;
    }
    if (c == '\0')
        return (char *)str;
    return 0;
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;

	// Ignorar espacios en blanco
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	// Manejar el signo
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// Convertir los caracteres numéricos a enteros
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char *ft_strncpy(char *dest, const char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];  // Copiar caracter de src a dest
    }
    // Si hemos copiado menos de n caracteres, asegurarnos que dest termina en '\0'
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return dest;
}

