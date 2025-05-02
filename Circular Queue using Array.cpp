// Circular Queue using Array.cpp : 

#include <iostream>
using namespace std;
class CircularQueue
{
private :
    int* arr;
    int size;            //max size of array
    int length;         // number of elements
    int front;         //front element on queue
    int rear;         //last element on queue
public:
    CircularQueue(int s)
    {
        size = s;
        arr = new int[size];
        length = 0;
        front = 0;
        rear = -1;
    }
    ~CircularQueue()
    {
        delete[]arr;
    }
    bool IsEmpty()
    {
        return length == 0;
    }
    bool IsFull()
    {
        return length == size;
    }
    void EnQueue(int value)
    {
        if (IsFull())
        {
            cout << "Queue is Full, you can't enqeueu" << endl;
            return;
        }
        rear = (rear+1) % size ;   // % for circular
        arr[rear] = value;
        length++;
    }
    int DeQueue()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty, you can't deqeueu" << endl;
            return -1;
        }
        int delvalue = arr[front];
        front = (front + 1) % size;   // % for circular
        length--;
        return delvalue;
    }
    void Print()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue : ";
        for (int i = front; i != rear; i = (i + 1) % size)  // % for circular
        {
            cout << arr[i] << "  ";
        }
        cout << arr[rear]<<endl;
    }
    int Front()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty, there is no front" << endl;
            return 0 ;
        }
        return arr[front];
    }
    int End()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty, there is no end" << endl;
            return 0 ;
        }
        return arr[rear];
    }
    int GetLength()
    {
        return length;
    }
};
int main()
{
    int size;
    cout << "Enter Size of Queue" << endl;
    cin >> size;
    CircularQueue Q(size);
    for (int i = 0; i < 3; i++)
    {
        int element;
        cout << " Enter element to queue" << endl;
        cin >> element;
        Q.EnQueue(element);
    }
    Q.Print();
    cout << "Front is : " << Q.Front() << endl;
    cout << "End is : " << Q.End() << endl;
    cout << "number of elements on Queue is : " << Q.GetLength() << endl;
    cout << " deleted element is : " << Q.DeQueue() << endl;
    cout << " deleted element is : " << Q.DeQueue() << endl;
    cout << "After deletion : " << endl;
    Q.Print();
    cout << "Front is : " << Q.Front() << endl;
    cout << "End is : " << Q.End() << endl;
    cout << "number of elements on Queue is : " << Q.GetLength() << endl;

    cout << "-------------------------" << endl;

    for (int i = 0; i < 2; i++)
    {
        int element;
        cout << " Enter element to queue" << endl;
        cin >> element;
        Q.EnQueue(element);
    }
    Q.Print();
    cout << "Front is : " << Q.Front() << endl;
    cout << "End is : " << Q.End() << endl;
    cout << "number of elements on Queue is : " << Q.GetLength() << endl;

}

