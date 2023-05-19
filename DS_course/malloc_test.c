#include <stdio.h>

int main()
{
	int* p;
	p = (int*)malloc(40);
	p[0] = 1;
	printf("%d\n", p[0]);
	printf("%d\n", p[1]);
	return 0;
}