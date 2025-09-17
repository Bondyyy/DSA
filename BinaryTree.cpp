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

// void insertNode(Tree &T, int x){
//     if(T==NULL){
//         T = getNode(x);
//     }
//     else if(x>T->data){
//         insertNode(T->right,x);
//     }
//     else {
//         insertNode(T->left,x);
//     }
// }

Tree Search(Tree T, int b){
    if(T == NULL) return NULL;
    if(T->data == b) return T;

    Tree p = Search(T->left, b);
    if(p != NULL) return p;

    return Search(T->right, b);
}

void SetLeft(Tree T, int c){
    if(T==NULL){
        return ;
    }
    if(T->left != NULL){
        return ;
    }
    T->left = getNode(c);
}

void SetRight(Tree T, int c){
    if(T==NULL){
        return ;
    }
    if(T->right != NULL){
        return ;
    }
    T->right = getNode(c);
}

void LNR(Tree T){
    if(T==NULL){
        return ;
    }
    LNR(T->left);
    cout<<T->data<<" ";
    LNR(T->right);
}

bool is_Leaf(Tree T){
    if(T == NULL){
        return false;
    }
    if(T->left == NULL && T->right ==NULL){
        return true;
    }
    return false;
}

void DeleteLeft(Tree T){
    if(T==NULL){
        cout<<"Node khong ton tai\n";
        return ;
    }
    if(T->left == NULL){
        cout << "Khong co node ben trai\n";
        return ;
    }
    if(is_Leaf(T->left)==false){
        cout << "Khong la node la nen khong xoa duoc\n";
        return ;
    }
    delete(T->left);
    T->left = NULL;
}

void DeleteRight(Tree T){
    if(T==NULL){
        cout<<"Node khong ton tai\n";
        return ;
    }
    if(T->right == NULL){
        cout << "Khong co node ben phai\n";
        return ;
    }
    if(is_Leaf(T->right)==false){
        cout << "Khong la node la nen khong xoa duoc\n";
        return ;
    }
    delete(T->right);
    T->right = NULL;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}
