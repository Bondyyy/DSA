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

node* getNode(int x){
    node *p = new node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Tree &T, int x){
    if(T==NULL){
        T=getNode(x);
    }
    if(x>T->data){
        insertNode(T->right,x);
    }
    else if(x<T->data){
        insertNode(T->left,x);
    }
}

void inputTree (Tree &T){
    int n; cin>>n;
    int x;
    while(n--){
        cin>>x;
        insertNode(T,x);
    }
}

void LNR(Tree T){
    if(T==NULL) return ;
    LNR(T->left);
    cout<<T->data<<" ";
    LNR(T->right);
}

int height(Tree T){
    if(T==NULL) return -1;
    int d=0;
    if(T!=NULL){
        d=1;
    }
    return d+ max(height(T->left),height(T->right));
}

bool full_binary_tree(Tree T){
    if(T==NULL) return true;
    if(T->left !=NULL && T-> right == NULL){
        return false;
    }
    if(T->right !=NULL && T-> left == NULL){
        return false;
    }
    return full_binary_tree(T->left) && full_binary_tree(T->right);
}


bool check_same_leaf(Tree T, int height, int maxx){
    if(T==NULL) return true ;
    if(T->left == NULL && T->right ==NULL){
        if(height != maxx){
            return false;
        }
    }
    return check_same_leaf(T->left,height +1,maxx) && check_same_leaf(T->right,height+1,maxx);
}

int isSpecialBST(Tree T){
    if(T==NULL){
        return true;
    }
    if(full_binary_tree(T) && check_same_leaf(T,0,height(T))){
        return true;
    }
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isSpecialBST (T);
	if(i==0) cout<<"\nThe tree is not a (My)Special-BST";
    else cout<<"\nThe tree is a (My)Special-BST";
	return 0;
}


