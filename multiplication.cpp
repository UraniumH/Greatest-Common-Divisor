#include<iostream>
#define llong unsigned long long
using namespace std;
int main(){
	llong a,b;
	cin>>a>>b;
	llong temp;
	llong max=(a>b)?a:b;
	llong min=(a<b)?a:b;
	for(llong i=1;;i+=1){
		if((max*i)%min==0){
			temp=max*i;
			break;
		}
	}
	cout<<"Greatest common devisor: "<<a/(temp/b)<<endl;
	cout<<"Smallest common multiplier: "<<temp<<endl;
	system("pause>nul");
	return 0;
}
