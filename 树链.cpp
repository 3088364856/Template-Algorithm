#include <bits/stdc++.h>
using ll = long long;
// 0 start

class sp{
public:
	
	std::vector<int> fa, siz, son, top, deep;
	std::vector<std::vector<int>> v;
	
	sp(int N = 5e5+5){
		fa.assign(N,0);
		siz.assign(N,0);
		son.assign(N,0);
		top.assign(N,0);
		deep.assign(N,0);
		v.assign(N,std::vector<int>());
	}
	
	void sp_assign(int N){
		fa.assign(N,0);
		siz.assign(N,0);
		son.assign(N,0);
		top.assign(N,0);
		deep.assign(N,0);
		v.assign(N,std::vector<int>());
	}
	
	void dfs1(int x, int f){
		deep[x] = deep[f] + 1;
		fa[x] = f;
		siz[x] = 1;
		for(auto t:v[x]){
			if(t == f)	continue;
			dfs1(t,x);
			siz[x] += siz[t];
			if(!son[x] || siz[son[x]] < siz[t])	son[x] = t;
		}
	}
	
	void dfs2(int x, int topx){
		top[x] = topx;
		if(!son[x])	return ;
		dfs2(son[x],topx);
		for(auto t:v[x]){
			if(t != fa[x] && t != son[x])	dfs2(t,t);
		}
	}
	
	int LCA(int x, int y){
		while(top[x] != top[y]){
			if(deep[top[x]] < deep[top[y]])	std::swap(x,y);
			x = fa[top[x]];
		}
		return deep[x] < deep[y] ? x : y;
	}
};


const int N = 5e5+5;
int deep[N];
std::vector<int> fa(N), siz(N), son(N),top(N);
std::vector<std::vector<int>> v(N);
int n,m,q;
sp f;
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	
	
	std::function<void(int,int)> dfs1 = [&](int x, int f){
		deep[x] = deep[f] + 1;
		fa[x] = f;
		siz[x] = 1;
		for(auto t:v[x]){
			if(t == f)	continue;
			dfs1(t,x);
			siz[x] += siz[t];
			if(!son[x] || siz[son[x]] < siz[t])	son[x] = t;
		}
	};
	std::function<void(int,int)> dfs2 = [&](int x, int topx){
		top[x] = topx;
		if(!son[x])	return ;
		dfs2(son[x],topx);
		for(auto t:v[x]){
			if(t != fa[x] && t != son[x])	dfs2(t,t);
		}
	};
	std::function<int(int,int)> LCA = [&](int x, int y){
		while(top[x] != top[y]){
			if(deep[top[x]] < deep[top[y]])	std::swap(x,y);
			x = fa[top[x]];
		}
		return deep[x] < deep[y] ? x : y;
	};	
	
	
	
	std::cin >> n >> q >> m;
	for(int i = 0; i < n-1; ++i){
		int x, y;
		std::cin >> x >> y;
		f.v[x].push_back(y);
		f.v[y].push_back(x);
	}
	f.dfs1(m,0);
	f.dfs2(m,m);
	while(q--){
		int x, y;
		std::cin >>x >> y;
		std::cout << f.LCA(x,y) << '\n';
	}

}
