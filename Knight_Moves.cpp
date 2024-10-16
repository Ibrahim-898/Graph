#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,m;
bool vis[N][N];
int dis[N][N];
vector<pair<int,int>> v={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
bool isValid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
void bfs(int src1,int src2){
    queue<pair<int,int>> q;
    q.push({src1,src2});
    vis[src1][src2]=true;
    dis[src1][src2]=0;
   while(!q.empty()){
        pair<int,int> p = q.front();
       //cout <<  p.first << " " << p.second << endl;
        q.pop();
        for(auto u:v){
        int ci = p.first+u.first;
        int cj = p.second+u.second;
        if(isValid(ci,cj)==true && vis[ci][cj]==false){
            q.push({ci,cj});
            vis[ci][cj]=true;
            dis[ci][cj]=dis[p.first][p.second]+1; 
        }
        }  
      }
}
int main()
{
   
    int t;
    cin >> t;
    while(t--){
        int k1,q1,k2,q2;
    cin >> n >> m >> k1 >>  k2 >> q1 >>  q2;
     bfs(k1,k2);
     cout << dis[q1][q2] << endl;
    }
}