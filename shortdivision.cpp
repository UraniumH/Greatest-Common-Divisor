#include<iostream>
#define llong unsigned long long
using namespace std;
bool hz(int a,int b){
	while(1){
		int t = a%b;
		if(t == 0){
			break;
		}else{
			a = b;
			b = t;
		}
	}
	if(b>1){
		return false;
	}else{
		return true;
	}
}
int main(){
	llong a,b;
	cin>>a>>b;
	llong temp=1;
	llong max=(a>b)?a:b;
	llong min=(a<b)?a:b;
	for(;;){
		for(llong i=1;i<=min;i+=1){
			if(a%i==0&&b%i==0){
				temp*=i;
				a/=i;
				b/=i;
				continue;
			}
		}
		if(hz(a,b)){
			break;
		}
	}
	cout<<"Greatest common devisor: "<<temp<<endl;
	cout<<"Smallest common multiplier: "<<temp*a*b<<endl;
	system("pause>nul");
	return 0;
}
