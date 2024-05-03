#include <bits/stdc++.h>

std::function<std::vector<int>(std::string s)> Z = [](std::string s){
	int n = (int)s.size();
	std::vector<int> z(n,0);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r && z[i-l] < r-i+1){
			z[i] = z[i-l];
		}else{
			z[i] = std::max(0,r-i+1);
			while(i+z[i] < n && s[z[i]] == s[i+z[i]])	++z[i];
		}
		if(i+z[i]-1 > r)	l = i, r = i+z[i]-1;
	}
	return z;
};

int main(){
	std::string s = "aabaaababbabbbaaabzz";
	std::vector<int> z = Z(s);
	
	for(auto x:z){
		std::cout << x << " ";
	}
	std::cout << '\n';
}
