#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "stack overflow error!");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack underflow errer!");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "stack underflow error!");
		exit(1);
	}
	else return s->stack[s->top];
}

int main() {
	StackType s;
	init(&s);
	char input[MAX_STACK_SIZE];
	printf("정수를 입력하시오: ");
	scanf("%s", input);
	printf("출력: ");
	int i = 0;
	while (input[i] != NULL) {
		if (is_empty(&s) || input[i] != peek(&s)){
			push(&s, input[i]);
			printf("%c", input[i]);
		}
		i++;
	}

	return 0;
}