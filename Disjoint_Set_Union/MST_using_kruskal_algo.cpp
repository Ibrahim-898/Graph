#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int a,b,c;
    Edge(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

};
#define endl '\n'
#define ll long long
#define ld  long double
bool cmp(Edge a,Edge b){
    if(a.c<b.c) return true;
    return false;

}
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
    vector<Edge> edgeList;
    while(e--){
        int x,y,c;
        cin >> x >> y >> c;
        edgeList.push_back(Edge(x,y,c));
    }   
    sort(edgeList.begin(),edgeList.end(),cmp);
    int totalCost = 0;
    for(auto u:edgeList){
        int leader1 = find(u.a);
        int leader2 = find(u.b);
        if(leader1!=leader2){
            totalCost+=u.c;
            union_by_size(u.a,u.b);
        }
    }
    cout <<  totalCost << endl;
}