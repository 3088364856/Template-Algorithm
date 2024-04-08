#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull p = 131;
const int N = 5e5+10;
ull P[N], H[N];
ull get_hash(int l, int r)	{return H[r]-H[l-1]*P[r-l+1];}
void init_hash(){
	P[0] = 1;
	for(int i = 1; i < N; ++i)	P[i] = P[i-1]*p;
}
string s;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	unordered_map<int,int> v[3];
	v[1][2] = 1;
	
	return 0;
}
