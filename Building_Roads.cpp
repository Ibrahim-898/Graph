#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool vis[N];
vector<int> v[N];
void dfs(int src){
    //cout << src << " ";
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
    int cnt =0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
    if(!vis[i]) {
        ans.push_back(i);
        dfs(i);
        cnt++;
     }
    }
    cout << cnt-1 << endl;
    for(int i=0;i<ans.size()-1;i++){
        cout << ans[i] << " " << ans[i+1] << endl;
    }
}