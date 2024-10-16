#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> v[N];
int parent[N];
bool ans=false;
bool vis[N];
void dfs(int src){
    vis[src]=true;
    for(auto u:v[src]){
    if(vis[u] && parent[src]!=u) ans=true;
    if(!vis[u]){
        parent[u]=src;
        dfs(u);
        
    }
    }

}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--){
        int x,y;
        cin >>x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<n;i++){
       if(!vis[i]) dfs(i);
    }
    if(ans) cout << "Cycle Found" << endl;
    else cout << "NO Cycle Found" << endl;
}