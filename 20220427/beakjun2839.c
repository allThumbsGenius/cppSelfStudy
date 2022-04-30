#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
	if(a == -1 && b == -1){
		return -2;
	}

	if(a == -1){
		return b;
	}
	if(b == -1){
		return a;
	}

	return a<b ? a:b;
}

int main(){
	int n;
	int *f;

	scanf("%d", &n);
	
	f = (int*)malloc(sizeof(int) * (n+1));
	f[0] = 0;
	f[1] = -1;
	f[2] = -1;
	f[3] = 1;
	f[4] = -1;
	
	for(int i = 5; i <= n; ++i){
		f[i] = min(f[i-3], f[i-5]) + 1;
	}

	printf("%d\n", f[n]);

	free(f);

	return 0;
}
	
