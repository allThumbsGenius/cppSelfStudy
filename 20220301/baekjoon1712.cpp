#include<iostream>

int getBreakEvenPoint(int, int, int);

int main(){

	int fixedCost, variableCost, price;
	int totalIncome = 0;

	std::cin >> fixedCost >> variableCost >> price;

	int n = getBreakEvenPoint(fixedCost, variableCost, price);

	std::cout << n;

	return 0;
}

int getBreakEvenPoint(int fixedCost, int variableCost, int price){
	return (fixedCost) / (price - variableCost) + 1;
}	
