#include<bits/stdc++.h>
using namespace std;
void AdjacencyMayrix() {  
}
int main()
{
    int n,e;
    cin >> n >> e;
    int a[n][n]={0};
    memset(a,0,sizeof(a));
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for( int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}