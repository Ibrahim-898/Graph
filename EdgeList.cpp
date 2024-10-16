#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> v;
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    for(auto u:v){
        cout << u.first << " " << u.second  << endl;
    }
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

}