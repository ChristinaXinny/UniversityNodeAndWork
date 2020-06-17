#include <iostream>

using namespace std;


void in_place(int a[], int n){
	
	for(int i=1; i<n; i++){
		if (a[i]< a[i-1]){
			int temp = a[i];
			for (int j=i; j>=0; j--){
				if(j>0 && a[j-1]>temp) {//保证最前面的数字会被改变
					a[j]=a[j-1];
				}
				else {
					a[j]=temp;
					break;
				}
			}
		}
		for(int j=0; j<n; j++){
			if(j==n-1){
				printf("%d\n",a[j]);
				break;
			}
			printf("%d ",a[j]);
		}
	
	}
}

int main(int argc, char *argv[]) {
	int n;
	while(~scanf("%d",&n)){
		
	
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
			
		}
		in_place(a, n);
		
	}
}