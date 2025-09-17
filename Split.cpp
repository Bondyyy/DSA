
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
using
###End banned keyword*/

#include <iostream>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void init(List &l){
    l.head = l.tail = NULL;
}


Node* createNode(int x){
    Node *p = new Node;
    p->val = x;
    p->next = NULL;
    return p;
}

void add_tail(List &L, int x){
    Node *p = new Node;
    p->val = x;
    p->next = NULL;
    if(L.head == NULL){
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}

pair<List, List> split(List &L){
    List L1, L2;
    init(L1); init(L2);
    Node *start = L.head;
    Node *nextNode;
    int ind = 0;
    while(start != NULL){
        nextNode = start->next;
        start->next = NULL;
        if(ind % 2 == 0){
            add_tail(L1, start->val);
        }
        else {
            add_tail(L2, start->val);
        }
        start = nextNode;
        ind++;
    }
    L.head = L.tail = NULL;
    return {L1, L2};
}

void printList(List &L) {
    Node* temp = L.head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

//###INSERT CODE HERE -


int main()
{
    List l; init(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);


    pair<List, List> ls = split(l);

    printList(ls.first);
    printList(ls.second);

    return 0;
}
