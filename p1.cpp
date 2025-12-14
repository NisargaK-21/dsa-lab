#include<iostream>
using namespace std;

int main(){
    int MAX_VALUE=10;
    int data[100],size;
    int freq[MAX_VALUE+1]={0};
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter "<<size<<" numbers between 1 and "<<MAX_VALUE<<": ";
    for(int i=0;i<size;i++){
        cin>>data[i];
        if(data[i]>=1 && data[i]<=MAX_VALUE){
            freq[data[i]]++;
        }
    }

    cout<<"\nHistogram\n";
    for(int i=1;i<=MAX_VALUE;i++){
       cout<<i<<" : ";
       for(int j=1;j<freq[i];j++){
           cout<<"*";
       }
       cout<<endl;
    }
}