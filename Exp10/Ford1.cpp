#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

bool bfs(vector<vector<int>>&cap,vector<vector<int>>&adj,int s,int t,vector<int>&parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int>>q;
    q.push({s,INT_MAX});
    while(!q.empty()){
        int cur=q.front().first;
        int flow=q.front().second;
        q.pop();
        for(int next:adj[cur]){
            if(parent[next]==-1&&cap[cur][next]>0){
                parent[next]=cur;
                int new_flow=min(flow,cap[cur][next]);
                if(next==t)return true;
                q.push({next,new_flow});
            }
        }
    }
    return false;
}

int maxflow(vector<vector<int>>&cap,vector<vector<int>>&adj,int s,int t){
    int n=cap.size();
    int flow=0;
    vector<int>parent(n);
    vector<bool>used(n,false);
    used[s]=used[t]=false;
    while(bfs(cap,adj,s,t,parent)){
        vector<int>path;
        int cur=t;
        int path_flow=INT_MAX;
        while(cur!=s){
            int prev=parent[cur];
            path_flow=min(path_flow,cap[prev][cur]);
            path.push_back(cur);
            cur=prev;
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        bool disjoint=true;
        for(int v:path){
            if(v!=s&&v!=t&&used[v]){
                disjoint=false;
                break;
            }
        }
        if(!disjoint)break;
        for(int v:path){
            if(v!=s&&v!=t)used[v]=true;
        }
        flow+=path_flow;
        for(int i=0;i<(int)path.size()-1;i++){
            int u=path[i],v=path[i+1];
            cap[u][v]-=path_flow;
            cap[v][u]+=path_flow;
        }
        cout<<"Augmenting Path Found: ";
        for(int v:path)cout<<v<<" ";
        cout<<"| Flow Added: "<<path_flow<<endl;
    }
    return flow;
}

int main(){
    int n,m;
    cout<<"Enter number of vertices and edges: ";
    cin>>n>>m;
    vector<vector<int>>cap(n,vector<int>(n,0));
    vector<vector<int>>adj(n);
    cout<<"Enter edges (u v capacity):\n";
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v]=c;
    }
    int s,t;
    cout<<"Enter source vertex: ";
    cin>>s;
    cout<<"Enter sink vertex: ";
    cin>>t;
    int max_flow=maxflow(cap,adj,s,t);
    cout<<"\nMaximum Flow using vertex-disjoint augmenting paths: "<<max_flow<<endl;
    return 0;
}
