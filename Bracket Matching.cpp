/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -
struct Stack{
    int n;
    char a[MAX];
};

void Init(Stack &s){
    s.n = 0;
}

void Push(Stack &s, char st){
    if(s.n == MAX){
        return ;
    }
    s.a[s.n] = st;
    s.n++;
}

bool Isempty(Stack s){
    if(s.n == 0){
        return true;
    }
    return false;
}

void Pop(Stack &s){
    if(Isempty(s)==true){
        return ;
    }
    s.n--;
}

char Top(Stack s){
    return s.a[s.n-1];
}
bool isValid(string str){
    Stack s; Init(s);
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '('|| c == '{' || c == '[') {
            Push(s, c);
        }
        else if (c == ')' || c=='}' || c==']') {
            if (Isempty(s)) {
                return false;
            }
            if(c==')' && Top(s) == '(' || c=='}' && Top(s) == '{' || c==']' && Top(s)=='['){
                Pop(s);
            }
        }
    }
    if(Isempty(s)==true){
        return true;
    }
    return false;
}
int main()
{
    string expr; cin>>expr;
    cout<< isValid(expr);

    return 0;
}



