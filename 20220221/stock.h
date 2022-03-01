#ifndef STOCK
#define STOCK
#include<iostream>
#include<string>

class Stock{
	private:
		std::string name;
		int shares;
		float shareVal;
		double totalVal;
		void setTotal(){ totalVal = shares * shareVal; }
	public:
		void acquire(std::string&, int, float);
		void buy(int, float);
		void sell(int, float);
		void update(float);
		void show();
		Stock(std::string, int, float);
		Stock();
		~Stock();
};

#endif
