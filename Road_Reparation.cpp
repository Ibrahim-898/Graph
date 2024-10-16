#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Edge{
    public:
    ll a,b,c;
    Edge(ll a,ll b,ll c){
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
const ll N = 1e5+7;
ll n,e;
ll par[N];
ll level[N];
ll group_size[N];
ll find(ll val){
    if(par[val]==-1) return val;
   ll leader =  find(par[val]);
   par[val] = leader;
   return leader;

}
void union_by_size(ll a,ll b){
    ll leaderA = find(a);
    ll leaderB = find(b);
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
        ll x,y,c;
        cin >> x >> y >> c;
        edgeList.push_back(Edge(x,y,c));
    }   
    sort(edgeList.begin(),edgeList.end(),cmp);
    ll totalCost = 0,cnt=0;
    for(auto u:edgeList){
        ll leader1 = find(u.a);
        ll leader2 = find(u.b);
        if(leader1!=leader2){
            totalCost+=u.c;
            union_by_size(u.a,u.b);
            cnt++;
        }
    }
    if(cnt!=n-1) cout << "-1" << endl;
    else cout <<  totalCost << endl;
}