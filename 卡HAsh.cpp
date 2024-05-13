#include <bits/stdc++.h>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int H = rng() & INT_MAX;

struct My_Hash{
	int operator()(int x) const {
		return x ^ H;
	}
};
int main(){
	std::unordered_map<int,int,My_Hash> mp; 
	std::cout << '\n';
}
