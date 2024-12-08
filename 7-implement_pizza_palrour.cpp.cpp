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