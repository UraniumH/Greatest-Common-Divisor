#include<iostream>
#define llong unsigned long long
using namespace std;
int main(){
	llong a,b;
	cin>>a>>b;
	llong temp;
	for(llong i=min(a,b);i>0;i-=1){
		if(a%i==0&&b%i==0){
			temp=i;
			break;
		}
	}
	cout<<"Greatest common devisor: "<<temp<<endl;
	cout<<"Smallest common multiplier: "<<(a/temp)*b<<endl;
	system("pause>nul");
	return 0;
}
