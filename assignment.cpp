#include<iostream>
#include<string>
using namespace std;

#define MAX 100

class Stack{
    private:
    string arr[MAX];
    int top;

    public:
    Stack(){
        top=-1;
    }
       void push(string s) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << s << endl;
        } else {
            arr[++top] = s;
        }
    }
    string pop() {
        if (top == -1) {
            return ""; 
        } else {
            return arr[top--];
        }
    }
    string topElement() {
        if (top == -1) return "";
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};


int main(){
    string s;
    cout<<"Enter HTML/XML string:\n";
    getline(cin,s);
    
    Stack st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='<'){
            int j=s.find('>',i);
            if(j==-1){
                cout<<"Not valid\n";
                return 0;
            }
            string tag=s.substr(i+1,j-i-1);

            if(tag.length()==0){
                cout<<"Not valid\n";
                return 0;
            }

            if(tag[0]!='/'){
                st.push(tag);
            }else{
                string closeTag=tag.substr(1);

                if(st.empty()||st.topElement()!=closeTag){
                    cout<<"Not valid\n";
                    return 0;
                }
                st.pop();
            }
            i=j;
            }
    }
    if(st.empty()){
        cout<<"Valid\n";
    }else{
        cout<<"Not valid\n";
    }   
    return 0;

}