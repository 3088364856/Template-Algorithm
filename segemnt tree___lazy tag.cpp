#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
#define endl '\n'
int n , m;
vector<ll> a(N);
vector<ll> tag(4*N);
struct node{
    int l, r;
    ll val;
};
node tree[4*N];
void addtag(int x, ll d){
    tag[x] += d;
    tree[x].val += (tree[x].r - tree[x].l +1)*d;
}

void up(int x){
    tree[x].val = tree[x<<1].val + tree[x<<1|1].val;
}

void down(int x){
    if(tag[x] != 0) {
        addtag(x<<1,tag[x]);
        addtag(x<<1|1,tag[x]);
        tag[x] = 0;
    }
}

void build(int x, int l, int r){
	tree[x].l = l, tree[x].r = r;
    if(l == r){
        tree[x].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    up(x);
}

void modify(int x, int l, int r, ll d){
    if(tree[x].l >= l && tree[x].r <= r){
        addtag(x,d);
        return ;
    }
    down(x);
    int mid = tree[x].l + tree[x].r >> 1;
    if(l <= mid) modify(x<<1,l,r,d);
    if(r > mid) modify(x<<1|1,l,r,d);
    up(x);
}

ll query(int x, int l, int r){
    if(tree[x].l >= l && tree[x].r <= r){
        return tree[x].val;
    }
    down(x);
    ll res = 0;
    int mid = tree[x].l + tree[x].r >> 1;
    if(l <= mid) res += query(x<<1,l,r);
    if(r > mid) res += query(x<<1|1,l,r);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1,1,n);
    while(m--){
        int flag;
        cin >> flag;
        if(flag&1){
            ll l, r, d;
            cin >> l >> r >> d;
            modify(1,l,r,d);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << query(1,l,r) << endl;
        }
    }
    return 0;
}
