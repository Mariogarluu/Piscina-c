#include <stdio.h>
#include "ej.h"

int main(void)
{
    char *dup = ft_strdup("Hello");
    printf("ft_strdup: %s\n", dup);
    free(dup);

    int *range = ft_range(1, 5);
    for (int i = 0; i < 4; i++)
        printf("ft_range: %d\n", range[i]);
    free(range);

    int *ultimate_range;
    int size = ft_ultimate_range(&ultimate_range, 1, 5);
    printf("ft_ultimate_range size: %d\n", size);
    for (int i = 0; i < size; i++)
        printf("%d ", ultimate_range[i]);
    free(ultimate_range);

    char *strs[] = {"Hello", "World", "42"};
    char *joined = ft_strjoin(3, strs, " ");
    printf("\nft_strjoin: %s\n", joined);
    free(joined);

    return (0);
}