#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const string u = "union";
const string g = "get";
int n, m;
struct dsu{
    vector<int> Size;
    vector<int> par;
    vector<long long> d;
    void init(int N){
        Size.assign(N,1);
        par.assign(N,-1);
        d.assign(N,0);
    }
    void unite(int a, int b){
        a = root(a); b = root(b);
        if(a == b)  return;
        if(Size[a] < Size[b])   swap(a,b);
        // a bigger than b
        Size[a] += Size[b];
        par[b] = a;
    }
    bool same(int a, int b){
        return root(a) == root(b);
    }
    int root(int a){
        if(par[a] == -1)    return a;
        int f = root(par[a]);
        d[a] += d[par[a]];
        return par[a] = f;
    }
    int size(int a){
        return Size[root(a)];
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;
	dsu uf;
	uf.init(n+1);
	vector<int> res;

	for(int i = 1; i <= q; ++i){
		ll x,y,z;
		cin >> x >> y >> z;
		if(uf.same(x,y)){
			if(uf.d[x]-uf.d[y] == z)	res.push_back(i);
			else	continue;
		}else{
			int ff = uf.root(x);
			uf.par[ff] = y;
			uf.d[ff] = uf.d[ff]-uf.d[x]+z;
			res.push_back(i);
		}
	}
	for(auto x:res){
		cout << x << " ";
	}
	return 0;
} 
