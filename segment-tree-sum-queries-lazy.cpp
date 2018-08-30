#include <bits/stdc++.h>
using namespace std;
const int m = 1e5 + 5;
int arr[m + 5], lazy[4 * m], tree[4 * m];
void build(int l, int r, int node){
    // leaf node
    if (l == r){
        tree[node] = arr[l];
        return;
    }
    // building left and right children
    build(l, (l+r) >> 1, node << 1);
    build(((l+r) >> 1) + 1, r, (node << 1) + 1);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}
void updateRange(int l, int r, int s, int e, int node, int val){
    // updating node if it's lazy
    if (lazy[node]){
        tree[node] += lazy[node] * (r - l + 1);
        if (l != r){
            // marking children as lazy
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (s > r || e < l || r < l)
        return;

    // updating node, marking children as lazy with new val
    if (l >= s && r <= e){
        tree[node] += val * (r - l + 1);
        if (l != r){
            lazy[node << 1] += val;
            lazy[(node << 1) + 1] += val;
        }
        return;
    }
    // recursing to wanted range
    updateRange(l , (l + r) >> 1, s, e, node << 1, val);
    updateRange(((l + r) >> 1) + 1, r, s, e, (node << 1) + 1, val);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}
long long query(int l, int r, int s, int e, int node){
    // out of range
    if (s > r || e < l)
        return 0;
    // updating node if it's lazy
    if (lazy[node]){
        tree[node] += lazy[node] * (r - l + 1);
        if (l != r){
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // getting answer from desired range
    if (l >= s && r <= e)
        return tree[node];
    // recursing till reaching desired ranges
    return min(query(l, (l + r) >> 1, s, e, node << 1), query(((l + r) >> 1) + 1, r, s, e, (node << 1) + 1));
}
int main(){
    // test on size n
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, n, 1);
    // testing on Q queries, type 1 is view range, type 2 is update range with v value.
    int Q;
    cin >> Q;
    while(Q--){
        int q; cin >> q;
        if (q == 1){
            int l, r;
            cin >> l >> r;
            cout << query(1, n, l, r, 1) << '\n';
        }else{
            int l, r, v;
            cin >> l >> r >> v;
            updateRange(1, n, l, r, 1, v);
        }
    }
    return 0;
}
