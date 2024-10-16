#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin >> n >> e;
    vector<int> v[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(auto u:v)
    {
        for(auto x:v[0]){
            cout << x << " ";
        }
        cout << endl;
    }

}