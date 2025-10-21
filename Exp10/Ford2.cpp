#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> cap;
vector<vector<int>> adj;
vector<int> dist,path;
vector<vector<int>> allpaths;
int n,s,t;

void bfs(){
    for(int i=0;i<n;i++) dist[i]=1e9;
    queue<int> q;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(cap[u][v]>0 && dist[v]==1e9){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}

void dfs(int u){
    if(u==t){
        allpaths.push_back(path);
        return;
    }
    for(int v:adj[u]){
        if(cap[u][v]>0 && dist[v]==dist[u]+1 && dist[v]<=dist[t]){
            path.push_back(v);
            dfs(v);
            path.pop_back();
        }
    }
}

int main(){
    cin>>n>>s>>t;
    cap.assign(n,vector<int>(n));
    adj.assign(n,vector<int>());
    dist.assign(n,1e9);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(v);
        cap[u][v]=c;
    }
    bfs();
    path.push_back(s);
    dfs(s);
    for(auto &p:allpaths){
        for(int node:p) cout<<node<<" ";
        cout<<endl;
    }
}
