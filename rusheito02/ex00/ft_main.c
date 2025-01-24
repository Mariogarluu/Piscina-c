/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:45:02 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/13 14:06:46 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

int main(int argc, char *argv[])
{
    t_dict *dictionary;
    int dict_count = 0;

    // Verificar el número de argumentos
    if (argc != 3)
    {
        write(1, "Error\n", 6);
        return (1);
    }

    // Leer el diccionario desde el archivo
    dictionary = read_dictionary(argv[1], &dict_count);
    if (!dictionary)
    {
        write(1, "Dict Error\n", 11);
        return (1);
    }

    // Convertir el número y manejar la salida
    convert_number(argv[2], dictionary, dict_count);

    // Liberar memoria del diccionario
    free_dictionary(dictionary, dict_count);
    return (0);
}

