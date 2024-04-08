/*
	Author: Fri59h2
	Description:
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PI arcos(-1)
const int mod = 1e9+7;
const int N = 1e6+1;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
//const int dir[8][2] = {1,0,0,1,-1,0,0,-1,-1,-1,1,1,1,-1,-1,1};
#define x first
#define y second
#define endl '\n'
#define all(x)	(x).begin(),(x).end()
#define mst(x,val)  memset((x),(val),sizeof (x))
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
typedef pair<int,int> pii;
int n, m, k, q, T;
vector<int> prime;
vector<int> visited;
void get(){
    visited.assign(N,0);
    for(int i = 2; i < N; ++i){
        if(!visited[i]){
            prime.push_back(i);
        }
        for(int j = 0; j < prime.size(); ++j){
            if(1ll*i*prime[j] >= N)	break;
            visited[i*prime[j]] = prime[j];
            if(i%prime[j] == 0)	break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    get();
    T = 1;
    cin >> T;
    while(T--){
        cin >> n;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            while(visited[x]){
                ++mp[visited[x]];
                x /= visited[x];
            }
            if(x > 1)	++mp[x];
        }
        auto solve = [&](){
            for(auto&[x,y]:mp){
                if(y%n != 0)	{
                    no;
                    return ;
                }
            }
            yes;
        };
        solve();
		
    }
    return 0;
}
