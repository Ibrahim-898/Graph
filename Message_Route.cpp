#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
bool vis[N];
 int level[N];
  int path[N];
  int n,e;
   vector<int> v[N];
   void shortestPathUnweighted(int src,int des){
queue<int> q;
q.push(src);
vis[src]=true;
while(!q.empty()){
    int p = q.front();
    q.pop();
    for(auto u:v[p]){
       if(vis[u]==false) {
        q.push(u);
        vis[u]=true;
        path[u]=p;
       }
        //cout << "level "  << i << ":" << endl;
    }
}
vector<int> ans;
ans.push_back(des);
while(path[des]!=-1){
    ans.push_back(path[des]);
    des = path[des];

}
reverse(ans.begin(),ans.end());
if(ans.size()==1) {
    cout << "IMPOSSIBLE" << endl;
    return;
}
cout << ans.size() << endl;
for(auto u:ans){
    cout << u << " ";
}
}
int main()
{
     memset(vis,false,sizeof(vis));
     memset(level,-1,sizeof(level));
     memset(path,-1,sizeof(path));
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    //bfs(1);
    shortestPathUnweighted(1,n);

}