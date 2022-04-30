#include<iostream>
#include<vector>



int main(){
	int n;
	std::vector<int> intArray;

	std::cin >> n;

	for(int i = 0; i < n; ++i){
		int k;
		std::cin >> k;
		intArray.push_back(k);
	}

	return 0;
}
