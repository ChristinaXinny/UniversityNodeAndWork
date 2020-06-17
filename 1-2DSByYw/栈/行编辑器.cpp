#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) 
{
	char str[100];
//	scanf("%s",str);
	gets(str);
	char a[100];
//	getchar();
	int i=0, j=0;
	while(i <= strlen(str)){
		if(str[i]=='#'){
			j--;
			i++;
			continue;
		}
		if(str[i]=='@'){
			j = 0;
			i++;
			continue;
		}
		a[j] = str[i];
		j++;
		i++;
	}
	
	printf("%s",a);
}