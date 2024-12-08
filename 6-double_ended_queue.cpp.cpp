#include <iostream>
using namespace std;
#define MAX 10
int Q[MAX];
int front = -1;
int rear = -1;
int n;

void enqueueRear()
{

    if (rear == MAX - 1)
    {
        cout << "Queue Overflow\n";
    }
    else if (rear == -1)
    {
        rear = 0;
        front = 0;
        cout << "Enter the number: ";
        cin >> n;
        Q[rear] = n;
    }
    else
    {
        rear++;
        cout << "Enter the number: ";
        cin >> n;
        Q[rear] = n;
    }
}

void dequeueFront()
{
    if (front == -1)
    {
        cout << "Queue Underflow\n";
    }
    else if (front == rear)
    {
        cout << Q[front] << " is deleted\n";
        rear = -1;
        front = -1;
    }
    else
    {
        cout << Q[front] << " is deleted\n";
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue us Empty\n";
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << "\t" << Q[i] << "\t" << endl;
        }
    }
}

void enqueueFront()
{
    if (front <= 0)
    {
        cout << "cant add fron front\n";
    }
    else if (front+1 ==rear)
    {
        cout<<"full queue\n";
    }
    else
    {
        front--;
        cout << "Enter the number: ";
        cin >> n;
        Q[front] = n;
    }
}

void dequeueRear()
{
    if (rear == -1)
    {
        cout << "Queue Underflow\n";
    }
    else if (rear == front)
    {
        cout << Q[rear] << " is deleted\n";
        rear = -1;
        front = -1;
    }
    else
    {
        cout << Q[rear] << " is deleted\n";
        rear--;
    }
}

int main()
{
    int ch;
    do
    {
        cout << "Menu\n1.EnqueueRear\n2.DequeueFront\n3.EnqueueFront\n4.DequeueRear\n5.Display\n6.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueueRear();
            break;
        case 2:
            dequeueFront();

            break;
        case 3:
            enqueueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            display();
            break;
        case 6:
            break;

        default:
            cout << "Wrong Choice\n";
            break;
        }

        /*
           /*
Assignment no.6: Implementation of queue using array.
*/
#include <iostream>
#define MAX 5

using namespace std;

class order
{
public:
int queue[MAX];
int rear = -1;
int front = -1;

void en_queue()
{
if (rear == MAX - 1)
{
        cout << "\nOrder cannot be accepted" << endl;
    }
    else
    {
        int ele;
        cout << "\nEnter the new order: ";
        cin >> ele;
        rear++;
        queue[rear] = ele;
    }
}

void de_queue()
{
    if (front == rear)
    {
        cout << "\nAll the ordrs are served." << endl;
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
        int ele = queue[front];
        cout << "\nThe order served is " << ele << endl;
    }
}

void display()
{
    if (front == rear)
    {
        cout << "\nAll the orders are served." << endl;
    }
    else
    {
        cout << "\nOrders are served in the sequence : ";
        for (int i = front + 1; i <= rear; i++)
        {
        cout << queue[i] << " ";
        }
        cout << endl;
    }
}
};

int main()
{
int choice, ch;
    order b;
    do
    {
        cout << "\n1. Enter the new order.\n2. serve the order\n3. Display the sequence of order to be served.\n";
        cout << "\nEnter your choice: ";
        cin >> ch;
       
        switch (ch)
        {
        case 1:
             b.en_queue();
             break;
             
        case 2:
           b.de_queue();
           break;
           
        case 3:
           b.display();
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

    } while (ch != 6);

    return 0;
}
