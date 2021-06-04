#include <iostream>
    using std::cout;
#include <NTL/ZZ.h>
    using NTL::ZZ;

ZZ* euclidesExtendidoNTL(ZZ a, ZZ b);


int main(){
    ZZ* valores = euclidesExtendidoNTL(ZZ(309679010214990749391078504540567233294),ZZ(29820878592520697226032517101025307608));
    for(ZZ*p=valores;p<valores+3;p++)
        cout<<*p<<' ';
    return 0;
}

ZZ* euclidesExtendidoNTL(ZZ a, ZZ b){
	ZZ d,x,y,q,r,s,t;
	if(b==0){
        d = a;
        x = 1;
        y = 0;
        static ZZ resultados[3] = {a,x,y};
        ZZ* rpta = resultados;
        return rpta;
	}
    ZZ x2 = ZZ(1);
    ZZ x1 = ZZ(0);
    ZZ y2 = ZZ(0);
    ZZ y1 = ZZ(1);
	while(b>0){
		q = a/b;

		r = a - (q*b);
		x = x2 - (q*x1);
		y = y2 - (q*y1);

		a = b;
		b = r;
		x2 = x1;
		x1 = x;
		y2 = y1;

		y1 = y;
	}
	d = a;
	x = x2;
	y = y2;
	static ZZ resultados[3] = {a,x2,y2};
	ZZ* rpta = resultados;
	return rpta;
}
