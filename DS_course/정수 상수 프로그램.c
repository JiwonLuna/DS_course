#include <stdio.h>

int main()
{
	int x = 10;
	int y = 010;
	int z = 0x10;

	printf("x = %d\n", x);	// 10�� 10�����̰� int���̰� ���� �������� 10�̴�.
	printf("y = %d\n", y);	// 010�� 8�����̰� int���̰� ���� �������� 8�̴�.
	printf("z = %d", z);	// 0x10�� 16�����̰� int���̰� ���� �������� 16�̴�.

	return 0;
}