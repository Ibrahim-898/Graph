#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld  long double
const int N = 1e5+7;
int n,e;
int par[N];
int level[N];
int group_size[N];
int find(int val){
    if(par[val]==-1) return val;
   int leader =  find(par[val]);
   par[val] = leader;
   return leader;

}
void union_by_size(int a,int b){
    int leaderA = find(a);
    int leaderB = find(b);
    if(group_size[leaderA] >= group_size[leaderB]){
        par[leaderB]=leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
    else {
        par[leaderA]=leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }

}
int main()
{
    memset(par,-1,sizeof(par));
    //memset(level,0,sizeof(level));
    memset(group_size,0,sizeof(group_size));
    cin >> n >> e;
    bool cycle = false;
    while(e--){
        int x,y;
        cin >> x >> y;
        int leaderA = find(x);
        int leaderB = find(y);
        if(leaderA==leaderB){
            cycle =true;
        }
        else{
            union_by_size(x,y);
        }

    }
    if(cycle) {
        cout << "Cycle is Found" << endl;

    }
    else cout << "NO Cycle is Found" << endl;
    
}