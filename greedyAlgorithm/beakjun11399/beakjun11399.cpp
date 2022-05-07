#include<iostream>
#include<algorithm>
#include<vector>

int caculateTime(std::vector<int> timePerPerson){
	int totalSum = 0;
	int howManyPerson = timePerPerson.size();

	for(int i = 0, j = howManyPerson; i < howManyPerson; ++i, --j){
		totalSum += timePerPerson[i] * j;
	}

	return totalSum;
}

int main(){
	int n;
	std::vector<int> timePerPerson;

	std::cin >> n;

	for(int i = 0; i < n; ++i){
		int time;
		std::cin >> time;
		timePerPerson.push_back(time);
	}

	std::sort(timePerPerson.begin(), timePerPerson.end());

	std::cout << caculateTime(timePerPerson);

	return 0;

}
