/*There are n cities and m roads. The capital is located at 1. 
Your task is to determine the length of the shortest route from 
the capital to every city.*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
using ii = pair<int,int>;
using lii = pair<ll,ll>;

int n,m;
vector<vector<pair<int,int>>> g;
vector<ll> dist;
vector<bool> vis;

class prioritize{
    public: bool operator()(lii &p1,lii &p2){
        return p1.second > p2.second;
    }
};

void dijksta(int sc){
    for(int i = 1;i<=n;i++){
        dist[i] = 1e18;
        vis[i] = false;
    }

    dist[sc] = 0;
    //vis[sc] = true;
    priority_queue<lii,vector<lii>,prioritize> pq;
    pq.push({sc,0});

    while(!pq.empty()){
        pair<ll,ll> node = pq.top();
        pq.pop();

        if(vis[node.first])continue;
        vis[node.first] = true;

        for(auto v:g[node.first]){
            int neigh = v.first;
            int wt = v.second;
            if(dist[neigh] > dist[node.first] + wt){
                dist[neigh] = dist[node.first] + wt;
                pq.push({neigh,dist[neigh]});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    dist.clear();
    dist.resize(n+1);
    vis.clear();
    vis.resize(n+1);
    int from,to,len;
    for(int i = 0;i < m;i++){
        cin >> from >> to >> len;
        g[from].push_back({to,len});
    }
    dijksta(1);
    for(int i = 1;i<=n;i++){
        cout << dist[i] << " ";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}