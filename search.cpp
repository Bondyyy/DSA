
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

Node* Search(Tree T, int x){
    if(T== NULL) return NULL;
    if(x == T->info) return T;
    if(x<T->info) return Search(T->left,x);
    return Search(T->right,x);
}

int minValue(Tree T) {
    if(T->left != NULL){
        return minValue(T->left);
    }
    return T->info;
}

int maxValue(Tree T) {
    if(T->right != NULL){
        return maxValue(T->right);
    }
    return T->info;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
