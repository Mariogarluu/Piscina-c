/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:41:03 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/13 14:12:48 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "rush02.h"

t_dict *read_dictionary(const char *filename, int *count)
{
    int fd;
    char *buffer;
    int file_size;
    int i = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        return (0);
    }

    // Obtener tamaño del archivo
    file_size = lseek(fd, 0, SEEK_END);
    if (file_size <= 0)
    {
        write(1, "Error: Empty dictionary\n", 24);
        close(fd);
        return (0);
    }
    lseek(fd, 0, SEEK_SET);

    // Asignar memoria para el buffer
    buffer = malloc(file_size + 1);
    if (!buffer)
    {
        write(1, "Error: Memory allocation failed\n", 33);
        close(fd);
        return (0);
    }

    // Leer el archivo
    if (read(fd, buffer, file_size) < 0)
    {
        free(buffer);
        close(fd);
        write(1, "Error: Failed to read dictionary\n", 34);
        return (0);
    }
    buffer[file_size] = '\0';  // Asegúrate de terminar el buffer con '\0'

    // Contar líneas
    *count = count_lines(buffer);
    if (*count == 0)
    {
        free(buffer);
        write(1, "Error: No entries found in dictionary\n", 38);
        return (0);
    }

    // Reservar memoria para el diccionario
    t_dict *dict = malloc((*count) * sizeof(t_dict));
    if (!dict)
    {
        free(buffer);
        write(1, "Error: Memory allocation failed for dictionary\n", 46);
        return (0);
    }

    // Procesar el buffer línea por línea
    char *line = ft_strtok(buffer, "\n");
    while (line && i < *count)
    {
        process_line(line, &dict[i]);  // Procesar la línea y llenar dict
        line = ft_strtok(0, "\n");
        i++;
    }

    free(buffer);  // Liberar el buffer
    close(fd);     // Cerrar el archivo
    return dict;   // Devolver el diccionario
}

void process_line(char *line, t_dict *dict_entry)
{
    char *number = ft_strtok(line, ":");
    char *word = ft_strtok(0, "\n");

    if (number && word)
    {
        dict_entry->number = ft_strdup(number);
        dict_entry->word = ft_strdup(word);
    }
}

// Cuenta las líneas del buffer para calcular el número de entradas del diccionario
int count_lines(const char *buffer)
{
    int lines = 0;
    int i = 0;

    while (buffer[i])
    {
        if (buffer[i] == '\n')
            lines++;
        i++;
    }
    return lines;
}

void free_dictionary(t_dict *dict, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(dict[i].number);
        free(dict[i].word);
    }
    free(dict);
}
