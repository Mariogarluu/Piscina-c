//cc -Wall -Wextra -Werror -o main main.c */*.c

#include <unistd.h>
#include <stdio.h>
#include "ej.h"

int main(void)
{
	int option = 0;
	int num = 0;
	int num2 = 0;
	int result;

	while (1)
	{
		printf("Seleccione una opción:\n");
		printf("0. Ex00\n");
		printf("1. Ex01\n");
		printf("2. Ex02\n");
		printf("3. Ex03\n");
		printf("4. Ex04\n");
		printf("5. Ex05\n");
		printf("6. Ex06\n");
		printf("7. Ex07\n");
		printf("8. Ex08\n");
		printf("9. Salir\n");
		printf("Ingrese su opción: ");
		scanf("%d", &option);

		switch (option)
		{
			case 0:
				printf("Ingrese un número para calcular el factorial: ");
				scanf("%d", &num);
				result = ft_iterative_factorial(num);
				printf("El factorial de %d es: %d\n", num, result);
				break;
			case 1:
				printf("Ingrese un número para calcular el factorial: ");
				scanf("%d", &num);
				result = ft_recursive_factorial(num);
				printf("El factorial de %d es: %d\n", num, result);
				break;
			case 2:
				printf("Ingrese un número para la potencia: ");
				scanf("%d", &num);
				printf("Ingrese un número que pontencia: ");
				scanf("%d", &num2);

				result = ft_iterative_power(num, num2);
				printf("La potencia es: %d\n", result);
				break;
			case 3:
				printf("Ingrese un número para la potencia: ");
				scanf("%d", &num);
				printf("Ingrese un número que pontencia: ");
				scanf("%d", &num2);
				result = ft_recursive_power(num, num2);
				printf("La potencia es: %d\n", result);
				break;
			case 4:
				printf("Ingrese el índice para calcular el número de Fibonacci: ");
				scanf("%d", &num);
				int result = ft_fibonacci(num);
				if (result == -1)
					printf("El índice debe ser un número no negativo.\n");
				else
					printf("El número de Fibonacci en el índice %d es: %d\n", num, result);
				break;
			case 5:
				printf("Ingrese un número para calcular su raíz cuadrada: ");
				scanf("%d", &num);
				result = ft_sqrt(num);
				if (result == 0)
					printf("El número %d no tiene una raíz cuadrada entera exacta.\n", num);
				else
					printf("La raíz cuadrada de %d es: %d\n", num, result);
				break;
			case 6:
				printf("Ingrese un número para verificar si es primo: ");
				scanf("%d", &num);
				if (ft_is_prime(num))
					printf("El número %d es primo.\n", num);
				else
					printf("El número %d no es primo.\n", num);
				break;
			case 7:
				printf("Ingrese un número para verificar si es primo o cual es el siguiente: ");
				scanf("%d", &num);
				result = ft_find_next_prime(num);
				printf("El número %d es primo.\n", result);
				break;
			case 8:
				result = ft_ten_queens_puzzle();
				printf("Número de soluciones encontradas: %d\n", result);
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
