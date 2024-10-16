#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
 int n,m;
vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j ){
    if(i<0 || i>=n || j<0 || j>=m ){
        return false;

    }
    if(vis[i][j] || a[i][j]=='-') return false;
    return  true;
}
void dfsOn2DGrid(int src1,int src2,int& count){
    vis[src1][src2]=true;
     count++;
    for(auto u:v){
        int ci = src1+u.first;
        int cj = src2+u.second;
        if(isValid(ci,cj)){
            dfsOn2DGrid(ci,cj,count);
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
    memset(vis,false,sizeof(vis));
    vector<int> ans;
    int cnt =0,mn=1e9+7;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && a[i][j]=='.'){
               int  count=0;
                 dfsOn2DGrid(i,j,count);
                 mn = min(mn,count);
                
            }
        }
    }
    if(mn==1e9+7) cout << "-1" << endl;
   else cout << mn << endl;


}