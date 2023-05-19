#include <stdio.h>

int main()
{

	printf("Start test!\n");
	
	int num[5] = { 1,2,3,4,5 };
	printf("%d\n", *num+1);
	printf("%d\n", num);
	*(num + 2) = 8;
	*(num + 1) = 4;
	printf("%d\n", *num);
	printf("%d\n", *num+4);
	printf("%d\n", *(num + 1));
	for (int i = 0; i < 5; i++) {
		printf("%d	", num[i]);
	}

	//*(num + 5) = 6;
	//printf("%d\n", *(num + 5));
	//*(num + 5) = 7;
	//printf("%d\n", *(num + 5));

	return 0;
}