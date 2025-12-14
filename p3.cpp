#include<iostream>
#include<cstring>
#define MAX 5
using namespace std;

class Stack{
    private:
      int arr[MAX];
      int top;
    public:
     Stack(){
        top=-1;
     }

     void push(char element){
         if(top>=MAX-1){
            cout<<"Stack Overflow"<<endl;
         }
         else{
            arr[++top]=element;
         }
     }

     int pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            return arr[top--];
        }
     }

     void display(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack elements are: "<<endl;
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
     }

     void check_Overflow(){
        top=MAX-1;
        cout<<"Filling stack to maximum capacity."<<endl;
        push('X');
     }

     void check_Underflow(){
         top=-1;
         cout<<"Emptying stack."<<endl;
         pop();
     }

     void checkPalindrome(string str){
        Stack tempStack;
        int len=str.length();

        for(int i=0;i<len;i++){
            tempStack.push(str[i]);
        }

        bool isPalindrome=true;

        for(int i=0;i<len;i++){
            if(tempStack.pop()!=str[i]){
                isPalindrome=false;
                break;
            }
        }

        if(isPalindrome){
            cout<<str<<" is a palindrome."<<endl;
        }
        else{
            cout<<str<<" is not a palindrome."<<endl;
        }
     }
};

int main(){
    Stack s;
    int choice;
    int element;
    string input;

    do{
     cout<<"====Stack menu===="<<endl;
     cout<<"1. Push element"<<endl;
     cout<<"2. Pop element"<<endl;
     cout<<"3. Check Palindrome"<<endl;
     cout<<"4. Demonstrate Overflow and Underflow"<<endl;
     cout<<"5. Display Stack"<<endl;
     cout<<"6. Exit"<<endl;

     cout<<"Enter your choice: ";
     cin>>choice;

     switch(choice){
        case 1:
            cout<<"Enter element to push: ";
            cin>>element;
            s.push(element);
            break;
        case 2:
            element=s.pop();
            if(element!='\0'){
                cout<<"Popped element: "<<element<<endl;
            }
            break;
        case 3:
            cout<<"Enter string to check palindrome: ";
            cin>>input;
            s.checkPalindrome(input);
            break;
        case 4:
            s.check_Overflow();
            s.check_Underflow();
            break;
        case 5:
            s.display();
            break;
        case 6:
            cout<<"Exiting program."<<endl;
            break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;
     }
    }while(choice!=6);

    return 0;
}
