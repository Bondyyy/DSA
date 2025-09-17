#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> dsk, int m, int start, int end){
    vector<bool> visited(m, false);
    vector<int> path;
    stack<int> open;
    open.push(start);
    visited[start] = true;
    while (!open.empty()) {
        int p = open.top();
        open.pop();
        for (int i = 0; i < dsk[p].size(); i++) {
            if (!visited[dsk[p][i]]) {
                open.push(dsk[p][i]);
                path.push_back(dsk[p][i]);
                visited[dsk[p][i]] = true;
            }
        }
    }
    return path;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m; cin>>m;
    int n; cin>>n;
    //m là đỉnh, n là cạnh;
    vector<vector<int>> dsk(m,vector<int>(m));
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        dsk[x].push_back(y);
        dsk[y].push_back(x);
    }
    vector<int> p = DFS(dsk, m, 0);
    if(p.empty()){
        cout<<"KHONG";
    }
    else {
        sort(p.begin(),p.end());
        for(int x:p){
            cout<<x<<" ";
        }
    }
}
