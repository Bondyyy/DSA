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
    node *pHead;
    node *pTail;
};

void Init(List &L){
    L.pHead = NULL;
    L.pTail = NULL;
}

node *Createnode(int x){
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

node* findMax(List L) {
    node* p = L.pHead;
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

void addpTail(List &L, int x){
    node *p = Createnode(x);
    if(L.pHead == NULL){
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void inputList(List &L, int n){
    for(int i=0;i<n;i++){
        int x; cin>>x;
        addpTail(L,x);
    }
}

void outputList(List &L){
    node* p = L.pHead;
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
    node* p = L.pHead;
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
    node*p = L.pHead;
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
    node *g = L.pHead;
    int d=0;
    while(g!=NULL){
        if(d==real_index){
            return g;
        }
        d++;
        g=g->next;
    }
}

node *swapData(List &L, int x, int y){
    node *start_x =L.pHead;
    node *start_y = L.pHead;
    while(start_x!=NULL){
        if(start_x->info == x){
            break;
        }
        start_x = start_x->next;
    }
    while(start_y!=NULL){
        if(start_y->info == y){
            break;
        }
        start_y = start_y->next;
    }
    if(start_x == NULL||start_y==NULL) return NULL;
    swap(start_x->info,start_y->info);
    return start_x;
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}

