#include<iostream>
#include <cctype>
#include<cstring>
using namespace std;

int top=-1;
char stack[20];
string postfix;
int length=-1;

char topp()
{
	if(top==-1) {
		return '\0';
	}
	return stack[top];
}

void push(char x) {
	if (top == 19)
	{
		cout << "STACK OVERFLOW\n";
	}
	else
	{
		stack[++top] = x;
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


int instack_priority(char x)
{	if(x=='+' || x=='-') {
		return 2;
	}
	else if(x=='*' || x=='/') {
		return 4;
	}
	else if(x=='^') {
		return 5;
	}
	else {
		return 0;
	}
}

int incoming_priority(char x)
{	if(x=='+' || x=='-') {
		return 1;
	}
	else if(x=='*' || x=='/') {
		return 3;
	}
	else if(x=='^') {
		return 6;
	}
	else if(x== '(') {
		return 9;
	}
	else {
		return 0;
	}
}




int infix_to_postfix(char x[], char size) {
	for (int i = 0; i < size; i++)
	{
		if(isalnum(x[i]))
		{
			postfix+=x[i];
		}
		else if (x[i]=='(')
		{
			push(x[i]);
		}
		else if(x[i]==')')
		{
			while (top != -1 && topp() != '(')
			{
				postfix+=pop();

			}
			if (top != -1) {
                pop(); 
            }

		}
		else  if(instack_priority(topp()) < incoming_priority(x[i]))
		{
			push(x[i]);
		}
		else if(instack_priority(topp()) >= incoming_priority(x[i])) {
			while (instack_priority(topp()) >= incoming_priority(x[i]))
			{
				postfix+=pop();
			}
			push(x[i]);
		}

	}

	while(top!=-1)
	{
		postfix+=pop();
	}



	return 0;
}



int main()
{
	char infix[15];


	cout<<"Enter the Infix Expression: "<<endl;
	cin>>infix;

	int size=strlen(infix);

	infix_to_postfix(infix,size);

	cout<<"POSTFIX EXPRESSION IS: "<<endl<<postfix<<endl;


	return 0;
}