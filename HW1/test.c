#include <stdio.h>

int fun(int n)

{

	int count = 0;

	for (int i = n; i > 0; i--)

		for (int j = 0; j < i; j++)

			count += 1;

	return count;
}

int main()
{

	int num = fun(10);
	printf("%d", num);
}
