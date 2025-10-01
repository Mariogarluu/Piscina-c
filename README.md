# 🏊 Piscina C - 42 Málaga

Este repositorio contiene todas las soluciones y proyectos completados durante la Piscina de C en 42 Málaga. La Piscina es un bootcamp intensivo de programación en C que dura aproximadamente un mes y cubre desde los fundamentos básicos hasta conceptos avanzados.

## 📋 Tabla de Contenidos

- [Descripción](#descripción)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Módulos de C](#módulos-de-c)
- [Proyectos Rush](#proyectos-rush)
- [Shell](#shell)
- [Compilación y Uso](#compilación-y-uso)
- [Autor](#autor)

## 📖 Descripción

La Piscina de C es un programa intensivo de 42 que introduce a los estudiantes al mundo de la programación en C. Durante este período, los estudiantes trabajan en ejercicios diarios (módulos C), proyectos en equipo (Rush) y ejercicios de shell.

## 🗂️ Estructura del Proyecto

```
Piscina-c/
├── c-00-v3/          # Módulo C00: Fundamentos básicos
├── c-01/             # Módulo C01: Punteros y bucles
├── c-02/             # Módulo C02: Strings y arrays
├── c-03-v2/          # Módulo C03: Funciones de string
├── c-04/             # Módulo C04: Conversiones y manipulación
├── c-05/             # Módulo C05: Recursión
├── c-06-v2/          # Módulo C06: Argumentos de línea de comandos
├── c-07/             # Módulo C07: Asignación dinámica de memoria
├── shell00-v5/       # Ejercicios de Shell
├── rusheito01/       # Rush 01: Puzzle de visibilidad
├── rusheito02/       # Rush 02: Diccionario de números
└── BSQ/              # Big Square Finder
```

## 💻 Módulos de C

### C00 - Fundamentos Básicos
Introducción a las funciones básicas y salida en C.
- `ex00`: ft_putchar - Imprime un carácter
- `ex01`: ft_print_alphabet - Imprime el alfabeto
- `ex02`: ft_print_reverse_alphabet - Imprime el alfabeto inverso
- `ex03`: ft_print_numbers - Imprime números del 0-9
- `ex04`: ft_is_negative - Determina si un número es negativo
- `ex05`: ft_print_comb - Imprime combinaciones de 3 dígitos
- `ex06`: ft_print_comb2 - Imprime combinaciones de 2 números
- `ex07`: ft_putnbr - Imprime un número entero
- `ex08`: ft_print_combn - Imprime combinaciones de n dígitos

### C01 - Punteros
Trabajo con punteros y manipulación de memoria.
- Operaciones básicas con punteros
- Intercambio de valores
- División y resto
- Funciones de ordenamiento

### C02 - Strings
Manipulación de cadenas de caracteres.
- Copia de strings
- Capitalización
- Conversiones de mayúsculas/minúsculas
- Impresión de memoria

### C03 - Funciones de String
Implementación de funciones estándar de string.
- strcmp, strncmp
- strcat, strncat
- strstr

### C04 - Conversiones
Funciones de conversión y salida.
- `ft_strlen` - Calcula la longitud de un string
- `ft_putstr` - Imprime un string
- `ft_putnbr` - Imprime un número
- `ft_atoi` - Convierte string a entero
- `ft_putnbr_base` - Imprime número en base específica
- `ft_atoi_base` - Convierte string a entero en base específica

**Compilación del módulo:**
```bash
cd c-04
cc -Wall -Wextra -Werror -o main main.c */*.c
./main
```

### C05 - Recursión
Implementación de funciones recursivas.
- `ft_iterative_factorial` - Factorial iterativo
- `ft_recursive_factorial` - Factorial recursivo
- `ft_iterative_power` - Potencia iterativa
- `ft_recursive_power` - Potencia recursiva
- `ft_fibonacci` - Secuencia de Fibonacci
- `ft_sqrt` - Raíz cuadrada
- `ft_is_prime` - Verificar si es primo
- `ft_find_next_prime` - Encontrar siguiente primo
- `ft_ten_queens_puzzle` - Puzzle de las 10 reinas

**Compilación del módulo:**
```bash
cd c-05
cc -Wall -Wextra -Werror -o main main.c */*.c
./main
```

### C06 - Argumentos de Línea de Comandos
Trabajar con argc y argv.
- Imprimir nombre del programa
- Imprimir argumentos
- Ordenar argumentos

### C07 - Asignación Dinámica de Memoria
Uso de malloc y gestión de memoria.
- `ft_strdup` - Duplicar string
- `ft_range` - Crear array de enteros
- `ft_ultimate_range` - Crear array con tamaño
- `ft_strjoin` - Unir strings con separador

**Compilación del módulo:**
```bash
cd c-07
cc -Wall -Wextra -Werror -o main main.c */*.c
./main
```

## 🚀 Proyectos Rush

### Rush 01 - Puzzle de Visibilidad
Resolver un puzzle de rascacielos basado en restricciones de visibilidad.

**Compilación:**
```bash
cd rusheito01
make
./rush-01
```

### Rush 02 - Diccionario de Números
Convertir números a palabras usando un diccionario.

**Compilación:**
```bash
cd rusheito02/ex00
make
./rush-02 [número]
```

**Ejemplo:**
```bash
./rush-02 42
# Output: forty two
```

## 🔍 BSQ - Big Square Finder

Encuentra el cuadrado más grande en un mapa.

**Compilación:**
```bash
cd BSQ
make
./bsq [archivo_mapa]
```

**Uso:**
```bash
# Con archivo
./bsq examplefile

# Desde stdin
./bsq < examplefile
```

## 🐚 Shell

Ejercicios de Shell scripting (bash).
```bash
cd shell00-v5
```

Los ejercicios incluyen:
- Manipulación de archivos
- Permisos
- Scripts básicos de bash
- Variables de entorno

## 🛠️ Compilación y Uso

### Requisitos
- GCC o Clang
- Make (para proyectos con Makefile)
- Sistema Unix/Linux

### Flags de Compilación
Todos los proyectos usan los siguientes flags de compilación:
```bash
-Wall -Wextra -Werror
```

### Compilación General
La mayoría de los módulos se pueden compilar de forma similar:

```bash
# Para módulos con main.c
cd [módulo]
cc -Wall -Wextra -Werror -o main main.c */*.c
./main

# Para proyectos con Makefile
cd [proyecto]
make
./[ejecutable]
```

### Limpieza
Para proyectos con Makefile:
```bash
make clean   # Elimina archivos objeto
make fclean  # Elimina archivos objeto y ejecutable
make re      # Recompila desde cero
```

## 📝 Notas Importantes

- Todos los ejercicios siguen la Norminette de 42 (estándar de código de 42)
- El código está optimizado para no tener fugas de memoria
- Se han implementado comprobaciones de errores apropiadas
- Algunos módulos tienen múltiples versiones (v0, v2, v3, etc.) que representan diferentes intentos o mejoras

## 👤 Autor

**Mario García**
- Email: marioga2@student.42malaga.com
- 42 Login: marioga2
- Escuela: 42 Málaga

## 📜 Licencia

Este proyecto es solo con fines educativos. El código está disponible para referencia y aprendizaje, pero se recomienda a los estudiantes actuales de 42 que trabajen en sus propias soluciones.

---

**Nota:** Este repositorio representa el trabajo completado durante la Piscina de C en 42 Málaga. Cada módulo y proyecto fue una oportunidad de aprendizaje invaluable en programación en C, algoritmos y resolución de problemas.

## 🎯 Objetivos de Aprendizaje Alcanzados

- ✅ Fundamentos de programación en C
- ✅ Gestión de memoria y punteros
- ✅ Recursión y algoritmos
- ✅ Trabajo con strings y arrays
- ✅ Entrada/Salida estándar
- ✅ Compilación y debugging
- ✅ Trabajo en equipo (Proyectos Rush)
- ✅ Shell scripting
- ✅ Resolución de problemas algorítmicos

**¡Buena suerte en tu viaje de aprendizaje en 42! 🚀**
