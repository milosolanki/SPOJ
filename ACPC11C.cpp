#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,ls,rs,sum=0;
		cin>>n;
		int ln[n],ans[n],l[n];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++){
			cin >> ln[i];
			sum += ln[i];
			l[i] = sum;
		}
		for(int i=0;i<n;i++){
			if(i==0){
				ans[i] = sum - ln[i];
			}else if(i==n-1){
				ans[i] = sum - ln[i];
			}else{
				ls = l[i] - ln[i];
				rs = sum - l[i];
				if(ls<rs){
					ans[i] = 2*ls + rs;
				}else{
					ans[i] = 2*rs + ls;
				}
			}
		}
		int least = ans[0];
		for(int i=1;i<n;i++){
			if(ans[i]<least)
				least = ans[i];
		}
		cout<<least<<endl;
	}
	return 0;
}
