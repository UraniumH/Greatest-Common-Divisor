//By LZ-AHS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define llong unsigned long long
using namespace std;
llong zzxc(llong fst,llong scd){
	if(fst%scd==0){
		return scd;
	}else{
		return zzxc(scd,fst%scd);
	}
}
void recursion(llong a,llong b){
	clock_t begin,end;
	begin = clock();
	llong temp=zzxc(a,b);
	end = clock();
	cout<<"GCD calculated by recursion algorithm: "<<temp<<endl;
	cout<<"SCM calculated by recursion algorithm: "<<(a/temp)*b<<endl;
	cout<<"Time used: "<<(end-begin)<<endl<<endl;
}

void enumeration(llong a,llong b){
	clock_t begin,end;
	llong temp;
	begin = clock();
	for(llong i=min(a,b);i>0;i-=1){
		if(a%i==0&&b%i==0){
			temp=i;
			break;
		}
	}
	end = clock();
	cout<<"GCD calculated by enumeration algorithm: "<<temp<<endl;
	cout<<"SCM calculated by enumeration algorithm: "<<(a/temp)*b<<endl;
	cout<<"Time used: "<<(end-begin)<<endl<<endl;
}

void multiplication(llong a,llong b){
	clock_t begin,end;
	llong temp;
	begin = clock();
	llong max=(a>b)?a:b;
	llong min=(a<b)?a:b;
	for(llong i=1;;i+=1){
		if((max*i)%min==0){
			temp=max*i;
			break;
		}
	}
	end = clock();
	cout<<"GCD calculated by multiplication algorithm: "<<a/(temp/b)<<endl;
	cout<<"SCM calculated by multiplication algorithm: "<<temp<<endl;
	cout<<"Time used: "<<(end-begin)<<endl<<endl;
}

bool hz(llong a,llong b){
	while(1){
		llong t = a%b;
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
void shortdivision(llong a,llong b){
	clock_t begin,end;
	llong temp=1;
	begin = clock();
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
	end = clock();
	cout<<"GCD calculated by short-division algorithm: "<<temp<<endl;
	cout<<"SCM calculated by short-division algorithm: "<<temp*a*b<<endl;
	cout<<"Time used: "<<(end-begin)<<endl<<endl;
}

int main(int argc,char *argv[]){
	llong a,b;
	if(argc==2){
		a=atol(argv[0]);
		b=atol(argv[1]);
	}else{
		cin>>a>>b;
	}
	cout<<endl;
	recursion(a,b);
	enumeration(a,b);
	multiplication(a,b);
	shortdivision(a,b);
	return 0;
}
