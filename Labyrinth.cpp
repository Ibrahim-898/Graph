#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld  long double
#define ios() ios_base:: sync_with_stdio(0);cin.tie(0);
const int N=1001;
int n,m;
char a[N][N];
bool vis[N][N];
char par[N][N];
bool isValid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    if(a[i][j]=='#') return false;
    return true;
}
pair<int,int> dis[N][N];
vector<char> ans;
vector<pair<int,int>> v = {{0,1},{0,-1},{1,0},{-1,0}};
int cnt;
bool bfs(int srci,int srcj,int desi,int desj){
    queue<pair<int,int>> q;
    q.push({srci,srcj});
   // cout << q.front().first << endl;
    vis[srci][srcj]=true;
   while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
       //cout <<  p.first << " " << p.second << endl;
        if(p.first==desi && p.second==desj){
                return true;
               }
        for(int i=0;i<4;i++){
             int x = v[i].first;
             int y= v[i].second;
             int ci = p.first+x;
             int cj = p.second+y;
        //cout << "* " << p.first << " "  << p.second <<  " " << u.first <<  " " << u.second << endl;
        
        if(isValid(ci,cj) && !vis[ci][cj]){

             if(i==0)       par[ci][cj]='R';
             else if(i==1)  par[ci][cj]='L';
             else if(i==2)  par[ci][cj]='D';
             else if(i==3)  par[ci][cj]='U';
             dis[ci][cj].first = p.first;
             dis[ci][cj].second = p.second;
             cnt++;
              q.push({ci,cj});
              vis[ci][cj]=true;
             //cout << ans.back() << endl;
        }
        // cout << ci << " " << cj << " " << x << " " << y << endl;
        }  
      }
      return false;
}
int main()
{
    memset(vis,false,sizeof(vis));
    cin >> n >> m;
    cnt=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dis[i][j]={-1,-1};
        }
    }
    
    int srci,srcj,desi,desj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]=='B'){
                desi = i;
                desj = j;
            }
            if(a[i][j]=='A'){
                srci=i;
                srcj=j;
            }
        }
    }
    bool res =bfs(srci,srcj,desi,desj);
    if(!res){
        cout << "NO" << endl;
        return 0;
    }
    while(1){
        if(dis[desi][desj].first==srci &&  dis[desi][desj].second==srcj) {
             ans.push_back(par[desi][desj]);
            break; 
        }
        ans.push_back(par[desi][desj]);
        int temp_i = desi, temp_j = desj;
        desi = dis[temp_i][temp_j].first;
        desj = dis[temp_i][temp_j].second;
        //cout << "^ " <<  dis[desi][desj].first << " " << dis[desi][desj].second << endl;
        
    }
    reverse(ans.begin(),ans.end());

   cout << "YES" << endl << ans.size() << endl;
     for(auto u:ans){
        cout << u;
    }
    cout << endl;
    
}