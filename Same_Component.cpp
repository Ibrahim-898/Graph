#include <bits/stdc++.h>
using namespace std;
const int N =1001;
char a[N][N];
int n,m;
bool vis[N][N];
vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    if(a[i][j]=='-') return false;
    return true;  
}
void bfs(int src1,int src2,int des1,int des2){
    queue<pair<int,int>> q;
    q.push({src1,src2});
    vis[src1][src2]=true;
          if(src1==des1 && src2==des2){
        cout << "YES" << endl;
        return;
    }
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(auto u:v){
            int x=u.first+p.first;
            int y = u.second+p.second;
            if(isValid(x,y) && !vis[x][y] ){
                if(x==des1 && y==des2){
        cout << "YES" << endl;
        return;
    }
                q.push({x,y});
                vis[x][y]=true;
            }
        }
    }
    cout  << "NO" << endl;
}
int main()
{ 
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int src1,src2,des1,des2;
    cin >> src1 >> src2 >> des1 >>  des2;
    bfs(src1,src2,des1,des2);
}
