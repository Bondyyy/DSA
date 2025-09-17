
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct node{
    int data;
    node* left;
    node* right;
};

typedef node* Tree;

node* getNode (int x){
    node* p = new node;
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(Tree &T, int x){
    if(T==NULL){
        T = getNode(x);
    }
    if(x == T->data){
        return;
    }
    if(x>T->data){
        insertNode(T->right, x);
    }
    if(x<T->data){
        insertNode(T->left, x);
    }
}

void inputTree(Tree &T){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        insertNode(T,x);
    }
}

void NLR(Tree T){
    if(T==NULL) return;
    cout<<T->data<<" ";
    NLR(T->left);
    NLR(T->right);
}

void ThayThe(Tree &p, Tree &T){
    if(T->left !=NULL){
        ThayThe(p,T->left);
    }
    else{
        p->data = T->data;
        p = T;
        T = T->right;
    }
}

void delete_root(Tree &T){
    if (T == NULL) return;

    Tree p = T;
    if (T->left == NULL) {
        T = T->right;
    }
    else if (T->right == NULL) {
        T = T->left;
    }
    else {
        ThayThe(p, T->right);
    }
    delete p;
}

void deleteRoot(Tree &T, int m){
    for(int i=0;i<m;i++){
        delete_root(T);
    }
}

void deleteNode(Tree &T, int x){
    if(T==NULL) return;
    if (x > T->data) {
        deleteNode(T->right, x);
    } else if (x < T->data) {
        deleteNode(T->left, x);
    } else if (x == T->data) {
        Tree p = T;
        if (T->left == NULL) {
            T = T->right;
        } else if (T->right == NULL) {
            T = T->left;
        } else {
            ThayThe(p, T->right);
        }
        delete p;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}

