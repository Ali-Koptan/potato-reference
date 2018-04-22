#include <bits/stdc++.h>
using namespace std;
const int n = 6;
int arr[n], tree[4*n];
void build(int l, int r, int node){
    if (l==r){
        tree[node]=arr[l];
        return;
    }
    build(l, (l+r)/2, node*2);
    build((l+r)/2+1, r, node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void update(int l, int r, int node, int val, int i){
    if (i<l || i>r)
        return;
    if (l==r){
        arr[i]+=val;
        tree[node]+=val;
        return;
    }
    if (i>=l && i<=r){
        update(l, (l+r)/2, node*2, val, i);
        update((l+r)/2+1, r, node*2+1, val, i);
    }
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int l, int r, int node, int s, int e){
    if (s>r || e<l)
        return 0;
    if (l>=s && r<=e)
        return tree[node];
    return query(l, (l+r)/2, node*2, s, e) + query((l+r)/2+1, r, node*2+1, s, e);
}
int main(){
    //test on size n.
    for (int i=0; i<n; i++)
        cin>>arr[i];
    build(0, n-1, 1);

    cout<<"#of qs?\n";
    int q; cin>>q;
    for (int i=0; i<q; i++){
        char x; cin>>x;
        if(x=='u'){
            int w, v; cin>>w>>v;
            update(0, n-1, 1, v, w);
            for (int j=0; j<n; j++)
                cout<<arr[j]<<' ';
            cout<<'\n';
        }
        else if (x=='q'){
            int s, e; cin>>s>>e;
            cout<<query(0, n-1, 1, s, e)<<'\n';
        }
    }
    return 0;
}
