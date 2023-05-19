#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct moon {
	int a;
	char str[20];
}moon;

int main() {
	moon* m;

	m = (moon*)malloc(sizeof(moon));
	if (m == NULL) {
		fprintf(stderr, "can't allocate memory\n");
		exit(1);
	}
	m->a = 100;
	strcpy(m->str, "just testing");

	free(m);
	return 0;
}