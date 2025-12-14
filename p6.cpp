#include<iostream>
using namespace std;
#define SIZE 5

class CircularQueue{
    int items[SIZE];
    int front, rear;

public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return ((front==0 && rear==SIZE-1) || (front==rear+1));
    }

    bool isEmpty(){
        return (front == -1);
    }

    void enqueue(int element){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
            return;
        }

        if(front == -1) front = 0;

        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout<<element<<" enqueued to queue"<<endl;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        if(front==rear){
            front=-1;
            rear=-1;
        }else{
            front=(front+1)%SIZE;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }

        cout<<"Queue elements are: ";  
        int i=front;
        while(true){
            cout<<items[i]<<" ";
            if(i==rear){
                break;
            }
            i=(i+1)%SIZE;
        }
        cout<<endl;
    }
};


int main(){
    CircularQueue q;
    int choice;
    do{
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                int element;
                cout<<"Enter element to enqueue: ";
                cin>>element;
                q.enqueue(element);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }while(choice!=4);
    return 0;
 }