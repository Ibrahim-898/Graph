#include<bits/stdc++.h>
using namespace std;
const int N = 101;
long long dis[N][N];
void floydWarshall(int n){
    for(int k=1;k<=n;k++){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(dis[i][k]<1e9+7 && dis[k][j]<1e9+7 && dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
int main()
{
   int n,e;
   cin >> n >> e;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==j) dis[i][j]=0;
        else
        dis[i][j]= 1e9+7;
    }
   }
    for(int i=0;i<e;i++){
        long long x,y,c;
        cin >> x >> y >> c;
       if(dis[x][y]>c ) dis[x][y]=c;
    }
    floydWarshall(n);
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        if(dis[a][b]>=1e9+7) cout << -1 << endl;
        else
        cout << dis[a][b] << endl;
        
    }
   

}