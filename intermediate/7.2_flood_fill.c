#include <stdio.h>
#include <stdlib.h>

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

void	ff_recursion(char **tab, t_point size, t_point current, char target)
{
	if (tab[current.y][current.x] == target)
	{
		tab[current.y][current.x] = 'F';
		if (current.x + 1 < size.x)
		{
			++current.x;
			ff_recursion(tab, size, current, target);
			--current.x;
		}
		if (current.x > 0)
		{
			--current.x;
			ff_recursion(tab, size, current, target);
			++current.x;
		}
		if (current.y + 1 < size.y)
		{
			++current.y;
			ff_recursion(tab, size, current, target);
			--current.y;
		}
		if (current.y > 0)
		{
			--current.y;
			ff_recursion(tab, size, current, target);
			++current.y;
		}
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	if (begin.x < size.x && begin.y < size.y)
	{
		target = tab[begin.y][begin.x];
		ff_recursion(tab, size, begin, target);
	}
}

char	**make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return new;
}

int	main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
