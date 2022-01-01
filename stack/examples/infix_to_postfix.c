#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"
#include <ctype.h>
int precedence(char focus_element) {
  switch (focus_element) {
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    case '^':
      return 3;
  }
  return -1;
}

char * infix_to_postfix(char *exp) {
  char *ret_array = (char *) malloc(sizeof(char) * 100);
  int ret_arr_pos = -1;
  stack *stackhol = newStack();
  for (int i = 0; exp[i]; i++) {
    if (isalpha(exp[i]))
      ret_array[++ret_arr_pos] = exp[i];
    else if (exp[i] == '(') {
      push((int) exp[i], stackhol);
    }
    else if (exp[i] == ')') {
      while (!isEmpty(stackhol) && returnTop(stackhol) != '(')
        ret_array[++ret_arr_pos] = pop(stackhol);
      pop(stackhol);
    }
    else {
      while (!isEmpty(stackhol) && precedence(exp[i]) <= precedence(returnTop(stackhol))) {
        ret_array[++ret_arr_pos] = pop(stackhol);
      }
      push((int) exp[i], stackhol);
    }
  }
  while (!isEmpty(stackhol))
    ret_array[++ret_arr_pos] = pop(stackhol);
  ret_array[++ret_arr_pos] = '\0';
  return ret_array;
}

int main() {
  char hold[100];
  fgets(hold, 100, stdin);
  fputs(infix_to_postfix(hold), stdout);
  return 0;
}
