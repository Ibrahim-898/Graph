#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld  long double
const int N = 1e5+7;
int par[N],n,groupSize[N],level[N];
void par_initializer(int n){
    for(int i=0;i<n;i++) {
        par[i]=-1;
        groupSize[i]=1;
        level[i]=0;
    }
}
int find(int node){
    if(par[node]==-1) return node;
    int leader = find(par[node]);
    par[node]=leader;
    return leader;

}
void dsu_Union_By_Size(int a,int b){
    int x = find(a);
    int y = find(b);
    if(groupSize[x]>=groupSize[y]){
        par[y]=x;
        groupSize[x]+=groupSize[y];
    }
    else {
        par[x]=y;
        groupSize[y]+=groupSize[x];
    }

}
void dsu_Union_By_Rank(int a,int b){
    int leaderA = find(a);
    int leaderB = find(b);
    if(level[leaderA]>level[leaderB]){
        par[leaderB]=leaderA;
    }
    else if(level[leaderA]<level[leaderB]) {
        par[leaderA]=leaderB;

    }
    else{
        par[leaderB]=leaderA;
        level[leaderA]++;
    }

}
int main()
{
    cin >> n;
    par_initializer(n);
    dsu_Union_By_Rank(1,2);
    dsu_Union_By_Rank(2,3);
    dsu_Union_By_Rank(4,5);
    dsu_Union_By_Rank(2,4);
    cout << find(4) << " " << level[find(4)] << endl;
    
}