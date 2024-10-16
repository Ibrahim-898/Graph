#include<bits/stdc++.h>
using namespace std;
class cmp{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.second>b.second) return true;
        return false;
    }

};
const int N = 1000;
const int mx = 1e7+7;
vector<pair<int,int>> v[N];
int dis[N];
void dijstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
    q.push({src,0});
    dis[src]=0;
    vector<int> ans;
    ans.push_back(src);
    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        for(auto u:v[p.first]){
        if(u.second+p.second < dis[u.first]){
            dis[u.first]=u.second+p.second;
            q.push({u.first,dis[u.first]});
        }
        }
    }


}
int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=0;i<N;i++){
        dis[i]=INT_MAX;
    }
    while(e--){
        int x,y,cost;
        cin >> x >> y  >> cost;
        v[x].push_back({y,cost});
        v[y].push_back({x,cost});
    }
    int src;
    cin>> src;
    dijstra(src);
    for(int i=1;i<=n;i++){
        cout << dis[i] << " ";
    }
    cout << endl;

}