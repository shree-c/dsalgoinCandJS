#include <stdio.h>
#include <stdlib.h>
typedef struct node 
int isOperand(char x) {
	return (x >= 'a' && x <= 'z') ||
            (x >= 'A' && x <= 'Z');
}
char *getInfix(char *postfix) {
	
}
int main() {
	printf("enter the expression in infix form: ");
	char infix_hold[100];
	fgets(infix_hold, 99, stdin);
	fputs(getInfix(infix_hold), stdout);
	return 0;
}

