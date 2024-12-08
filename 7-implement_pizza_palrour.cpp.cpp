#include<iostream>
using namespace std;

#define MAX 5

int front=-1;
int rear=-1;


class pizza{
    public:
          int amount;
          string size;
          float price;

float pricing(string size,int amount){
    if (size=="large")
    {
        price=amount*100;
    }
    else if (size=="medium")
    {
        price=amount*75;
    }
    else{
        price=amount*50;
    }
    return price;
    
}


int Accept(int x)
{
    if (rear==MAX)
            {
              cout<<"Orders Are Full!!!\n";
              return 1;
            }
    else if (rear==-1 && front==-1)
            {
                rear=0;
                front=0;
                cout<<"Enter the size: ";
                cin>>size;
                cout<<"Enter the Amount: ";
                cin>>amount;
                price=pricing(size,amount);
            
            }
    else       
            {
                rear++;
                cout<<"Enter the size: ";
                cin>>size;
                cout<<"Enter the Amount: ";
                cin>>amount;
                price=pricing(size,amount);
            
            }
            return 0;
}



void Deliver()
{
    if (front==-1)
    {
        cout<<"All orders are delivered\n";
    }
    else if (front==rear)
    {
        cout<<"Order deliverd and Moeny has been recieved: "<<price<<endl;
        front=-1;
        rear=-1;
    }
    else
    {
        cout<<"Order deliverd and Moeny has been recieved: "<<price<<endl;
        front++;
    }
    
}

        


};




int main()
{   int j=0;
    int temp=0;
    pizza M[10]; 
    int ch,n;

    do
    {   cout<<"Menu\n1.Accept Order\n2.Deliver Order\n3.Display\n4.Exit\n";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter Number Of consecutive Orders: ";
            cin>>n;

            for (int i = temp; i < n+temp; i++)
            {
                    M[i].Accept(n);
                    if (n==1)
                    {
                        break;
                    }
                    
            }
            temp+=temp;
       
            break;
        case 2:              
                       
             M[j].Deliver();
             j++;
             if (rear==-1 && front==-1){
                j=0;
             }
            
            
            break;
        case 3:        
                if(front==-1)
                    {
                        cout<<"No orders at the moment!!!\n";
                    }
                    else
                    {
                    for (int i = front; i <= rear; i++)
                    {
                    cout<<"Amount is: "<<M[i].amount<<"\nPrice is: "<<M[i].price<<"\nSize is: "<<M[i].size<<endl;
                    }
                    }
             break;
        case 4:
            break;
        default:
            cout<<"Wrong choice\n";
            break;
        }
        
    } while (ch!=4);




    return 0;
}

/*
/*
	Assignment no.7: Implementation of double ended queue using array.	
*/
#include<iostream>
#define MAX 10
using namespace std;

int rear=-1;
int front=-1;

class Deque
{
public:
	int queue[MAX];

	void insertAtfront(int ele)
	{
        	if((front == 0 && rear == MAX-1) || (front == rear+1))
	        {
	            	cout << "\nDeque overflow." << endl;
	        }
	        else if(front == -1 && rear == -1)  
	        {
	        	front = rear = 0;
	            	queue[front] = ele;
	        }
	        else if(front == 0)  
	        {
	            	front = MAX - 1;
	            	queue[front] = ele;
	        }
	        else
	        {
	            	front--;
	            	queue[front] = ele;
	        }
	}
	
	void insertAtrear(int ele)
	{
		if((front == 0 && rear == MAX-1) || (front == rear + 1))
	        {
	            	cout << "\nDeque overflow." << endl;
	        }
	        else if(rear == -1 && front == -1)  
	        {
	            	front = rear = 0;
	            	queue[rear] = ele;
	        }
	        else if(rear == MAX-1)  
	        {
	            	rear = 0;
	            	queue[rear] = ele;
	        }
	        else
	        {
	            	rear++;
	            	queue[rear] = ele;
	        }
	}
	
	void deleteAtfront()
	{
		if(front == -1 && rear == -1) 
	        {
	        	cout << "\nDeque underflow." << endl;
	        }
	        else if(rear == front)  
	        {
	            	cout << "\nThe deleted element is " << queue[front] << endl;
	            	front = rear = -1;
	        }
	        else if(front == MAX-1)
	        {
	            	cout << "\nThe deleted element is " << queue[front] << endl;
	            	front = 0;
	        }
	        else
	        {
	            	cout << "\nThe deleted element is " << queue[front] << endl;
	            	front++;
	        }
	}
	
	void deleteAtrear()
	{
		if(front == -1 && rear == -1) 
		{
	            	cout << "\nDeque underflow." << endl;
	        }
	        else if(rear == front) 
	        {
	            	cout << "\nThe deleted element is " << queue[rear] << endl;
	            	front = rear = -1;
	        }
	        else if(rear == 0)  
	        {
	            	cout << "\nThe deleted element is " << queue[rear] << endl;
	            	rear = MAX - 1;
	        }
	        else
	        {
	            	cout << "\nThe deleted element is " << queue[rear] << endl;
	            	rear--;
	        }
	}
	
	void display()
	{
	        if(front == -1 && rear == -1)
	        {
	            	cout << "\nDeque is empty." << endl;
	        }
	        else
	        {
	            	cout << "\nElements in deque: ";
	            	while(front != rear)
	            	{
	                	cout << queue[front] << " ";
	                	front = (front + 1) % MAX;
	            	}
	            	cout << queue[rear] << endl;
	        }
	}
};
	
int main()
{
	int choice, ch;
	Deque d;
	int ele;
	do
	{
		cout << "\n1. Insert the element at front.\n2. Insert the element at rear.\n3. Delete the element from 	front.\n4. Delete the element from rear.\n5. Display the deque.";
	        cout << "\nEnter your choice: ";
	        cin >> ch;
	
	        switch (ch)
	        {
	        	case 1:
	                	cout << "\nEnter the element to be inserted: ";
	                	cin >> ele;
	                	d.insertAtfront(ele);
	                	break;
	
	            	case 2:
	                	cout << "\nEnter the element to be inserted: ";
	                	cin >> ele;
	                	d.insertAtrear(ele);
	                	break;
	
	            	case 3:
	                	d.deleteAtfront();
	                	break;
	
	            	case 4:
	                	d.deleteAtrear();
	                	break;
	
	            	case 5:
	                	d.display();
	                	break;
	
	            	default:
	                	cout << "\nInvalid choice" << endl;
	                	break;
	        }
	
	        cout << "\nPress 1 to continue: ";
	        cin >> choice;
	
	} while (choice == 1);
	return 0;
}		
*/
