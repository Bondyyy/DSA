#include<bits/stdc++.h>
using namespace std;

struct node{
	int info;
	node *left, *right;
};

// struct Tree{
// 	node *root;
// } chỉ có 1 kiểu dữ liệu nên không cần xài struct


typedef node* Tree; //typedef dùng để đặt tên khác cho 1 kiểu dữ liệu có sẵn
//hamf(node * T) == hamf(Tree T)

node* getNode(int x){
	node *p=new node;
	p->info =x;
	p->left = p->right = NULL;
	return p;
}

void insertNode(Tree &T, int x){
	if(T==NULL /*if(!T)*/){
		T = getNode(x);
	}
	if(x == T->info) return ;
	if(x<T->info){
		insertNode(T->left,x);
	}	else {
		insertNode(T->right,x);
	}
}

void inputTree(Tree &T){//tham chiếu vì cây có thể thay đổi
	int n,x; cin>>n;
	for (int i=0;i<n;i++){
		cin>>x;
		//tạo ra 1 node chứa x rồi gắn vào cây;
		insertNode(T,x);
	}
}

void NLR(Tree T){
	if(T == NULL){
		return;
	}
	cout<<T->info<<" ";
	NLR(T->left);
	NLR(T->right);
}

void LRN(Tree T){
	if(T==NULL){
		return ;
	}
	LRN(T->left);
	LRN(T->right);
	cout<<T->info<<" ";
}
void LNR(Tree T){
	if(T==NULL){
		return;
	}
	LNR(T->left);
	cout<<T->info<<" ";
	LNR(T->right);
}

Tree Search(Tree T, int x){
	if(x == T->info){
		return T;
	}
	if(x<T->info){
		Search(T->left,x);
	} else {
		Search(T->right,x);
	}
	return NULL;
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
