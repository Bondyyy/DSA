
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Node{
	int info;
	Node *left, *right;
};

typedef Node* Tree;

Node *getNode(int x){
	Node *p = new Node;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

void insertNode(Tree &T, int x){
	if(T==NULL){
		T = getNode(x);
	}
	if(x == T->info){
		return;
	}
	if(x<T->info){
		insertNode(T->left,x);
	}	else {
		insertNode(T->right,x);
	}
}

bool existsInTree(Tree T, int x) {
    if (T == NULL) return false;
    if (T->info== x) return true;
    if (x<T->info) return existsInTree(T->left, x);
    if (x>T->info) return existsInTree(T->right, x);
}

void inputTree(Tree &T){
	int n,x; cin>>n;
	for (int i=0;i<n;i++){
		cin>>x;
        if(existsInTree(T, x) == true) {
            cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
            break;
        } else {
            insertNode(T, x);
        }
    }
}

void NLR(Tree T){
	if(T==NULL) return ;
	cout<<T->info<<" ";
	NLR(T->left);
	NLR(T->right);
}

void LRN(Tree T){
    if(T==NULL) return ;
    LRN(T->left);
    LRN(T->right);
    cout<<T->info<<" ";
}

void LNR(Tree T){
    if(T==NULL) return ;
    LNR(T->left);
    cout<<T->info<<" ";
    LNR(T->right);
}

void listLeafs(Tree T){
    if(T == NULL) return ;
    if(T->left == NULL && T->right == NULL){
        cout<<T->info<<" ";
    }
    listLeafs(T->left);
    listLeafs(T->right);
}

void listInternalNodes(Tree T, int x) {
    if (T == NULL) return;
    if (x == true && ((T->left != NULL && T->right != NULL) || (T->left != NULL && T->right == NULL) || (T->left == NULL && T->right != NULL))){
        cout << T->info << " ";
    }
    listInternalNodes(T->left, true);
    listInternalNodes(T->right, true);
}


void listNodesWithOneChild(Tree T){
    if(T == NULL) return ;
    if((T->left != NULL && T->right == NULL) || (T->left == NULL && T->right != NULL)) {
        cout<<T->info<<" ";
    }
    listNodesWithOneChild(T->left);
    listNodesWithOneChild(T->right);
}

void listNodesWithTwoChildren(Tree T){
    if(T == NULL) return ;
    if(T->left != NULL && T->right != NULL) {
        cout<<T->info<<" ";
    }
    listNodesWithTwoChildren(T->left);
    listNodesWithTwoChildren(T->right);
}

int countNodes(Tree T) {
    if (T == NULL) return 0;
    int dem = 0;
    if (T->info != NULL) {
        dem ++;
    }
    return dem + countNodes(T->left) + countNodes(T->right);
}

int countLeafs(Tree &T){
    if(T == NULL) return 0;
    int dem = 0;
    if(T->left == NULL && T->right == NULL){
        dem ++;
    }
    return dem + countLeafs(T->left) + countLeafs(T->right);
}

int countInternalNodes(Tree T){
    return max(countNodes(T) - countLeafs(T) -1,0);
}

int countOneChild(Tree T){
    if(T == NULL) return 0;
    int dem=0;
    if((T->left != NULL && T->right == NULL) || (T->left == NULL && T->right != NULL)) {
        dem = 1;
    }
    return dem + countOneChild(T->left) + countOneChild(T->right);
}

int countTwoChildren(Tree T){
    if(T == NULL) return 0;
    int dem = 0;
    if(T->left != NULL && T->right != NULL) {
        dem++;
    }
    return dem+countTwoChildren(T->left)+ countTwoChildren(T->right);
}

int countLess(Tree T, int x){
    if(T==NULL) return 0;
    int dem = 0;
    if(x>T->info){
        dem++;
    }
    return dem + countLess(T->left,x) +countLess(T->right, x);
}

int countBetweenValues(Tree T, int x, int y){
    if(T==NULL) return 0;
    int dem = 0;
    if(x<T->info&&T->info<y){
        dem++;
    }
    return dem + countBetweenValues(T->left, x,y) +countBetweenValues(T->right, x, y);
}

int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
