
#include <bits/stdc++.h>
using namespace std;

// Tự cài đặt danh sách liên
struct node{
    int info; // Nếu như có nhiều info tức là ví dụ sinh viên thì struct sv
    node *next;
};

struct List{
    // thêm đầu và cuối để dễ quản lí danh sách liên kết
    node *head;
    node *tail;
    //int n;
};

void init(List &L){
    // Khởi tạo dslk
    L.head = L.tail = NULL;
    //L.n = 0;
}

node* createNode(int x){
    node *p = new node;
    // if(p==NULL){
    //     cout<<"Không đủ bộ nhớ";
    // }
    p->info = x;
    p->next = NULL;
    // Hàm trả về biến vừa tạo để tí sử dụng nó
    return p;
}
void addHead(List &L, int x){
    // B1: Tạo ra 1 node (biến động) chứa x
    node *p = createNode(x);
    // B2: Gắn node mới tạo vào đầu.
    if(L.head == NULL){
        L.head = L.tail = p;
    }
    else {
        p->next = L.head;
        L.head = p;
    }
}

void addTail(List &L, int x){
    node *p = createNode(x);
    if(L.head == NULL){
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}
void printList(List L){
    node *p = L.head;
    while(p != NULL){
        cout<<p->info<<" ";
        p = p->next;
    }
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    List L;// con trỏ thì xài -> còn biến thì .
    init(L);
    while(1){
        int x; cin>>x;
        if(x==3){
            break;
        }
        int y; cin>>y;
        if(x==0){
            addHead(L,y);
        }
        else if(x==1){
            addTail(L,y);
        }
    }
    printList(L);
}
