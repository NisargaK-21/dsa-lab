#include<iostream>      // Provides input-output stream functionality (cin, cout)
#include<cstring>       // Provides string handling functions like strlen()
using namespace std;    // Allows use of standard library names without std:: prefix

// Function F() defines the precedence of operators
// when they are already present in the stack
int F(char symbol){
    switch(symbol){
        case '+':case '-':return 2;   // Low precedence for + and -
        case '*':case '/':return 4;   // Higher precedence for * and /
        case '^':case '%':return 5;   // Highest precedence for ^ and %
        case '(':return 0;            // '(' has the lowest precedence in stack
        case '#':return -1;           // '#' is a stack bottom marker
        default:return 8;             // Operand (letters/numbers)
    }
}

// Function G() defines the precedence of operators
// when they come from the infix expression (input)
int G(char symbol){
    switch(symbol){
        case '+':case '-':return 1;   // Lower precedence when incoming
        case '*':case '/':return 3;   // Medium precedence
        case '^':case '%':return 6;   // Highest precedence (right associative)
        case '(':return 9;            // '(' always pushed onto stack
        case ')':return 0;            // ')' causes popping from stack
        default:return 7;             // Operand
    }
}

// Function to convert infix expression to postfix expression
void infix_to_postfix(const char infix[],char postfix[]){
   char stack[30];        // Stack to store operators
   int top=-1, j=0;       // top: stack pointer, j: postfix index

   stack[++top]='#';      // Push sentinel symbol '#' onto stack

   // Loop through each character of the infix expression
   for(int i=0;i<strlen(infix);++i){
       char symbol=infix[i];   // Read current symbol

       // Pop operators from stack while stack precedence is higher
       while(F(stack[top])>G(symbol)){
           postfix[j++]=stack[top--];  // Pop and add to postfix
       }

       // If precedence is not equal, push the symbol
       if(F(stack[top])!=G(symbol))
           stack[++top]=symbol;
       else
           top--;   // Used mainly to remove '(' when ')' is encountered
   }

   // Pop remaining operators from stack into postfix
   while(stack[top]!='#'){
       postfix[j++]=stack[top--];
   }

   postfix[j]='\0';   // Null-terminate postfix string
}

int main(){
    char infix[30], postfix[30];   // Arrays to store expressions

    cout<<"Enter a valid infix expression: ";
    cin>>infix;                    // Read infix expression (no spaces)

    infix_to_postfix(infix,postfix);  // Convert infix to postfix

    cout<<"Infix expression: "<<infix<<endl;
    cout<<"Postfix expression: "<<postfix<<endl;

    return 0;   // End of program
}
