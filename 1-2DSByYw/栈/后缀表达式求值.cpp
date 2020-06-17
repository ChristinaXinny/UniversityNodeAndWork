#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char str[100];
	while(~scanf("%s",str)){
		int num[100];
		int len = strlen(str);
		int j=-1;
		for(int i=0; i<len; i++){
			
			if(str[i]>='0'&&str[i]<='9'){
				num[++j] = str[i]-'0';
			}
			else {
				int a,b,ans;
				a = num[j--];
				b = num[j--];
				switch (str[i]) {
					case '+':
						ans = b + a;
						break;
					case '-':
						ans = b - a;
						break;
					case '*':
						ans = b * a;
						break;
					case '/':
						ans = b / a;
						break;
				}
				num[++j] = ans;
			}
		}
		int sum = num[j--];
		printf("%d\n",sum);
	}
}

