#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//#include<stack>
//using namespace std; 

//	stack<int> s1;
//	stack<char> s;
//	入栈，s.push(x);
//	出栈，s.pop();
//			注意，出栈操作只是删除栈顶元素，并不返回该元素
//	访问栈顶，s.top()
//	判断栈空，s.empty()，当栈空时，返回true
//	访问栈中的元素个数，s.size()。

int com(char s){
	int n = 0;
	switch (s){
		case '-':
			n = 3;
			break;
		case '+':
			n = 3;
			break;
		case '*':
			n = 6;
			break;
		case '/':
			n = 6;
			break;
	}
	return n;
}


int main(int argc, char *argv[]) {
	
	char str[100];
	
	while(~scanf("%s",str)){
		char sym[100];
		int j=-1;
		int temp = 0;//temp==0此时是括号外 temp==1是括号内
		for(int i=0; i<strlen(str); i++){
			
			if(str[i]>='0' && str[i]<='9'){
				printf("%d",str[i]-'0');
			}
			else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
				while(1){
					if(j==-1 || sym[j]=='('){
						sym[++j]=str[i];
						break;
					}
					else if(com(str[i])>com(sym[j])){
						sym[++j]=str[i];
						break;
					}
					else{
						printf("%c",sym[j]);
						j--;
					}	
				}
			}
			else{
				if(str[i]=='('){
					sym[++j]=str[i];
				}
				else{
					while(sym[j]!='('){
						printf("%c",sym[j]);
						j--;
					}
					j--;
				}
			}
		}
		while(j>-1){
			printf("%c",sym[j]);
			j--;
		}
		printf("\n");
	}
}
