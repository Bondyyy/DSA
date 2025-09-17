/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(int a[50][50], int &n, int &m){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
}

void outputMatrix(int a[50][50], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void uniqueElements(int a[50][50], int n, int m) {
    int maxx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxx = max(maxx, a[i][j]);
        }
    }

    int *Hash = new int [maxx+1]{0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Hash[a[i][j]]++;
        }
    }

    bool found = false;

    for (int i = 0; i <= maxx; i++) {
        if (Hash[i] == 1) {
            found = true;
        }
    }

    if (!found) {
        cout << "No unique element in the matrix";
        return ;
    }

    cout<<"Unique elements in the matrix:\n";
    for(int i=0;i<=maxx;i++){
        if(Hash[i]==1){
            cout<<i<<" ";
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}



