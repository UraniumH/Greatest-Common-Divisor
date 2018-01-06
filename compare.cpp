#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define llong unsigned long long
using namespace std;
llong zzxc(llong fst,llong scd){
	if(fst%scd==0){
		return scd;
	}else{
		return zzxc(scd,fst%scd);
	}
}
void recursion(int a,int b){
	llong temp=zzxc(a,b);
	cout<<"GCD calculated by recursion algorithm: "<<temp<<endl;
	cout<<"SCM calculated by recursion algorithm: "<<(a/temp)*b<<endl;
}

void enumeration(int a,int b){
	llong temp;
	for(llong i=min(a,b);i>0;i-=1){
		if(a%i==0&&b%i==0){
			temp=i;
			break;
		}
	}
	cout<<"GCD calculated by enumeration algorithm: "<<temp<<endl;
	cout<<"SCM calculated by enumeration algorithm: "<<(a/temp)*b<<endl;
}

void multiplication(int a,int b){
	llong temp;
	llong max=(a>b)?a:b;
	llong min=(a<b)?a:b;
	for(llong i=1;;i+=1){
		if((max*i)%min==0){
			temp=max*i;
			break;
		}
	}
	cout<<"GCD calculated by multiplication algorithm: "<<a/(temp/b)<<endl;
	cout<<"SCM calculated by multiplication algorithm: "<<temp<<endl;
}

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
void shortdivision(int a,int b){
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
	cout<<"GCD calculated by short-division algorithm: "<<temp<<endl;
	cout<<"SCM calculated by short-division algorithm: "<<temp*a*b<<endl;
}

int main(int argc,char *argv[]){
	llong a,b;
	if(argc==2){
		a=atoi(argv[0]);
		b=atoi(argv[1]);
	}else{
		cin>>a>>b;
	}
	recursion(a,b);
	enumeration(a,b);
	multiplication(a,b);
	shortdivision(a,b);
	return 0;
}
