#include "stock.h"

void Stock::acquire(std::string &co, int n, float pr){
	name = co;
	shares = n;
	shareVal = pr;
	setTotal();
}

void Stock::buy(int n, float pr){
	shares += n;
	shareVal = pr;
	setTotal();
}

void Stock::sell(int n, float pr){
	shares -= n;
	shareVal = pr;
	setTotal();
}

void Stock::update(float pr){
	shareVal = pr;
	setTotal();
}

void Stock::show(){
	std::cout << "회사명 : " << name << std::endl;
	std::cout << "주식수 : " << shares << std::endl;
	std::cout << "주가 : " << shareVal << std::endl;
	std::cout << "주식 총 가치 : " << totalVal << std::endl;
}

Stock &Stock::topval(Stock& s){
	if(s.shareVal > shareVal){
		return s;
	}
	else{
		return *this;
	}
}

Stock::Stock(std::string co, int n, float pr){
	name = co;
	shares = n;
	shareVal = pr;
	setTotal();
}

Stock::Stock(){
	name = "";
	shares = 0;
	shareVal = 0;
	setTotal();
}

Stock::~Stock(){
	std::cout << name << "클래스가 완료되었습니다.\n";

}

