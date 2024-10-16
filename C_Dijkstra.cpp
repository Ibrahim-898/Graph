#include<bits/stdc++.h>
using namespace std;
#define ll long long
class cmp{
    public:
    bool operator()(pair<ll,ll> a,pair<ll,ll> b){
        if(a.second>b.second) return true;
        return false;
    }

};
const ll N = 1e5+10;
ll path[N];
 ll n,e;
vector<pair<ll,ll>> v[N];
ll dis[N];
void dijstra(ll src){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp> q;
    q.push({src,0});
    dis[src]=0;
    vector<ll> ans;
    while(!q.empty()){
        pair<ll,ll> p = q.top();
        q.pop();
        for(auto u:v[p.first]){
        if(u.second+p.second < dis[u.first]){
            dis[u.first]=u.second+p.second;
            q.push({u.first,dis[u.first]});
            path[u.first]=p.first;
        }
        }
    }
    ll des = n;
    ans.push_back(n);
      if(path[n]==-1){
        cout << -1 << endl;
        return;
    }
    while(path[des]!=-1){
        des =path[des];
        ans.push_back(des);
    }
    reverse(ans.begin(),ans.end());
    for(auto u:ans){
        cout << u << " ";
    }
    


}
int main()
{
    cin >> n >> e;
    for(ll i=0;i<N;i++){
        dis[i]=1e18;
        path[i]=-1;
    }
    while(e--){
        ll x,y,cost;
        cin >> x >> y  >> cost;
        v[x].push_back({y,cost});
        v[y].push_back({x,cost});
    }
    ll src;
    //cin>> src;
    src = 1;
    dijstra(src);
    // for(ll i=1;i<=n;i++){
    //     cout << dis[i] << " ";
    // }
    // cout << endl;

}