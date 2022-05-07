#include<iostream>
#include<vector>

int main(){
	int howManyTypeOfCoin;
	int whatToMake;
	int count = 0;
	std::vector<int> typeOfCoin;
	
	std::cin >> howManyTypeOfCoin >> whatToMake;
	for(int i = 0; i < howManyTypeOfCoin; ++i){
		int n;
		std::cin >> n;
		typeOfCoin.push_back(n);
	}
	
	for(int i = howManyTypeOfCoin - 1; i >= 0; --i){
		count += whatToMake / typeOfCoin[i];
		whatToMake = whatToMake % typeOfCoin[i];
	}

	std::cout << count;

	return 0;

}
