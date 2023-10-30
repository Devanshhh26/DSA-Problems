#include<iostream>
using namespace std;

class Queue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size=size;
        arr=new int [size];
        front =0;
        rear=0;
    }
    void push(int data)
    {
        if(rear==size)
        {
            cout<<"Queue is full";
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    void pop()
    {
        if(rear==front)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rear)
            {
                front=0;
                rear=0;
            }
        }
    }
    int getFront()
    {
        if(front==rear)
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    bool isEmpty()
    {
        if(front==rear)
        {
            return true;
        }
        else{
            return false;
        }
    }
    int getSize()
    {
        return rear-front; 
    }
};

int main()
{
    Queue q(10); 
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.pop();
    cout<<q.getSize();
    if(q.isEmpty())
    {
        cout<<"Queue is Empty ";
    }
    else{
        cout<<"Queue is not Empty ";
    }
    cout<<q.getFront();
    return 0;
}