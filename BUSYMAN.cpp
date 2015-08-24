#include <iostream>
#include <vector>
using namespace std;
void quicksort(int l[],int r[],int left,int right){
	int pivot = r[(left+right)/2];
	int temp,i=left,j=right;
	while(i<=j){
		while(r[i]<pivot) i++;
		while(r[j]>pivot) j--;
		if(i<=j){
			temp = r[j];
			r[j] = r[i];
			r[i] = temp;
			temp = l[j];
			l[j] = l[i];
			l[i] = temp;
			i++;j--;
		}
	}
	if(j>left) quicksort(l,r,left,j);
	if(i<right) quicksort(l,r,i,right);
	return;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int l[n],r[n];
		for(int i=0;i<n;i++)
			cin >> l[i] >> r[i];
		quicksort(l,r,0,n-1);
		// for(int i=0;i<n;i++){
		// 	cout << l[i] << " " << r[i] << endl;
		// }
		int count=1,current=0;
		for(int i=1;i<n;i++){
			if(l[i]>=r[current]){
				count++;
				current = i;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
