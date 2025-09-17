#include <bits/stdc++.h>
using namespace std;

int main()
{

    set<pair<string, string>> se;
    int n;
    cin >> n;
    string a, b;
    set<string> names;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        se.insert({a, b});
        names.insert(a);
        names.insert(b);
    }
    vector<string> name2(names.begin(), names.end());
    for (int i = 0; i < name2.size(); i++)
    {
        for (int j = i + 1; j < name2.size(); j++)
        {
            if (name2[i] != name2[j])
            {
                if (se.find({name2[i], name2[j]}) == se.end() || se.find({name2[j], name2[i]}) == se.end())
                {
                    cout << "FALSE";
                    return 0;
                }
            }
        }
    }
    cout << "TRUE";
}
