#include<iostream>
#include<string>
#include "stock.h"

int main(){
	Stock temp;
	std::string what = "Panda";

	temp.show();
	temp.buy(10, 1200);
	temp.show();
	temp.sell(5, 800);
	temp.show();

	return 0;
}
