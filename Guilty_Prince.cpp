#include<bits/stdc++.h>
using namespace std;
const int N=21;
int n,m;
char a[N][N];
bool vis[N][N];
int level[N][N];
vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j){
   if(i<0 || i>=m || j<0 || j>=n) return false;
   if(a[i][j]=='#') return false;
   return true;
}
int bfs(int src1,int src2){
    queue<pair<int,int>> q;
    q.push({src1,src2});
    vis[src1][src2]=true;
    level[src1][src2]=0;
    int cnt=0;
   while(!q.empty()){
        pair<int,int> p = q.front();
        cnt++;
        q.pop();
        for(auto u:v){
        int ci = p.first+u.first;
        int cj = p.second+u.second;
        if(isValid(ci,cj) && !vis[ci][cj]){
            q.push({ci,cj});
            vis[ci][cj]=true;
            level[ci][cj]=level[p.first][p.second]+1; 
        }
        }  
      }
      return cnt;
}
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
         memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    int src1,src2;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j]; 
        if(a[i][j]=='@'){
            src1=i;
            src2=j;
          }
        }
    }
   int res = bfs(src1,src2);
   cout << "Case " <<  i << ": " <<  res << endl;
   }
}