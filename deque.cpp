#include<iostream>
#include <queue>
#include<stdio.h>
#include<algorithm>
#define MAX 10
using namespace std;


class que{
   
private:
    int *queue;
    int front, rear, size;

public:
    // Constructor to initialize the circular queue
    que(int n) {
        size = n;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~que() {
        delete[] queue;
    }

    bool isempty()
    {
        if(front==-1){
            return true;
        }
        return false;
    }

    bool isfull()
    {
        if((front==0 && rear==size-1)||(front!=0 && rear==(front-1)%(size-1))){
            return true;
        }
        return false;
    }

    int pushfront(int value )
    {
        if(isfull()){
            return -1;
        }

        else if (front==-1)
        {
            front=rear=0;
           
        }
        else if (front==0&& rear!=size-1){
            front=size-1;
        }
        else 
        {
            front--;
        }
        queue[front]=value;
        return 1;
      
    }

     int pushrear(int value )
    {
        if(isfull()){
            return -1;
        }

        else if (front==-1)
        {
            front=rear=0;
           
        }
        else if (front!=0 && rear==size-1){
            rear=0;
        }
        else 
        {
            rear++;
        }
        queue[rear]=value;
        return 1;
      
    }
    int poprear(){
        if(isempty())
        {
            return -1;
        }
        int val=queue[rear];
        queue[rear]=-1;
        if(front==rear)
        {
            front=rear=-1;
        }
        else if (rear==0)
        {
            rear=size-1;

        }
        else{
            rear--;
           
        }
     return val;
    }


    int popfront(){
        if(isempty())
        {
            return -1;
        }
        int val=queue[front];
        queue[front]=-1;
        if(front==rear)
        {
            front=rear=-1;
        }
        else if (front==size-1)
        {
            front=0;

        }
        else{
            front++;
            
        }
        return val;
    }
    void display() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        
            for ( int i = front; i<=rear;i++)
            {
                cout<< queue[i]<<" ";
            }
       
        cout << endl;
    }
};

int main(){
    int n;
    cout << "Enter the size of the Circular Queue: ";
    cin >> n;

    que cq(n);

    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue rear\n";
        cout << "2. Enqueue front\n";
        cout << "3. Dequeue front\n";
        cout << "4. Dequeue rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            cq.pushrear(value );
            break;
        case 2:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            cq.pushfront(value );
            break;
        case 3:
            cq.popfront();
            break;
        case 4:
            cq.poprear();
            break;
        case 5:
            cq.display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}