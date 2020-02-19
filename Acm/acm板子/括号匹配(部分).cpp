bool isValid(char *s) {
  if (NULL == s)
    return false;
  int len = strlen(s);
  /*使用数组作为栈，申请内存*/
  char *stack = (char *)malloc(len * sizeof(char));
  if (NULL == stack)
    return false;
  int topOfStack = -1;
  while (0 != *s) {
    /*遇见左括号入栈*/
    if ('{' == *s || '[' == *s || '(' == *s) {
      // printf("push %c to stack\n",*s);
      topOfStack++;
      stack[topOfStack] = *s;
    }
    /*如果此时栈为空，说明之前都没有左括号，因此肯定不匹配，直接退出*/
    else if (topOfStack == -1) {
      topOfStack++;
      break;
    }
    /*遇见右括号，栈顶是左括号，出栈*/
    else if (('}' == *s && '{' == stack[topOfStack]) ||
             (')' == *s && '(' == stack[topOfStack]) ||
             (']' == *s && '[' == stack[topOfStack])) {
      topOfStack--;
    }
    /*右括号，并且栈顶不是左括号，肯定不匹配，直接退出*/
    else if ('}' == *s || ']' == *s || ')' == *s) {
      topOfStack++;
      break;
    }
    s++;
  }
  free(stack);
  /*判断栈是否为空*/
  return topOfStack == -1;
}