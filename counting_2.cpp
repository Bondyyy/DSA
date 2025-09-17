
#include <iostream>
using namespace std;

bool isPrime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

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

void LNR(Tree T){
    if(T==NULL) return;
    LNR(T->left);
    cout<<T->data<<" ";
    LNR(T->right);
}

int countNodes(Tree T) {
    if (T == NULL) return 0;
    int dem = 0;
    if (T != NULL) {
        dem ++;
    }
    return dem + countNodes(T->left) + countNodes(T->right);
}

int depthOfTree(Tree T){
    if(T==NULL) return -1;
    int dem = 0;
    if(T!=NULL){
        dem++;
    }
    return dem + max(depthOfTree(T->left),depthOfTree(T->right));
}

void countEven(Tree T, int &count_even) {
    if (T == NULL) return;
    if (T->data % 2 == 0) {
        count_even++;
    }
    countEven(T->left, count_even);
    countEven(T->right, count_even);
}

void countOdd(Tree T, int &count_odd) {
    if (T == NULL) return;
    if (T->data % 2 != 0) {
        count_odd++;
    }
    countOdd(T->left, count_odd);
    countOdd(T->right, count_odd);
}

int countPositive(Tree T) {
    if (T == NULL) return 0;
    int dem = 0;
    if (T->data > 0) {
        dem++;
    }
    return countPositive(T->left) + countPositive(T->right) + dem;
}

int countNegative(Tree T) {
    if (T == NULL) return 0;
    int dem = 0;
    if (T->data < 0) {
        dem++;
    }
    return countNegative(T->left) + countNegative(T->right) + dem;
}

int countPrime(Tree T){
    if(T==NULL) return 0;
    int dem = 0;
    if(isPrime(T->data)==true){
        dem++;
    }
    return countPrime(T->left) + countPrime(T->right) + dem;
}

void listPrime(Tree T){
    if(T==NULL) return;
    if(isPrime(T->data)==true){
        cout<<T->data<<" ";
    }
    listPrime(T->left);
    listPrime(T->right);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}

