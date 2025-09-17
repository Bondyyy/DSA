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

void inputTree(Tree &T){
	int n,x; cin>>n;
	int a[101];
	for (int i=0;i<n;i++){
		cin>>x;
		a[x]++;
		if(a[x]!=1){
			insertNode(T,x);
		}
		else break;
	}
}

void NLR(Tree T){
	if(T==NULL) return ;
	cout<<T->info<<" ";
	NLR(T->left);
	NLR(T->right);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout<<"NLR: "; NLR(T);
	return 0;
}

