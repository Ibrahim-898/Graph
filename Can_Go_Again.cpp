#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    long long x,y,c;
    Edge(long long x,long long y,long long c){
        this->x = x;
        this->y = y;
        this->c = c;

    }

};
const int N = 1010;
vector<Edge> edgeList;
long long dis[N];
long long cost[N];
void bellmanFord(long long src,long long n){
    dis[src]=0;
    for(int i=1;i<=n-1;i++){
        for(auto u:edgeList){
            int start = u.x;
            int des = u.y;
            long long cost = u.c;
        if(dis[start]<1e18 && dis[start]+cost<dis[des]){
            dis[des]=dis[start]+cost;
        }
        }
    }
}
bool cycleDetection(int src,int n){
   // bellmanFord(src,n);
    for(auto u:edgeList){
            int start = u.x;
            int des = u.y;
            int cost = u.c;
        if(dis[start]<1e18 && dis[start]+cost<dis[des]){
            return true;
        }
    }
        return false;

}
int main()
{
    long long n,e;
    cin >> n >> e;
    for(int i=1;i<=n;i++) dis[i]=1e18;
    while(e--){
        long long x,y,c;
        cin >> x >> y >> c;
        edgeList.push_back(Edge(x,y,c));
    }
     long long src,t,f=1;
    cin >> src >> t;
    bellmanFord(src,n);
   bool res = cycleDetection(src,n);
   for(int i=0;i<t;i++){
   
    long long des;
    cin >> des;
    if(!res){
        if(dis[des]==1e18) cout << "Not Possible" << endl;
        else
        cout << dis[des] << endl;
    }
   }
    if(res==true){
        cout << "Negative Cycle Detected" << endl;
        f=0;
    }
    
}