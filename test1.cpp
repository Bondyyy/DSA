#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *right;
    Node *left;
};

typedef Node* Tree;

Tree getNode(int x){
    Tree newNode = new Node;
    newNode->data =x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(Tree &T, int x, int y, char c){
    if(T==NULL){
        return ;
    }
    if(T->data == x){
        if(c == 'L'){
            T->left =getNode(y);
        }
        else T->right = getNode(y);
    }
    insertNode(T->left, x, y, c);
    insertNode(T->right, x, y ,c);
}


void print_xoan_oc(Tree T){
    if(T==NULL) return ;
    queue<Tree> q;
    q.push(T);
    int dem = 0;

    while(!q.empty()){
        int size_of_level = q.size();
        vector<int> store_same_level;

        for(int i = 0 ;i<size_of_level; i++){
            Tree cur = q.front();
            store_same_level.push_back(cur->data);
            q.pop();
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }

        if(dem % 2 != 0){
            for(auto x:store_same_level){
                cout<<x<<" ";
            }
        }
        else if(dem%2 ==0){
            for(int i = store_same_level.size()-1;i>=0;i--){
                cout<<store_same_level[i]<<" ";
            }
        }
        dem++;
    }
}
