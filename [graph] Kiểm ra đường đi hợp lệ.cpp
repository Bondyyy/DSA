#include <bits/stdc++.h>
    using namespace std;

    int main()
    {

        int e,n;
        cin>>e>>n;
        //e: số cạnh
        map<string,map<string,int>> mp;
        string x,y; int p;
        for(int i=0;i<e;i++){
            cin>>x>>y>>p;
            mp[x][y] = p;
        }
        string path;
        while(n--){
            vector<string>paths;
            while(cin>>path){
                if(path=="."){
                    break;
                }
                else if (mp.count(path)==0){
                    cout<<"FALSE";
                    return 0;
                }
                else paths.push_back(path);
            }
            if(paths.size()<=1 || paths.front()!=paths.back()){
                cout<<"FALSE";
                break;
            }

            int total = 0;
            bool check = true;
            for(int i=0;i<paths.size()-1;i++){
                string a = paths[i];
                string b = paths[i+1];
                if (mp[a].count(b)!=0) {
                    total += mp[a][b];
                } else {
                    check=false;
                    break;
                }
            }
            if(check == false){
            cout<<"FALSE"<<endl;
            }
            else cout<<total<<endl;
        }
    }
