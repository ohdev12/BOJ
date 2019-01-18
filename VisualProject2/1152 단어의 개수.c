#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main(void) {
	char str[MAX];
	char* token;
	const char* delim = ' ';
	fgets(str, MAX, stdin);
	printf("%s\n", str);
	strtok(str, delim);
	//printf("%s\n", token);
	return 0;
}
