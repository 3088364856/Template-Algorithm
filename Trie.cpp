#include <bits/stdc++.h>
using namespace std;
struct trie {
    static const int N = 3e6+10;
    int exist[N];
    int nxt[N][65], cnt;
    void init(){
        memset(exist,0,sizeof exist);
        memset(nxt,0,sizeof nxt);
        cnt = 0;
    }
    void insert(const string& s){
        int p = 0;
        for(int i = 0; i < s.size(); ++i){
            int t = s[i]-'a';
            if(!nxt[p][t])  nxt[p][t] = ++cnt;
            p = nxt[p][t];
        }
		exist[p] = 1;
    }

    int search(const string& s){
        int p = 0;
        for(int i = 0; i < s.size(); ++i){
            int t = s[i]-'a';
            if(!nxt[p][t])  return 0;
            p = nxt[p][t];
        }
        return p;
    }
};
int T,n,m;
trie t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        t.init();
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            t.insert(s);
        }
        while(m--){
            string s;
            cin >> s;
            cout << t.search(s) <<endl;
        }
    }
    return 0;
}
