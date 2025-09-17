
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct node{
    int info;
    node *next;
};

struct List{
    node *head;
    node *tail;
};

void Init(List &L){
    L.head = NULL;
    L.tail = NULL;
}

node *Createnode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

node* findMax(List L) {
    node* p = L.head;
    node* m = nullptr;
    if (p == NULL) {
        cout << "List is empty";
        return nullptr;
    }
    m = p;
    while (p != NULL) {
        if (p->info > m->info) {
            m = p;
        }
        p = p->next;
    }
    return m;
}

void addTail(List &L, int x){
    node *p = Createnode(x);
    if(L.head == NULL){
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputList(List &L, int n){
    for(int i=0;i<n;i++){
        int x; cin>>x;
        addTail(L,x);
    }
}

void outputList(List &L){
    node* p = L.head;
    if(p == NULL){
        cout<<"List is empty";
        return ;
    }
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
}

node* findElement(List L, int i) {
    node* p = L.head;
    node* m = nullptr;
    if (p == NULL) {
        cout << "List is empty";
        return nullptr;
    }
    int d = 0;
    while(p!=NULL){
        d++;
        if(d==i){
            return p;
        }
        p=p->next;
    }
    cout << "The index is invalid";
    return nullptr;
}

node *findElementFromEnd(List L, int i){
    node*p = L.head;
    int n=0;
    if(p == NULL){
        cout<<"List is empty";
        return nullptr;
    }
    while(p!=NULL){
        n++;
        p=p->next;
    }
    int real_index = n-i;
    if(real_index<0){
        cout<<"The index is invalid";
        return nullptr;
    }
    node *g = L.head;
    int d=0;
    while(g!=NULL){
        if(d==real_index){
            return g;
        }
        d++;
        g=g->next;
    }
}
int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
