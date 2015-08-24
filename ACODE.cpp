#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main(){
	string code;
	while(1){
		code="";
		cin>>code;
		if(code[0]=='0')
			break;
		unsigned int s[code.length()];
		memset(s,0,sizeof(s));
		if(code[code.length()-1]!=0)
			s[code.length()-1]=1;
		for(int i = code.length()-2 ; i>=0 ; i--){
			if(i==code.length()-2){
				if((code[i]-'0')*10+code[i+1]-'0'==0){
					s[0]=0;
					break;
				}
				if(code[i]=='0')
					s[i] = s[i+1];
				else if((code[i]-'0')*10+code[i+1]-'0'<=26 && code[i+1]!='0')
					s[i] = 2;
				else
					s[i] = 1;
			}else{
				if((code[i]-'0')*10+code[i+1]-'0'==0){
					s[0]=0;
					break;
				}
				// cout<<"here\n";
				if(code[i]=='0')
					s[i] = s[i+1];
				else if((code[i]-'0')*10+code[i+1]-'0'<=26 && code[i+1]!='0')
					s[i] = s[i+1] + s[i+2];
				else
					s[i] = s[i+1];
			}
		}
		// for(int i=0;i<code.length();i++)
		// 	cout<<s[i];
		// cout<<endl;
		cout<<s[0]<<endl;
	}
	return 0;
}
