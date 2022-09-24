#include<iostream>
#include<cstdio>
#include<cmath>

int main(){
	int number;
	int sum;
	int gotMinus = 0;
	char opers;
	for(scanf("%d", &sum);scanf("%c", &opers),opers!='\n';){
		scanf("%d", &number);
		if(opers == '-'){
			gotMinus = 1;
		}
		if(gotMinus){
			sum -= abs(number);
		}
		else{
			sum+=number;
		}
	}

	std::cout << sum;
	return 0;
}
