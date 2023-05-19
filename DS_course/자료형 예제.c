#include <stdio.h>
int main()
{
	int id, pass;
	printf("아이디와 패스워드를 4개의 숫자로 입력하세요:\n");

	printf("id:____\b\b\b\b");
	scanf("%d", &id);
	
	printf("pass:____\b\b\b\b");
	scanf("%d", &pass);
	printf("\aYour id is\"%d\", passward is \"%d\".", id, pass);

	return 0;
}