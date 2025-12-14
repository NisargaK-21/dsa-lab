#include<iostream>
#include<string>
using namespace std;

struct Employee{
    string ssn,name;
    float sal;
    long phno;
    Employee *next,*prev;
};

Employee *head=nullptr,*rear=nullptr;

Employee* createNode(){
    Employee *newnode=new Employee;
    cout<<"Enter SSN: ";
    cin>>newnode->ssn;
    cout<<"Enter Name: ";
    cin>>newnode->name;
    cout<<"Enter Salary: ";
    cin>>newnode->sal;
    cout<<"Enter Phone Number: ";
    cin>>newnode->phno; 
    newnode->next=newnode->prev=nullptr;
    return newnode;
}

void createDll(int n){
    for(int i=0;i<n;i++){
        Employee *newnode=createNode();
        if(head==nullptr){
            head=rear=newnode;
        }else{
            rear->next=newnode;
            newnode->prev=rear;
            rear=newnode;
        }
    }
}

void display(){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Employee *temp=head;
    int count=0;
    while(temp!=nullptr){
        cout<<"SSN:"<<temp->ssn<<"| Name:"<<temp->name<<"| Salary:"<<temp->sal<<"| Phone Number:"<<temp->phno<<endl;
        temp=temp->next;
        count++;
    }
    cout<<"NULL"<<endl;
    cout<<"Total Employees: "<<count<<endl;
}

void insertEnd(){
    Employee *newnode=createNode();
    if(head==nullptr){
        head=rear=newnode;
    }else{
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}

void deleteEnd(){
    if(rear==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Employee *temp=rear;
    if(head==rear){
        head=rear=nullptr;
    }else{
        rear=rear->prev;
        rear->next=nullptr;
    }
    cout<<"\nDeleted Employee:"<<temp->name<<endl;
    delete temp;
}

void insertFront(){
    Employee *newnode=createNode();
    if(head==nullptr){
        head=rear=newnode;
    }else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void deleteFront(){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Employee *temp=head;
    if(head==rear){
        head=rear=nullptr;
    }else{
        head=head->next;
        head->prev=nullptr;
    }
    cout<<"\nDeleted Employee:"<<temp->name<<endl;
    delete temp;
}

void demonstrateDeque(){
    cout<<"\n--- Demonstrating Deque Operations ---\n"<<endl;
    cout<<"1.Insert at Front\n2.Insert at End\n3.Delete from Front\n4.Delete from End\n5.Display\n6.Exit"<<endl;
    int choice;
    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: insertFront(); break;
            case 2: insertEnd(); break;
            case 3: deleteFront(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
            case 6: cout<<"\nExiting..."<<endl; break;
            default: cout<<"\nInvalid choice"<<endl;
    }
    }while(choice!=6);
}

int main(){
    int choice,n;
    do{
        cout<<"\n--- Employee Management System ---\n"<<endl;
        cout<<"1.Create Employee List\n2.Display Employee List\n3.Insert at End\n4.Delete from End\n5.Insert at Front\n6.Delete from Front\n7.Demonstrate Deque Operations\n8.Exit"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:cout<<"Enter number of employees: ";
                   cin>>n;
                   createDll(n);
                   break;
            case 2:display(); break;
            case 3:insertEnd(); break;
            case 4:deleteEnd(); break;
            case 5:insertFront(); break;
            case 6:deleteFront(); break;
            case 7:demonstrateDeque(); break;
            case 8: cout<<"\nExiting..."<<endl; break;
            default: cout<<"\nInvalid choice"<<endl;
        }
    }while(choice!=8);
}