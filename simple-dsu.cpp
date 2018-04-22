#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int Parent[N], Rank[N];
void init(){
    for (int i=0; i<N; i++)
        Parent[i]=i, Rank[i]=0;
}
int get_parent(int u){
    if (Parent[u]==u)
        return u;
    return Parent[u]=get_parent(Parent[u]);
}
void connect(int u, int v){
    u=get_parent(u);
    v=get_parent(v);
    if(Rank[u]<Rank[v]){
        Parent[u]=v;
    }
    else if (Rank[u]>Rank[v]){
        Parent[v]=u;
    }
    else{
        Parent[u]=v;
        Rank[v]++;
    }
}
bool is_connected(int u, int v){
    return (get_parent(u)==get_parent(v));
}
vector<pair<int, pair<int, int>>>adj;
int go(){
    int total(0);
    //sort(adj.begin(), adj.end());
    for (int i=0; i<adj.size(); i++){
            for (int j=0; j<adj[i].size(); j++){
                if (!is_connected(i, adj[j].second)){
                total+=adj[j].first;
                connect(i, adj[j].second);
            }
        }
    }
    return total;
}
int main()
{
    int n, m;
    while(cin>>n>>m){
        adj.resize(m+1);
        if (n==0 && m==0)
            return 0;
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(c, b));
        adj.clear();
    }
    return 0;
}
