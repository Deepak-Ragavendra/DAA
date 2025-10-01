#include<iostream>
#include<vector>

using namespace std;

int main(){
    int v,e,a,b,w;
    cin>>v>>e;
    vector<vector<int>> dist(v+1,vector<int>(v+1,1e9));
    for(int i=1;i<=v;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<e;i++){
        cin>>a>>b>>w;
        dist[a][b]=min(dist[a][b],w);
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(i!=k && j!=k){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    int tot=0;
    for(int i=1;i<=v;i++){
        for(int j=i+1;j<=v;j++){
            tot=max(tot,dist[i][j]);
        }
    }
    cout<<tot;
}