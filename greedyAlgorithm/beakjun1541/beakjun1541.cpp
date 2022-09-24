#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

int makeSum(int isPlus, int sum, int num){
	if(isPlus == 1){
		return sum + num;
	}
	return sum - num;
}
	

int main(){
	char lines[51];

	cin >> lines;

	int sum = 0;
	int isPlus = 1;
	int count = 0;
	int made = 0;
	vector<int> temp;

	for(int i = 0; i < strlen(lines); ++i){
		int made = 0;
		if(lines[i] >= 48 && lines[i] <= 57){
			count++;
			temp.emplace_back(lines[i] - 48);
		}
		if(lines[i] == '+'){
			while(count > 0){
				made += (temp[count-1] * (int)pow(10, temp.size()-count));
				count--;
			}
			sum = makeSum(isPlus, sum, made);
			temp.clear();
		}
		if(lines[i] == '-'){
			while(count > 0){
				made += (temp[count-1] * (int)pow(10, (temp.size()-1)-(count-1)));
				count--;
			}
			sum = makeSum(isPlus, sum, made);
			isPlus = 0;
			temp.clear();
		}
		if(i == strlen(lines)-1){
			while(count > 0){
				made += (temp[count-1] * (int)pow(10, (temp.size()-1)-(count-1)));
				count--;
			}
			sum = makeSum(isPlus, sum, made);
		}

	}
	
	cout << sum;

	return 0;
}
