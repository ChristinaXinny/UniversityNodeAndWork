#include <iostream>

using namespace std;


void BubbleSort(int a[], int n){
	for(int i=0; i<n-1; i++){
		int count = 0;
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				count++;
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		
		for(int j=0; j<n; j++){
			printf("%d ",a[j]);
		}
		printf("\n");
		if(count==0)break;
	}
}

int main(int argc, char *argv[]) {
	int n;
	while(~scanf("%d",&n)){
		int a[n];
		for(int i=0; i<n ;i++){
			scanf("%d",&a[i]);
		}
		BubbleSort(a, n);
	}
}