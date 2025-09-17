/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include<iostream>
using namespace std;
struct node
{
    int info;
    node* next;
};
struct List
{
    node *head, *tail;

};
struct Hash
{
    int m;
    int n;
    float load;
    List *pL; //con tro quan ly 1 mang chua cac List
};

//###INSERT CODE HERE -
void initList(List &L){
    L.head = L.tail = NULL;
}

void initHash(Hash &H){
    H.n = 0;
    H.pL = new List[H.m];
    for(int i = 0;i<H.m;i++){
        initList(H.pL[i]);
    }
}

int hashFunc(int x, Hash H){
    return x%H.m;
}

node* createNode(int x){
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
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

void inputHash(Hash &H, int n){
    int x;
    initHash(H);
    for(int i = 0;i<n;i++){
        cin>>x;
        if((H.n+1.0)/H.m>H.load){
            continue;
        }
        int ind = hashFunc(x,H);
        addTail(H.pL[ind],x);
    }
}

void printList(List L){
    node* p = L.head;
    while(p!=NULL){
        cout<<p->info<<" ";
        p = p->next;
    }
}
void printHash(Hash H){
    for(int i=0;i<H.m;i++){
        cout<<"List "<<i<<": ";
        printList(H.pL[i]);
        cout<<endl;
    }
}

void searchHash(Hash H, int x){
    int dem = 0;
    int ind = hashFunc(x,H);
    List L = H.pL[ind];
    node* p = L.head;
    while(p!=NULL){
        if(p->info == x){
            cout<<dem+1<<endl;
            break;
        }
        dem++;
        p = p->next;
    }
    if(dem == 0){
        cout<<"Khong"<<endl;
    }
}

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    Hash H;  cin>>H.m>>H.load;
    int n;cin>>n;
    inputHash(H,n);
    printHash(H);
    int nkey,key;cin>>nkey;

    for(int i=0;i<nkey;i++)
    {
        cin>>key;
        searchHash(H,key);
    }
    return 0;
}
