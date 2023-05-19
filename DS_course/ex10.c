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
	int n;
	printf("정수 배열의 크기 : ");
	scanf("%d", &n);
	printf("정수를 입력하시오 : ");
	StackType s;
	init(&s);
	for (int i = 0; i < n; i++) {
		element t;
		scanf("%d", &t);
		push(&s, t);
	}
	printf("반전된 정수 배열 : ");
	for (int i = 0; i < n; i++) {
		printf("%d", pop(&s));
	}
	return 0;
}