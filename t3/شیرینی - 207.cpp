#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define INF INT_MAX

vector<pair<int, int>> graph[MAX];
int dist[MAX], parent[MAX];
bool visited[MAX];

void Dijkstra(int start, int end){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0; i<MAX; i++){
        dist[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto v: graph[u]){
            int node = v.first;
            int weight = v.second;
            if(dist[node] > dist[u] + weight){
                dist[node] = dist[u] + weight;
                parent[node] = u;
                pq.push(make_pair(dist[node], node));
            }
        }
    }
    if(dist[end] == INF){
        cout<<0<<endl;
        return;
    }
    cout<<dist[end]<<endl;
    stack<int> path;
    int temp = end;
    while(temp != -1){
        path.push(temp);
        temp = parent[temp];
    }
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<endl;
}

int main(){
    long long n, m;
    cin>>n>>m;
    int start=0, end;
    cin>>end;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    Dijkstra(start, end);
    return 0;
}