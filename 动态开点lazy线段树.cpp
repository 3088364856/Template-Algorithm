/*
    Author: Fri59h2
    Description:
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
//const int dir[8][2] = {1,0,0,1,-1,0,0,-1,-1,-1,1,1,1,-1,-1,1};
#define all(x)    (x).begin(),(x).end()
#define mst(x,val)  memset((x),(val),sizeof (x))
#define x first
#define y second
#define endl '\n'
const int N = 1e4*30;
    int n , m, cnt;
    int root;
    int tree[2*N];
    int tag[2*N];
    int lc[2*N];
    int rc[2*N];

    void addtag(int& x, ll d){
        if(!x)  x = ++cnt;
        tag[x] = d;
        tree[x] = d;
    }

    void up(int x){
        tree[x] = tree[lc[x]] & tree[rc[x]];
    }

    void down(int& x){
        if(!x)  x = ++cnt;
        if(tag[x] != -1) {
            addtag(lc[x],tag[x]);
            addtag(rc[x],tag[x]);
            tag[x] = -1;
        }
    }

    void modify(int& x, int l, int r, int L, int R, ll d){
        if(!x)  x = ++cnt;
        if(L >= l && R <= r){
            addtag(x,d);
            return ;
        }
        down(x);
        int mid = L + R >> 1;
        if(l <= mid) modify(lc[x],l,r,L,mid,d);
        if(r > mid) modify(rc[x],l,r,mid+1,R,d);
        up(x);
    }

    int query(int& x, int l, int r, int L, int R){
        if(!x)  x =  ++cnt;
        if(L >= l && R <= r){
            return tree[x];
        }
        down(x);
        int res = 1;
        int mid = L + R >> 1;
        if(l <= mid) res &= query(lc[x],l,r,L,mid);
        if(r > mid) res &= query(rc[x],l,r,mid+1,R);
        return res;
    }



int main(){
    modify(root,1,10,1,1e9,1);
    cout << query(root,1,3,1,1e9);

}
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */