#include <iostream>
#include <cctype> //contains function for lowering string and checking punctuation marks
#include <cstring>
using namespace std;

char stack[30];
int top = -1, length;

void push(char x)
{
  if (top == 29)
  {
    cout << "STACK OVERFLOW\n";
  }
  else
  {
    top++;
    stack[top] = x;
  }
}

char pop()
{
  if (top == -1)
  {
    cout << "STACK UNDERFLOW\n";
    return '\0';
  }
  else
  {
    return stack[top--];
  }
}

int main()
{
  int i;
  int count = 0; // it will help to properly skip space amd punctuation mark without messimg the indexing
  char c[40];
  char r[40]; // new array will store string in lower case and without space and punctuation

  cout << "Enter the statement: ";
  cin.getline(c, 40);

  length = strlen(c);
  cout << length << endl;

  for (i = 0; i < length; i++)
  {
    c[i] = tolower(c[i]); // lower case the string char by char
  }

  cout << "Lower Case string: " << c;

  for (i = 0; i < length; i++)
  {
    if (c[i] == ' ' || ispunct(c[i])) // Skip spaces and punctuation marks
    {
    }
    else
    {
      push(c[i]);
      r[count] = c[i]; // using count to properly handle indexing
      count++;
    }
  }

  r[count] = '\0'; // Null-terminate the string(code still works without it but still on internet it is advisable to do this)

  cout << "\nStack becomes: " << stack;
  cout << "\nString becomes: " << r << endl;

  int flag = 1;
  for (i = 0; i < count; i++)
  {
    if (pop() == r[i]) // stack follow LIFO principle so no need to reverse a string
    {
      continue;
    }
    else
    {
      flag = 0;
      break;
    }
  }

  if (flag == 1)
  {
    cout << "\nPalindrome" << endl;
  }
  else
  {
    cout << "\nNot a Palindrome" << endl;
  }

  return 0;
}
