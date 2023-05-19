#include <stdio.h>

int main()
{
	int x = 10;
	int y = 010;
	int z = 0x10;

	printf("x = %d\n", x);	// 10은 10진수이고 int형이고 값은 십진수로 10이다.
	printf("y = %d\n", y);	// 010은 8진수이고 int형이고 값은 십진수로 8이다.
	printf("z = %d", z);	// 0x10은 16진수이고 int형이고 값은 십진수로 16이다.

	return 0;
}