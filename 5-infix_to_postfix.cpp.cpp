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

// sample code 
/*
#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100

class Postfix
{
	char stack[MAX];
	int stackIndex;
	
public:	
	Postfix() 
	{
        	stackIndex = -1;
    	}
    		
	void push(char ele)
	{
		if(stackIndex == MAX-1)
		{
			cout<<"Stack overflow";
		}
		else
		{
			stack[++stackIndex] = ele;
		}
	}
	
	char pop() 
	{
        	if (stackIndex == -1) 
        	{
            		cout << "Stack Underflow" << endl;
            		return -1; 
            	} 
            	else 
            	{
            		return stack[stackIndex--];
        	}
    	}
    	
    	bool isEmpty() 
    	{
        	return stackIndex == -1;
    	}
    
	int prec(char c)
	{
		if(c == '^')
			return 3;
		else if(c == '/' || c == '*')
			return 2;
		else if(c == '+' || c == '-')
			return 1;
		else
			return -1;
	}
	
	char associativity(char c)
	{
		char R,L;
		if(c == '^')
			return R;
		return L;
	}
	
	void infixtopostfix(char s[])
	{
		int len = strlen(s);
		char postfix[100];
		int postIndex = 0;
		char c;
		
		for(int i=0;i<len;i++)
		{
			c = s[i];
			
			if(isalpha(c) || isdigit(c))
			{
				postfix[postIndex++]=c;
			}
			
			else if(c == '(')
			{
				push(c);
			}
			
			else if(c == ')')
			{
				while(!isEmpty() && stack[stackIndex]!= '(')
				{
					postfix[postIndex++] = pop();
				}
				if (!isEmpty()) 
				{
                    			pop(); 
                		}
			}
			
			else if(c == '[')
			{
				push(c);
			}
			
			else if(c == ']')
			{
				while(!isEmpty() && stack[stackIndex]!= '[')
				{
					postfix[postIndex++] = pop();
				}
				if (!isEmpty()) 
				{
                    			pop(); 
                		}
			}
			
			else if(c == '{')
			{
				push(c);
			}
			
			else if(c == '}')
			{
				while(!isEmpty() && stack[stackIndex]!= '{')
				{
					postfix[postIndex++] = pop();
				}
				if (!isEmpty()) 
				{
                    			pop(); 
                		}
			}
			
			else
			{
				while (!isEmpty() && (prec(c) < prec(stack[stackIndex]) ||
                                       (prec(c) == prec(stack[stackIndex]) &&
                                           associativity(c) == 'L'))) 
				{
					postfix[postIndex++] = pop();
				}
				push(c);
			}
		}
		
		while (!isEmpty()) 
		{
        		postfix[postIndex++] = pop();
    		}
	
    		postfix[postIndex] = '\0';
    		cout<<"Postfix Expression is:"<<postfix<<endl;
    	}
};	
		
int main() 
{
	char exp[10];
	cout<<"Enter the Infix Expression:";
	cin>>exp;
	
	Postfix b;
	b.infixtopostfix(exp);
    	return 0;
}		
		*****************//////////////////////
sample questions 
Here are **5 sample questions with answers** that you can solve using your program to convert infix expressions to postfix:

---

### **Question 1**  
**Infix Expression**:  
`A+B*C`  

**Solution**:  
Postfix Expression: `ABC*+`

---

### **Question 2**  
**Infix Expression**:  
`(A+B)*C`  

**Solution**:  
Postfix Expression: `AB+C*`

---

### **Question 3**  
**Infix Expression**:  
`A*B+C/D`  

**Solution**:  
Postfix Expression: `AB*CD/+`

---

### **Question 4**  
**Infix Expression**:  
`A+B*C-D/E`  

**Solution**:  
Postfix Expression: `ABC*+DE/-`

---

### **Question 5**  
**Infix Expression**:  
`(A+B)*(C-D)`  

**Solution**:  
Postfix Expression: `AB+CD-*`

---

You can input these expressions into your program and verify the outputs match the solutions!
		
		
		
		
		
		*/
