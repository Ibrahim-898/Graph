#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> v[N];
bool vis[N];
bool ans;
int parent[N];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto u:v[p]){
            if(vis[u] && parent[p]!=u) ans=true;
        if(vis[u]==false){
            q.push(u);
            vis[u]=true;
            parent[u]=p;
        }
        }
    }
}
int main(){
    int n,e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); 
    }
    ans = false;
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    if(ans){
        cout << "Cycle Found" << endl;
    }
    else cout << "No Cycle Found" << endl;
}