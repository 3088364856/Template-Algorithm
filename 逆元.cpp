#include <bits/stdc++.h>
const int mod = 1e9+7;


// Fei Ma Small Principle  
// Need: p is prime 
// Solve: a*res == 1 (mod p)
auto qp = [](long long a, long long p = mod-2){
	long long res = 1;
	while(p){
		if(p&1)	res*= a;
		a *= a;
		res %= mod;
		a %= mod;
		p >>= 1;
	}
	return res;
};

// exgcd 
// Need: gcd(a,b) == 1
// Solve: ax == 1 (mod b)
auto exgcd(long long a ,long long b,long long &x, long long &y)->void{
	if(!b)	{
		x = 1, y = 0;
		return ;	
	}
	exgcd(b,a%b,y,x), y -= a / b *x;
	return ;
}

// 1-n
// Solve: [1,N] Modular Multiplicative Inverse 
auto find_all(int N = 1e5)->void{
	++N;
	std::vector<long long> inv(N,0);
	inv[1] = 1;
	for(int i = 2; i < N; ++i)	{
		inv[i] = (long long)(mod-mod/i)*inv[mod%i]%mod;
	}
}

int main(){
	return 0;
}

