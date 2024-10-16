#include<bits/stdc++.h>
using namespace std;
char a[20][20];
bool vis[20][20];
 int n,m;
vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
bool isValid(int i,int j ){
    if(i<0 || i>=n || j<0 || j>=m ){
        return false;

    }
    return  true;
}
void dfsOn2DGrid(int src1,int src2){
    cout << src1 << " " << src2 << " val " <<  a[src1][src2] << endl;
    vis[src1][src2]=true;
    for(int i=0;i<4;i++){
        int ci = src1+v[i].first;
        int cj = src2+v[i].second;
        if(isValid(ci,cj) &&  vis[ci][cj]==false){
            dfsOn2DGrid(ci,cj);
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
    int src1,src2;
    cin >> src1 >> src2;
    dfsOn2DGrid(src1,src2);



}