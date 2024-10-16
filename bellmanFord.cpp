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
const int N = 1e5+7;
vector<Edge> edgeList;
int dis[N];
int cost[N];
void bellmanFord(int src,int n){
    dis[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto u:edgeList){
            int start = u.x;
            int des = u.y;
            int cost = u.c;
        if(dis[start]<1e9+7 && dis[start]+cost<dis[des]){
            dis[des]=dis[start]+cost;
        }
        }
    }
    for(int i=0;i<n;i++){
        cout << dis[i] << " ";
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=0;i<n;i++) dis[i]=1e9+7;
    while(e--){
        int x,y,c;
        cin >> x >> y >> c;
        //Edge * val = new Edge(x,y,c);
        edgeList.push_back(Edge(x,y,c));
    }
     int src;
    cin >> src;
    bellmanFord(src,n);
    
}