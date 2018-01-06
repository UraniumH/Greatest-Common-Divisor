#include<iostream>
#define llong unsigned long long
using namespace std;
llong zzxc(llong fst,llong scd){
	if(fst%scd==0){
		return scd;
	}else{
		return zzxc(scd,fst%scd);
	}
}
int main(){
	llong a,b;
	cin>>a>>b;
	llong temp=zzxc(a,b);
	cout<<"Greatest common devisor: "<<temp<<endl;
	cout<<"Smallest common multiplier: "<<(a/temp)*b<<endl;
	getchar();
	return 0;
}
