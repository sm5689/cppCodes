#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int front, rear, arr[5];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == 4)
            return true;
        else
            return false;
    }

    void enQueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
        }
        else
            rear++;
        arr[rear] = val;
    }

    int deQueue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }

    int count()
    {
        return (rear + 1);
    }

    void display()
    {
        cout << "Elements in Queue are\n";
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue q1;
    int option, value;
    do
    {
        cout << "Queue Operations Menu\n";
        cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Count\n6. Display\n7. Clear Screen\n";
        cout << "Prees 0 to Exit\n\n";
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operaton called\n";
            cout << "Enter an element to insert in the queue\n";
            cin >> value;
            q1.enQueue(value);
            break;
        case 2:
            cout << "Dequeue Opertion called\n";
            cout << "Dequeued element: " << q1.deQueue() << "\n";
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty\n";
            else
                cout << "Queue is not Empty\n";
            break;
        case 4:
            if (q1.isFull())
                cout << "Queue is Full\n";
            else
                cout << "Queue is not Full\n";
            break;
        case 5:
            cout << "Count operation called\n";
            cout << "Total elements in the Queue are: " << q1.count();
            cout << endl;
            break;
        case 6:
            cout << "Display Function called\n";
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter proper Option\n";
            break;
        }

    } while (option != 0);
    return 0;
}