#include "miniStack.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool isPalandrome(string str);
bool balancedParentheses(string code);
int balancedBlocks(string code);

int main() {
  miniStack<int> stackInt;

  stackInt.push(1);
  stackInt.push(2);
  stackInt.push(3);

  cout << "stack size: " << stackInt.size() << endl;

  stackInt.pop();

  cout << stackInt.top() << endl;

  miniStack<string> stackString;

  stackString.push("hello");
  stackString.push(", ");
  stackString.push("world!");

  while (!stackString.empty()) {
    cout << stackString.top();
    stackString.pop();
  }
  cout << endl;

  cout << "stack size: " << stackString.size() << endl;

  cout << "a b ccb should return false" << endl;
  cout << isPalandrome("a b ccb") << endl;

  cout << "collin should return false" << endl;
  cout << isPalandrome("collin") << endl;

  cout << "a b ccba should return true" << endl;
  cout << isPalandrome("a b ccba") << endl;

  cout << "()()() should return true" << endl;
  cout << balancedParentheses("()()()") << endl;

  cout << "(()) should return true" << endl;
  cout << balancedParentheses("(())") << endl;

  cout << "(() should return false" << endl;
  cout << balancedParentheses("(()") << endl;

  cout << "{([])} should return -1" << endl;
  cout << balancedBlocks("{([])}") << endl;

  cout << "{([)]} should return 3" << endl;
  cout << balancedBlocks("{([)]}") << endl;

  return 0;
}

bool isPalandrome(string str) {
  miniStack<char> stack;
  for (int i = 0; i < str.length(); i++) {
    if (stack.empty()) {
      if (str[i] != ' ')
        stack.push(str[i]);
    } else {
      if (str[i] == stack.top())
        stack.pop();
      else if (str[i] != ' ')
        stack.push(str[i]);
    }
  }
  return stack.empty();
}

bool balancedParentheses(string code) {
  miniStack<char> stack;
  for (int i = 0; i < code.length(); i++) {
    if (stack.empty()) {
      if (code[i] == '(' || code[i] == ')')
        stack.push(code[i]);
    } else {
      if (stack.top() == '(' && code[i] == ')')
        stack.pop();
      else if (code[i] == '(' || code[i] == ')')
        stack.push(code[i]);
    }
  }
  return stack.empty();
}

int balancedBlocks(string code) {
  miniStack<char> stack;
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '(' || code[i] == '[' || code[i] == '{') {
      stack.push(code[i]);
    } else if (stack.top() == '(') {
      if (code[i] == ')') {
        stack.pop();
      } else if (code[i] == ']' || code[i] == '}') {
        cout << "error: expected \")\" at position:" << i << endl;
        return i;
      }
    } else if (stack.top() == '[') {
      if (code[i] == ']') {
        stack.pop();
      } else if (code[i] == ')' || code[i] == '}') {
        cout << "error: expected \"]\" at position:" << i << endl;
        return i;
      }
    } else if (stack.top() == '{') {
      if (code[i] == '}') {
        stack.pop();
      } else if (code[i] == ']' || code[i] == ')') {
        cout << "error: expected \"}\" at position:" << i << endl;
        return i;
      }
    }
  }
  if (stack.empty())
    return -1;
}