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

    } while (ch != 6);

    return 0;
}