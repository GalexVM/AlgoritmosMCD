#include <iostream>
    using std::cout;
    using std::endl;
#include <NTL/ZZ.h>
    using NTL::ZZ;


ZZ eu_resta_rec(ZZ a, ZZ b){
    if(a==b) return a;
	else{
		if (a>b){	a=a-b;  }
		else{ 	b=b-a;  }
		return(eu_resta_rec(a,b));
	}
}
int main(){
    cout<<eu_resta_rec(ZZ(1456),ZZ(125));
}
