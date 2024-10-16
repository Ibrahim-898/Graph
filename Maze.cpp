#include <bits/stdc++.h>

using namespace std;
int n,m;
char a[1001][1001];
bool vis[1001][1001];
pair<int,int> path[1001][1001];
bool flag = false;
vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    if(a[i][j]=='#') return false;
    return true;
}
bool bfs(int starti,int startj,int desi,int desj){
    queue<pair<int,int>> q;
    q.push({starti,startj});
    vis[starti][startj]=true;
    vector<pair<int,int>> ans;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if(p.first==desi && p.second==desj) {
           return true;
        }
        for(auto u:v){
        int ci = p.first + u.first;
        int cj = p.second +u.second;  
        if(isValid(ci,cj) && !vis[ci][cj]){
            q.push({ci,cj});
            vis[ci][cj]=true;
           // cout << p.first << " " << p.second << endl;
           path[ci][cj]={p.first,p.second};
        }
        
        }
    }
    return false;
}

int main()
{
     memset(vis,false,sizeof(vis));
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            path[i][j]={-1,-1};
        }

    }
   cin >> n >> m;
       int starti,startj,desi,desj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]=='R') {
                starti=i;
                startj=j;
        }
            if(a[i][j]=='D'){
                desi=i;
                desj=j;
            }
    }
    }
   bool  res =  bfs(starti,startj,desi,desj);
   if(res){
   int i = path[desi][desj].first,j =path[desi][desj].second;
   while(path[i][j].first!=-1 && path[i][j].second!=-1){
    a[i][j]='X';
    //cout << path[i][j].first << " " << path[i][j].second << endl; 
    int temp = i;
    i=path[i][j].first;
    j=path[temp][j].second;
    //cout << "i " <<  i << " " << j << endl;
   }
   }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    
   
}
