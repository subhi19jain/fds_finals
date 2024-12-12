#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, size;

public:
    // Constructor to initialize the circular queue
    CircularQueue(int n) {
        size = n;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] queue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
       if(front==-1){
        cout<< " queue is empty "<<endl;
        return true;
       }
       return false;
    }

    // Function to check if the queue is full
    bool isFull() {
        if ((front==0 && rear==size-1)|| (front!=0 && rear== (front-1)%(size-1)))
        {
          //cout<<"queue is full !! "<<endl; 
          return true;
        }
        return false ;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear= 0;
            queue [rear]=value;
        }
        else if (rear==size-1 && front!=0)
        {
            rear=0;
            queue[rear]=value;
        }
        else{
        rear ++;
        queue[rear] = value;
        cout << "Enqueued: " << value << endl;
        
    }
    }
    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int value = queue[front];
        queue[front]=-1;
        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
             
        } else if (front==size-1) {
            front =0;
        }
        else {
            front++;
        }
        cout << "Dequeued: " << value << endl;
        return value;
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
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

int main() {
    int n;
    cout << "Enter the size of the Circular Queue: ";
    cin >> n;

    CircularQueue cq(n);

    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
