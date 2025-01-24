//cc -Wall -Wextra -Werror -o main main.c */*.c

#include <unistd.h>
#include <stdio.h>
#include "ej.h"

int main(void)
{
	int option;
	char str[100];
	char str1[100];
	int num;

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
				printf("Introduce una cadena: ");
				scanf("%99s", str);
				printf("La longitud de la cadena es: %d\n", ft_strlen(str));
				break;
			case 1:
				printf("Introduce una cadena: ");
				scanf("%99s", str);
				printf("La cadena mostrada por write \n");
				ft_putstr(str);
				printf("\n");
				break;
			case 2:
				printf("Ingrese un número para imprimir: ");
				scanf("%d", &num);
				ft_putnbr(num);
				write(1, "\n", 1);
				break;
			case 3:
				printf("Ingrese una cadena para convertir a entero: ");
				scanf("%s", str);
				int result_atoi = ft_atoi(str);
				printf("Resultado de ft_atoi: ");
				ft_putnbr(result_atoi);
				write(1, "\n", 1);
				break;
			case 4:
				printf("Ingrese un número: ");
				scanf("%d", &num);
				printf("Ingrese la base: ");
				scanf("%s", str);
				ft_putnbr_base(num, str);
				write(1, "\n", 1);
				break;
			case 5:
				printf("Ingrese una cadena para convertir a entero: ");
				scanf("%s", str);
				printf("Ingrese la base: ");
				scanf("%s", str1);
				int result_atoi_base = ft_atoi_base(str, str1);
				printf("Resultado de ft_atoi_base: %d\n", result_atoi_base);
				break;
			case 9:
				printf("Saliendo...\n");
				return (0);
			default:
				printf("Opción no válida, intente de nuevo.\n");
		}
	}
	return (0);
}
