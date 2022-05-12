#include<iostream>

int min(int a, int b){
	return a<b ? a : b;
}

int min(int a, int b, int c){
	return (a<b ? a : b)<c ? (a<b ? a : b) : c;
}

int main(){
	int x;
	int *f;

	std::cin >> x;

	f = new int[x + 1];

	f[0] = 0;
	f[1] = 0;
	f[2] = 1;
	f[3] = 1;

	for(int i = 4; i <= x; ++i){
		if(i%6 == 0){
			f[i] = min(f[i/3], f[i/2], f[i-1]) + 1;
		}
		else if(i%3 == 0){
			f[i] = min(f[i/3], f[i-1]) + 1;
		}
		else if(i%2 == 0){
			f[i] = min(f[i/2], f[i-1]) + 1;
		}
		else{
			f[i] = f[i-1] + 1;
		}
	}


	std::cout << f[x];

	delete[] f;
}
