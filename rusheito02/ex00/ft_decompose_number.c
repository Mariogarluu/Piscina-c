/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decompose_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:54:14 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/13 13:54:16 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

void print_number_as_words(char *num_str, t_dict *dict, int dict_count);
void print_digit_word(char *number, t_dict *dict, int dict_count);

// Descompone un número y lo convierte en palabras usando el diccionario
void decompose_number(char *num_str, t_dict *dict, int dict_count)
{
    int len = ft_strlen(num_str);

    // Casos especiales para números de 1 o 2 dígitos
    if (len == 1 || (len == 2 && num_str[0] == '1'))
    {
        print_digit_word(num_str, dict, dict_count);  // Números menores de 20
        return;
    }

    // Si el número tiene más de 2 dígitos, descomponer según su longitud
    if (len == 2)
    {
        // Decenas + unidades
        char tens[3] = { num_str[0], '0', '\0' };  // Ejemplo: "45" -> "40"
        print_digit_word(tens, dict, dict_count);

        if (num_str[1] != '0')  // Si no es múltiplo de 10
            print_digit_word(&num_str[1], dict, dict_count);  // Unidades
    }
    else if (len == 3)
    {
        // Centenas
        char hundreds[2] = { num_str[0], '\0' };  // Ejemplo: "345" -> "300"
        print_digit_word(hundreds, dict, dict_count);
        write(1, " hundred ", 9);

        // Procesar los dos dígitos restantes
        decompose_number(&num_str[1], dict, dict_count);
    }
    else if (len > 3)
    {
        // Casos para miles, millones, etc.
        int leading_digits = len % 3 == 0 ? 3 : len % 3;  // 1-3 dígitos iniciales
        char leading[4];
        ft_strncpy(leading, num_str, leading_digits);
        leading[leading_digits] = '\0';

        decompose_number(leading, dict, dict_count);

        // Buscar el nombre adecuado (thousand, million, etc.)
        if (len > 3 && len <= 6)
            write(1, " thousand ", 10);
        else if (len > 6 && len <= 9)
            write(1, " million ", 9);
        // Puedes añadir más casos para billones, trillones, etc.

        // Descomponer el resto del número
        decompose_number(&num_str[leading_digits], dict, dict_count);
    }
}

// Imprime el número correspondiente a una cadena (ej. "40" o "5")
void print_digit_word(char *number, t_dict *dict, int dict_count)
{
    for (int i = 0; i < dict_count; i++)
    {
        if (ft_strcmp(dict[i].number, number) == 0)
        {
            write(1, dict[i].word, ft_strlen(dict[i].word));
            write(1, " ", 1);
            return;
        }
    }
}
