#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m;
char a[N][N];
bool vis[N][N];
int level[N][N];
vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
void bfs(int src1,int src2){
    queue<pair<int,int>> q;
    q.push({src1,src2});
   // cout << q.front().first << endl;
    vis[src1][src2]=true;
    level[src1][src2]=0;
   while(!q.empty()){
        pair<int,int> p = q.front();
       cout <<  p.first << " " << p.second << endl;
        q.pop();
        for(auto u:v){
        int ci = p.first+u.first;
        int cj = p.second+u.second;
        if(isValid(ci,cj)==true && vis[ci][cj]==false){
            q.push({ci,cj});
            vis[ci][cj]=true;
            level[ci][cj]=level[p.first][p.second]+1; 
        }
        }  
      }
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int src1,src2;
    cin >> src1 >> src2;
    // for(auto u:v){
    //     cout << u.first << " " << u.second << endl;
    // }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(src1,src2);
    cout << level[2][3] << endl;
}