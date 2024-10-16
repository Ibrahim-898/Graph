#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
bool vis[N];
vector<int> v[N];
void dfs(int src){
    cout << src << " ";
    vis[src]=true;
    for(auto u:v[src]){
        if(vis[u]==false){
            dfs(u);
        }
        }
}
int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(vis,false,sizeof(vis));
    int src;
    cin >> src;
    dfs(src);
}