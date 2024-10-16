#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld  long double
#define ios() ios_base:: sync_with_stdio(0);cin.tie(0);
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first!=b.first)
    return (a.first<b.first);
    else
     return (a.second>b.second);
}
int fact(int n)
{
    return (n==1) ? 1: n * fact(n - 1); 
    // ? :
}
const int N=1001;
int n,m;
char a[N][N];
bool vis[N][N];
bool isValid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    if(a[i][j]=='#') return false;
    return true;
}
vector<pair<int,int>> v = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int srci,int srcj) {
    for(auto u:v){
        int ci = u.first + srci;
        int cj = u.second + srcj;
    if(isValid(ci,cj) && !vis[ci][cj]){
        vis[ci][cj]=true;
        dfs(ci,cj);
    }
    }
    
    
}
int main()
{
    ios();
    memset(vis,false,sizeof(vis));
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && a[i][j]=='.'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}