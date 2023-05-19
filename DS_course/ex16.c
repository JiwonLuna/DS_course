#include<stdio.h>
#include<stdbool.h>

#define MAX_STACK_SIZE 100

typedef struct StackType {
	char stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

void push(StackType* s, char item) {
	s->stack[++(s->top)] = item;
	return;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

char pop(StackType* s) {
	char t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {
	printf("���ڿ��� �Է��Ͻÿ� : ");
	char input[MAX_STACK_SIZE];
	scanf("%s", input);

	StackType s;
	init(&s);
	int i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z')
			push(&s, input[i]);
		// �빮�ڴ� �ҹ��ڷ� �ٲ㼭 stack�� ����.
		else if ('A' <= input[i] && input[i] <= 'Z')
			push(&s, input[i] - ('A' - 'a'));
		i++;
	}
	bool flag = true;
	i = 0;
	while (input[i] != NULL) {
		if ('a' <= input[i] && input[i] <= 'z') {
			if (pop(&s) != input[i]) {
				flag = false;
				break;
			}
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			if (pop(&s) != (input[i] - ('A' - 'a'))) {
				flag = false;
				break;
			}
		}
		i++;
	}
	if (flag)
		printf("ȸ���Դϴ�.\n");
	else
		printf("ȸ���̾ƴմϴ�.\n");

	return 0;
}