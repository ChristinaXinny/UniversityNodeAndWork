#include<iostream>
#include<cstring>
#include<algorithm> 
#include<stack>
using namespace std;
 
stack<char> s1;  //运算符栈 
stack<char> s2;  //中间结果栈 
int f(const char str){
	 int yxj;  //优先级 
	 switch(str){
		case '*':yxj=5;break;
		case '/':yxj=5;break;
		case '+':yxj=4;break;
		case '-':yxj=4;break;
	 }
	return yxj;
 
}

int main(){
	char c[100];
		cin>>c;
	int lenc=strlen(c);
	for(int i=0;i<lenc;i++){
		if(c[i]>='0'&&c[i]<='9'){  
			s2.push(c[i]);
		}
		else if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'){
			while(true){
				if(s1.empty()||s1.top()=='('){  
					s1.push(c[i]);
					break;
				}
				else if(f(c[i])>f(s1.top())){  
					s1.push(c[i]);
					break;
				}
				else{       
					char cc=s1.top();
					s1.pop();
					s2.push(cc);
				}
			}
		}
		else{
			if(c[i]=='('){   
				s1.push(c[i]);
			}
			else{
				while(s1.top()!='('){
					char ccc=s1.top();
					s1.pop();
					s2.push(ccc);
				}
				s1.pop();
			}
		}
	}
	while(!s1.empty()){
		char cccc=s1.top();
		s2.push(cccc);
		s1.pop();
	}
	while(!s2.empty()){
		char c=s2.top();
		s1.push(c);
		s2.pop();
	}
	while(!s1.empty()){  
		cout<<s1.top();
		s1.pop();
	}
	
	return 0;
}