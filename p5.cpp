#include<iostream>
#include<cmath>
#include<cctype>

using namespace std;

int arr[20];
int top = -1;

void push(int x){
    arr[++top] = x;
}

int pop(){
    return arr[top--];
}

int main(){
    char postfix[20];
    cout<<"Enter postfix expression: ";
    cin>>postfix;

    for(int i=0;postfix[i]!='\0';i++){
        char symb=postfix[i];

        if(isdigit(symb)){
            push(symb-'0');
        }else{
            int op2=pop();
            int op1=pop();
            int res=0;

            switch (symb)
            {
            case '+':
              res=op1+op2;
                break;
            case '-':
              res=op1-op2;
                break;
            case '*':
              res=op1*op2;
                break;
            case '/':
              res=op1/op2;
                break;
            case '%':
              res=op1+op2;
                break;
            case '^':
              res=pow(op1,op2);
                break;
            }
            push(res);
        }
    }
    cout<<"Result: "<<pop()<<endl;
    return 0;
}