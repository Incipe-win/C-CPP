/*栈 */

#include <iostream>
using namespace std;

const int MAX = 5;
class stack {
public:
  void init() { top = 0; }
  void push(int x);
  int pop();
  int gettop() { return top; }

private:
  int num[MAX];
  int top;
  bool isfull() { return top == MAX ? true : false; }
  bool isempty() { return top == -1 ? true : false; }
};

void stack::push(int x) {
  if (isfull()) {
    cout << "Stack is full!" << endl;
    return;
  };
  num[top++] = x;
}

int stack::pop() {
  top--;
  if (isempty()) {
    cout << "Stack is empty!" << endl;
    return 0;
  };
  return num[top];
}

int main() {
  stack s;
  s.init();
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  for (int i = 0; i < 3; i++)
    cout << s.pop() << endl;
  cout << endl;

  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  cout << endl;

  for (int i = 0; i < 5; i++)
    cout << s.pop() << endl;
  s.pop();
  return 0;
}
