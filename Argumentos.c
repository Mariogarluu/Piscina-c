#include <unistd.h>

int main(int a, char *args[])
{
	int i = 0;
	char salto = '\n';
	while(args[i] != NULL)
	{
		int x = 0;
		while(args[i][x] != '\0')
		{
			char w = args[i][x];
			write(1, &w, 1);
			x++;
		}
		write(1, &salto, 1);
		i++;
	}
	return (a);
}
