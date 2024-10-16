#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
bool vis[N];
int level[N];
int bfs(vector<int> v[],int src,int n,int des){
queue<int> q;
q.push(src);
vis[src]=true;
level[src]=0;

while(!q.empty()){
    int p = q.front();
    //cout << p <<  " ";
    q.pop();
    for(auto u:v[p]){
       if(vis[u]==false) {
        q.push(u);
        vis[u]=true;
        level[u]=level[p]+1;
        if(u==des){
            return level[u];
        }
       }
    }
}
 return  -1;
}
int main(){
     memset(vis,false,sizeof(vis));
     memset(level,-1,sizeof(level));
    int n,e;
    cin >> n >> e;
    vector<int> v[n];
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int src,des,c;
    cin >> src >> des >> c;
 int res =  bfs(v,src,n,des);
   if(res==-1) cout << "NO" << endl;
  else {
    if(res<=c*2)
cout << "YES" << endl;
else cout << "NO" << endl;
  }


}