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
ZZ eu_div(ZZ a, ZZ b, ZZ r){
	r= mod(a,b);
	if (r==ZZ(0)) return b; //caso base
	if(r> (b/2)) {r=b-r;}
	return (eu_div(b,r,r));
}

int main(){

    cout<<eu_div(ZZ(452),ZZ(24),ZZ(0))<<endl;

}

