#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <tuple>
using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

void dfs(int start, vector<vector<int>> dsk)
{
    int soDinh = dsk.size();
    stack<int> S;
    vector<bool> visited(soDinh, false);

    S.push(start);

    while (S.empty() == false)
    {
        int u = S.top();
        S.pop();

        if (visited[u] == true)
        {
            continue;
        }
        visited[u] = true;
        cout << u << " ";
        for (int i = 0; i < dsk[u].size(); i++)
        {
            if (visited[dsk[u][i]] == false)
            {
                S.push(dsk[u][i]);
            }
        }
    }
}

void bfs(int start, vector<vector<int>> dsk)
{
    int soDinh = dsk.size();
    vector<int> visited(soDinh, false);
    queue<int> Q;

    Q.push(start);
    visited[start] = true;
    while (Q.empty() == false)
    {
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        for (int i = 0; i < dsk[u].size(); i++)
        {
            int nei = dsk[u][i];
            if (visited[nei] == false)
            {
                visited[nei] = true;
                Q.push(nei);
            }
        }
    }
}

int main()
{
    int n, m, s; // n: dinh, m:canh, s:dinh duyet
    cin >> n >> m >> s;
    vector<vector<int>> dsk(n + 1);
    pair<int, int> point;
    for (int i = 0; i < m; i++)
    {
        cin >> point.first >> point.second;
        dsk[point.first].push_back(point.second);
    }
    for (int i = 1; i < n + 1; i++)
    {
        sort(dsk[i].begin(), dsk[i].end());
    }
    bfs(s, dsk);
}