#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> v[N];
bool pathvisit[N];
bool ans=false;
bool vis[N];
void dfs(int src){
    vis[src]=true;
     pathvisit[src]=true;
    for(auto u:v[src]){
        if(pathvisit[u]) ans=true;
    if(!vis[u]){
        dfs(u);   
    }
    }
    pathvisit[src]=false;

}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--){
        int x,y;
        cin >>x >> y;
        v[x].push_back(y);
    }
    memset(vis,false,sizeof(vis));
    memset(pathvisit,false,sizeof(pathvisit));
    for(int i=0;i<n;i++){
       if(!vis[i]) dfs(i);
    }
    if(ans) cout << "Cycle Found" << endl;
    else cout << "NO Cycle Found" << endl;
}