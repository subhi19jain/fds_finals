#include<iostream>
#include <stack>

using namespace std;
#define size 10

class Stackexp{
 int top;
 char stk[size];
 public:
  Stackexp(){
    top=-1;
  }
  void push(char);
  char pop();
  int isfull();
  int isempty();



};

void Stackexp::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char Stackexp::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}
int Stackexp::isfull()
{
if(top==size){
    return 1;}
else{
  return 0;
}
}
int Stackexp::isempty()
{
if(top==-1){
    return 1;}
else{
  return 0;
}

}
int main(){
    Stackexp s1;
    char exp[20],ch;
    int i=0;

    cout<<"Parenthesis checker"<<endl;
    cout<<"enter expression to be checked "<<endl;
    cin>>exp;

    if((exp[0]==')')||(exp[0]==']'||exp[0]=='}'))
    {
        cout<<"enter valid expression first "<<endl;
        return 0;
    }
    else {

        while (exp[i]!='\0'){//check null character 
            ch=exp[i];
            switch(ch)
            {
                case '(': s1.push(ch);break;
                case '{': s1.push(ch);break;
                case '[': s1.push(ch);break;
                case ')': s1.pop();break;
                case '}': s1.pop();break;
                case ']': s1.pop();break;

            }
            i+=1;

        }
        if (s1.isempty())
        {
         cout<< "expression is well parentised"<<endl;

        }
        else 
        {
            cout<< " enter valid expression first "<< endl;
        }
    }
    return 0;
}
