#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long; 
#define endl '\n'
struct node{
    int l, r;
	int val;
};
const int N = 1e5 + 10;
node tree[4*N];
int a[N];

void up(int x){
	tree[x].val = max(tree[x<<1].val, tree[x<<1|1].val);
}

void build(int x, int l, int r){
	tree[x].l = l, tree[x].r = r;
	if(tree[x].l == tree[x].r){
		tree[x].val = a[l];
		return;
	}
	int mid = tree[x].l + tree[x].r >> 1;
	build(x << 1,l,mid);
	build(x << 1 | 1,mid + 1,r);
	up(x);
}

void modify(int x, int u, int delta){
    if(tree[x].l == tree[x].r)  tree[x].val += delta;
    else{
        int mid = tree[x].l + tree[x].r >> 1;
        if(u <= mid)    modify(x << 1, u, delta);
        else    modify(x <<1|1,u,delta);
        up(x);
	}
}

int query(int x,int l, int r){
	int mx = INT_MIN;
	if(tree[x].l >= l && tree[x].r <= r )	return tree[x].val;
	int mid = tree[x].l + tree[x].r >> 1;
	if(l <= mid)	mx = max(mx,query(x << 1,l,r));
	if(r > mid)		mx = max(mx,query(x << 1|1,l,r));
	return mx; 
} 

int n, m, c, b;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(m--){
		scanf("%d %d",&c,&b);
		printf("%d\n",query(1,c,b));
	}
	return 0;
} 
