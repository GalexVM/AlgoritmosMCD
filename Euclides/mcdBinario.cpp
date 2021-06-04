#include <iostream>
    using std::cout;
    using std::endl;
#include <NTL/ZZ.h>
    using NTL::ZZ;

ZZ var(ZZ a){ //valor absoluto
	if(a>=ZZ(0)){ return a;	}
	else {return -a; }
}
ZZ eu_binario(ZZ x, ZZ y ){
	//if (x<y){ return ZZ(-1);}
    ZZ g(1) ,t;

    while(x==y){

	    x=x/2;
	    y=y/2;
	    g=2*g;
    }
    while(x!=ZZ(0)){

	    while(x%2==ZZ(0)){x=x/2;	}
	    while(y%2==ZZ(0)){y=y/2;	}
	    t= var(x-y) /2;
	    if (x>=y){x=t;   }
	    else{y=t;	}
    }

    return (g*y);
}

int main(){
    cout<<eu_binario(ZZ(1456),ZZ(123));
}
