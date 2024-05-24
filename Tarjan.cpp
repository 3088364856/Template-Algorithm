#include <bits/stdc++.h>


// v is graph
const int N = 1e5+5;
std::vector<int> v[N], stk, num, low, scc;
int top, dfn, cnt;
int n, m;
int main(){
	std::function<void(int)> tarjan = [&](int u){
		stk[top++] = u;
		low[u] = num[u] = dfn++;
		for(auto x:v[u]){
			if(!num[x])	{
				tarjan(x);
				low[u] = std::min(low[u],low[x]);
			}else if(!scc[x])	low[u] = std::min(low[u],num[x]);
		}
		if(low[u] == num[u]){
			++cnt;
			while(1){
				int x = stk[--top];
				scc[x] = cnt;
				if(x == u)	break;
			}
		}
	};
	std::function<void(int)> Tarjan = [&](int n = N){
		stk = std::vector<int> (n+1,0);
		num = std::vector<int> (n+1,0);
		low = std::vector<int> (n+1,0);
		scc = std::vector<int> (n+1,0);
		
		for(int i = 1; i <= n; ++i)	if(!scc[i])	tarjan(i);
	};

	return 0;	
}
