/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/06/23 12:39
	Description: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
const string u = "union";
const string g = "get";
int n, m;
struct dsu{
    vector<int> Size;
    vector<int> par;
    void init(int N){
        Size.assign(N,1);
        par.assign(N,-1);
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
        return par[a] = root(par[a]);
    }
    int size(int a){
        return Size[root(a)];
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dsu uf;
	uf.init();
	while(m--){
		string s;
		int a,b;
		cin >> s >> a >> b;
		if(s==u)	uf.unite(a,b);
		else{
			if(uf.same(a,b))	cout << "YES" << '\n';
			else	cout << "NO" <<endl;
		}
	}
	return 0;
} 
