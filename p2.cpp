#include<iostream>
using namespace std;

int length(const char str[]){
   int i=0;
   while(str[i]!='\0'){
    i++;
   }
   return i;
}


bool match(const char str[], const char pat[],int pos){
  int i=0;
  while(pat[i]!='\0'){
    if(str[pos+i]!=pat[i]){
        return false;
    }
    i++;
  }
  return true;
}


int main(){
 const int MAX=100;
 char str[MAX],pat[MAX],res[MAX],rep[MAX];
 cout<<"Enter the main string: ";
 cin.getline(str,MAX);
 cout<<"Enter the pattern string: ";
 cin.getline(pat,MAX);
 cout<<"Enter the replace string: ";
 cin.getline(rep,MAX);

 int lenstr=length(str);
 int lenpat=length(pat);
 int lenrep=length(rep);


 bool found=false;
int i=0,k=0;
 while(i<lenstr){
  if(i<=lenstr-lenpat && match(str,pat,i)){
    for(int j=0;j<lenrep;j++){
        res[k++]=rep[j];
    }
  i+=lenpat;
  found=true;
 }else{
    res[k++]=str[i++];
 }
}
res[k]='\0';

if(!found){
    cout<<"Pattern not found"<<endl;
}else{
    cout<<"Resultant string is: "<<res<<endl;
}

return 0;
}