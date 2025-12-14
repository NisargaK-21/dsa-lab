#include<iostream>
#include<string>
using namespace std;

struct Student{
    string name;
    int sem;
    Student *next;
};

Student *head=nullptr;

void createSll(int n){
    head = nullptr;

    for(int i=0;i<n;i++){
        Student *newnode = new Student;
        cout<<"Enter student details:"<<endl;
        cin>>newnode->name>>newnode->sem;

        newnode->next = head;
        head = newnode;
    }
}

void display(){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Student *temp=head;
    
    while(temp!=nullptr){
        cout<<"["<<temp->name<<", "<<temp->sem<<"] -> ";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
}


void insertEnd(){
    Student *newnode = new Student;

    cout<<"Enter student details to insert at end:"<<endl;
    cin>>newnode->name>>newnode->sem;

    newnode->next = nullptr;

    if(head==nullptr){
        head=newnode;
    }else{
        Student *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}


void deleteEnd(){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }

    Student *temp=head;
    Student *prev=nullptr;
    while(temp->next!=nullptr){
        prev=temp;
        temp=temp->next;
    }
    prev->next=nullptr;
    delete temp;
}

void insertFront(){
    Student *newnode = new Student;

    cout<<"Enter student details to insert at end:"<<endl;
    cin>>newnode->name>>newnode->sem;

    newnode->next=head;
    head=newnode;
}

void deleteFront(){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Student *temp=head;
    head=head->next;
    delete temp;
}


int main(){
    int choice;
    do{
        cout<<"1. Create SLL"<<endl;
        cout<<"2. Display SLL"<<endl;
        cout<<"3. Insert at end"<<endl;
        cout<<"4. Delete at end"<<endl;
        cout<<"5. Insert at front"<<endl;
        cout<<"6. Delete at front"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                int n;
                cout<<"Enter number of students: ";
                cin>>n;
                createSll(n);
                break;
            case 2:
                display();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }while (choice!=7);
  return 0;
}