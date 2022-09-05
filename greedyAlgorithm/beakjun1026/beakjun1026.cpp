#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void vectorInput(vector<int> &v, int N){
	for(int i = 0; i < N; i++){
		int number;
		cin >> number;
		v.emplace_back(number);
	}
}

int findIndexOfNum(vector<int> &v, int n){
	vector<int>::iterator iter;
	iter = find(v.begin(), v.end(), n);
	*iter = -1;
	return iter - v.begin();
}

int vectorMul(vector<int> a, vector<int> b, int n){
	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum += a[i]*b[i];
	}
	return sum;
}

int main(){
	vector<int> A;
	vector<int> B;
	int N;

	cin >> N;

	vectorInput(A, N);
	vectorInput(B, N);

	vector<int> tempA;
	vector<int> tempB;
	vector<int> tempBTwo;

	tempA = A;
	tempB = B;
	tempBTwo = B;
	
	sort(tempA.begin(), tempA.end());
	sort(tempB.begin(), tempB.end(), greater<>());

	for(int i = 0; i < N; i++){
		A[findIndexOfNum(tempBTwo, tempB[i])] = tempA[i];
	}

	cout << vectorMul(A, B, N);

	return 0;
}
