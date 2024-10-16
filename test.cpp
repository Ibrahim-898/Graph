#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int x,y,c;
    Edge(int x,int y,int c){
        this->x = x;
        this->y = y;
        this->c = c;

    }

};
const int N = 1001;
vector<Edge> edgeList;
long long dis[N];
long long neg[N];
long long cost[N];
bool bellmanFord(int src,int n){
    dis[src]=0;
    for(int i=1;i<=n-1;i++){
        for(auto u:edgeList){
            long long start = u.x;
            long long des = u.y;
            long long cost = u.c;
        if(dis[start]<1e9+7 && dis[start]+cost<dis[des]){
            dis[des]=dis[start]+cost;
        }
        }
    }
    for(int i=1;i<=n;i++){
        neg[i]=dis[i];
    }
    for(auto u:edgeList){
            long long start = u.x;
            long long des = u.y;
            long long cost = u.c;
        if(neg[start]<1e9+7 && neg[start]+cost<neg[des]){
            return true;;
        }
        }
    return false;
}
bool cycleDetection(int src,int n){
    bellmanFord(src,n);
    for(auto u:edgeList){
            long long start = u.x;
            long long des = u.y;
            long long cost = u.c;
        if(dis[start]<1e9+7 && dis[start]+cost<dis[des]){
            return true;;
        }
        }
    return false;
}
int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=1;i<=n;i++) dis[i]=1e9+7;
    while(e--){
        int x,y,c;
        cin >> x >> y >> c;
        edgeList.push_back(Edge(x,y,c));
    }
     int src,q;
    cin >> src >> q;
    bool res = bellmanFord(src,n);
    int testcase[1001];
   for(int i=0;i<q;i++){
        int des;
        cin >>  testcase[i];
    }
    if(res){
        cout << "Negative Cycle Detected" << endl;
        return 0;
        }
     for(int i=0;i<q;i++){
        if(dis[testcase[i]]>=1e9) cout << "Not Possible" << endl;
        else cout << dis[testcase[i]] << endl;

     }
    
}