/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioga2 <marioga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:58:06 by marioga2          #+#    #+#             */
/*   Updated: 2024/10/07 12:40:14 by marioga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cc -Wall -Wextra -Werror -o main main.c */*.c

#include <stdio.h>
#include "ej.h"

int	ft_strcmp(char *s1, char *s2);

int main(void)
{
    int option;
	char str1[100];
	char str2[100];
    unsigned int n;
	int result;
    char *substring;

	while (1)
	{
		printf("Seleccione una opción:\n");
		printf("0. Ex00\n");
        printf("1. Ex01\n");
        printf("2. Ex02\n");
        printf("3. Ex03\n");
        printf("4. Ex04\n");
        printf("5. Ex05\n");
		printf("9. Salir\n");
		printf("Ingrese su opción: ");
		scanf("%d", &option);

		switch (option)
		{
			case 0:
				printf("Ingrese la primera cadena: ");
				scanf("%s", str1);
				printf("Ingrese la segunda cadena: ");
				scanf("%s", str2);
				result = ft_strcmp(str1, str2);
				if (result == 0)
					printf("Las cadenas son iguales.\n");
				else if (result < 0)
					printf("La primera cadena es menor que la segunda.\n");
				else
					printf("La primera cadena es mayor que la segunda.\n");

				break;
            case 1:
				printf("Ingrese la primera cadena: ");
				scanf("%s", str1);
				printf("Ingrese la segunda cadena: ");
				scanf("%s", str2);
				printf("Ingrese el número de caracteres a comparar (n): ");
				scanf("%u", &n);
				result = ft_strncmp(str1, str2, n);
				if (result == 0)
					printf("Las cadenas son iguales en los primeros %u caracteres.\n", n);
				else if (result < 0)
					printf("La primera cadena es menor que la segunda en los primeros %u caracteres.\n", n);
				else
					printf("La primera cadena es mayor que la segunda en los primeros %u caracteres.\n", n);
				break;
            case 2:
				printf("Ingrese la primera cadena (dest): ");
				scanf("%s", str1);
				printf("Ingrese la segunda cadena (src): ");
				scanf("%s", str2);
				ft_strcat(str1, str2);
				printf("Resultado de la concatenación: %s\n", str1);
				break;
            case 3:
				printf("Ingrese la primera cadena (dest): ");
				scanf("%s", str1);
				printf("Ingrese la segunda cadena (src): ");
				scanf("%s", str2);
				printf("Ingrese el número de caracteres de src a concatenar (n): ");
				scanf("%u", &n);
				ft_strncat(str1, str2, n);
				printf("Resultado de la concatenación: %s\n", str1);
				break;
            case 4:
				printf("Ingrese la cadena donde buscar: ");
				scanf("%s", str1);
				printf("Ingrese la subcadena a buscar: ");
				scanf("%s", str2);
				substring = ft_strstr(str1, str2);
				if (substring != NULL)
					printf("Subcadena encontrada: %s\n", substring);
				else
					printf("Subcadena no encontrada.\n");
				break;
            case 5:
				printf("Ingrese la cadena de destino (dest): ");
				scanf("%s", str1);
				printf("Ingrese la cadena fuente (src): ");
				scanf("%s", str2);
				
				printf("Ingrese el tamaño total del buffer (size): ");
				scanf("%u", &n);

				unsigned int result_strlcat = ft_strlcat(str1, str2, n);

				printf("Resultado de la concatenación: %s\n", str1);
				printf("Longitud total esperada: %u\n", result_strlcat);
				break;
			case 9:
				printf("Saliendo...\n");
				return (0);
			default:
				printf("Opción no válida, intente de nuevo.\n");
		}
	}
}