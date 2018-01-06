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
	cout<<temp<<endl;
	cout<<(a/temp)*b<<endl;
	getchar();
}
