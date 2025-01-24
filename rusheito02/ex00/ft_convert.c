/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:39:34 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/13 14:07:32 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>
#include <unistd.h>

void convert_number(char *number_str, t_dict *dict, int dict_count)
{
    // Validar que el número solo contenga dígitos
    for (int i = 0; number_str[i] != '\0'; i++)
    {
        if (number_str[i] < '0' || number_str[i] > '9')
        {
            write(1, "Error: Invalid number format\n", 30);
            return;
        }
    }

    // Llamar a la función que descompone el número
    decompose_number(number_str, dict, dict_count);
}
