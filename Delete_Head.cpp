#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node * next;
};

struct List{
    node *head;
    node *tail;
};

void init(List &L){
    L.head = NULL;
    L.tail = NULL;
}

node *CreateNode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addHead(List &L, int x){
    node *p = CreateNode(x);
    if(L.head ==NULL){
        L.head = L.tail = p;
    }
    else {
        p->next = L.head;
        L.head = p;
    }
}

void addTail(List &L, int x){
    node *p = CreateNode(x);
    if(L.head == NULL){
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}

void addMid(List &L,int a, int b){
    node *p = CreateNode(b);
    node *start = L.head;
    bool check = true;
    while(start != NULL){
        if(start->info == a){
            check = false;
            break;
        }
        start = start->next;
    }
    if(check == false){
        p->next = start->next;
        start->next = p;
        if(start == L.tail){
            L.tail = p;
        }
    }
    else addHead(L,b);
}

void delHead(List &L){
    if(L.head == NULL){
        return;
    }
    node *p = L.head;
    L.head = L.head->next;
    if(L.head == NULL){
        L.tail = NULL;
    }
    delete p;
}

void delMid(List &L){

}
void in(List &L) {
    node* p = L.head;
    if(p == NULL){
        cout<<"blank";
        return ;
    }
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    List L;
    init (L);
    while(1){
        int x; cin>>x;
        if(x==6){
            break;
        }
        if(x==0){
            int y; cin>>y;
            addHead(L,y);
        }
        else if(x==1){
            int y; cin>>y;
            addTail(L,y);
        }
        else if(x==2){
            int y; cin>>y;
            int b;
            cin>>b;
            addMid(L,y,b);
        }
        else if(x==5){
            delHead(L);
        }
    }
    in(L);
}
