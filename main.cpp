#include<iostream>
using namespace std;
long zzxc(long fst,long scd){
	if(fst%scd==0){
		return scd;
	}else{
		return zzxc(scd,fst%scd);
	}
}
int main(){
	long a,b;
	cin>>a>>b;
	long temp=zzxc(a,b);
	cout<<"Greatest common devisor: "<<temp<<endl;
	cout<<"Smallest common multiplier: "<<(a/temp)*b<<endl;
	getchar();
}
