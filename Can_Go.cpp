#include <bits/stdc++.h>

using namespace std;
int n,m;
char a[1000][1000];
bool vis[1000][1000];
vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
bool bfs(int starti,int startj,int desi,int desj){
    queue<pair<int,int>> q;
    q.push({starti,startj});
    vis[starti][startj]=true;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if(p.first==desi && p.second==desj) return true;
        for(auto u:v){
        int ci = p.first + u.first;
        int cj = p.second +u.second;  
        if(isValid(ci,cj)==true && vis[ci][cj]==false && a[ci][cj]!='#'){
            q.push({ci,cj});
            vis[ci][cj]=true;
        }
        
        }
    }
    return false;
    
}

int main()
{
   cin >> n >> m;
       int starti,startj,desi,desj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]=='A') {
                starti=i;
                startj=j;
        }
            if(a[i][j]=='B'){
                desi=i;
                desj=j;
            }
    }
    }
    memset(vis,false,sizeof(vis));
   bool ans =  bfs(starti,startj,desi,desj);
   if(ans==true) cout << "YES" << endl;
   else cout << "NO" << endl;
}
