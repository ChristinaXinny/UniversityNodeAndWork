#include <iostream>

using namespace std;

void swap(int &x, int &y) {
	int temp = y;
	y = x;
	x = temp;
}

void prin(int a[], int n){
	for(int k=0; k<n; k++){
		printf("%d ",a[k]);
	}	
	printf("\n");
} 

void kuai(int a[], int l, int r){
	int n = l + r +1;
	int p = a[0];
	swap(p, a[l]);
	int i=l+1, j=r;
	while(i<j){
		while(a[i]<p)i++;
		while(a[j]>p)j--;
		if(i<j){
			swap(a[i], a[j]);
			prin(a, n);
		}
		else break;
	}
	a[0] = a[j];
	a[j] = p;
	prin(a, n);
}



void partition(int a[], int n){

		kuai(a, 0, n-1);
	
}


int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	getchar();
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
//	prin(a, n);
	partition(a, n);
	
}