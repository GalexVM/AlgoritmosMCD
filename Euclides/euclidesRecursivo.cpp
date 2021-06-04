#include <iostream>
    using std::cout;
    using std::endl;
#include <NTL/ZZ.h>
    using NTL::ZZ;
ZZ mod(ZZ a, ZZ b){
    ZZ q= a/b;
	ZZ	r= a- (q*b);
	if(a<ZZ(0)){
		ZZ ar=r;
	    r= b+ar;
	}
	return r;
}
ZZ eu_recursivo(ZZ a, ZZ b){

	if (b==ZZ(0)) return a; //caso base
	return (eu_recursivo(b,mod(a,b)));
}

int main(){

    cout<<eu_recursivo(ZZ(309679010214990749391078504540567233294),ZZ(29820878592520697226032517101025307608));
}
