#include <iostream>
    using std::cout;
    using std::endl;
#include <NTL/ZZ.h>
    using NTL::ZZ;
    using NTL::RandomBits_ZZ;
#include <sstream>
    using std::ostringstream;
    using std::istringstream;
#include <string>
    using std::string;
ZZ algoritmoLehmer(ZZ x, ZZ y);//Tienen que estar dentro de Zn
ZZ modulo(ZZ a, ZZ b);
ZZ eu_clasico(ZZ a, ZZ b);
ZZ generar_aleatorioNTL(int bits);


int main(){

    ZZ resultado = algoritmoLehmer(ZZ(11289370736665826443035172330136603527902707647525459568326502033707598516141328567104955047281847367464322201762077175394580556486926955690337609308881195),ZZ(8198048337486084641347991022554317762190988542040250094912525370908284937250476707234704179055204673696670233771480866910561260487329183669036178753670077));
    cout<<resultado<<endl;

    return 0;
}

ZZ algoritmoLehmer(ZZ x, ZZ y){
    ZZ yMax, xMax;
    ZZ A,B,C,D,q,qq,t,T,u;

    ostringstream salidaX,salidaY;
    string digitosX,digitosY;
    while (y >= 10){

        //Obteniendo digitos de mayor orden de x  1.1

        salidaX<<x;

        digitosX = salidaX.str();
        //cout<<"digitosX: "<<digitosX<<endl;
        for(int i = 0; i<digitosX.size();i++){
            if(i>0)digitosX.erase(i);
        }
        istringstream entradaX (digitosX);
        entradaX>>xMax;
        //[0]



        //Obteniendo digitos de mayor orden de Y 1.1
        salidaY<<y;
        digitosY = salidaY.str();
        //cout<<"digitosY: "<<digitosY<<endl;
        for(int i = 0; i<digitosY.size();i++){
            if(i>0)digitosY.erase(i);
        }
        istringstream entradaY (digitosY);
        entradaY>>yMax;


        //1.2
        A = 1;B=0;C=0;D=1;
        //1.3
        while((yMax+C)!=0 && (yMax+D)!=0){


            q = (xMax+A)/(yMax+C);
            qq = (xMax+B)/(yMax+D);
            if(q != qq){
                break;
            }else{
                t = A-(q*C);
                A = C;
                C = t;
                t = B-(q*D);
                B = D;
                D = t;
                t = xMax-(q*yMax);
                xMax = yMax;
                yMax = t;
            }

        }
        //1.4
        if(B == 0){
            T = modulo(x,y);
            x = y;
            y = T;
            //cout<<"se cambian variables"<<endl;
            //cout<<"x: "<<x<<" y: "<<y<<endl;
        }else{
            T =(A*x)+(B*y);
            u = (C*x)+(D*y);
            x = T;
            y = u;
        }
    }

    //2
    ZZ v(eu_clasico(x,y));

    //3

    return v;
}
ZZ modulo(ZZ a, ZZ b){
	ZZ q= a/b;
	ZZ	r= a- (q*b);
	if(a<ZZ(0)){
		ZZ ar=r;
	    r= b+ar;
	}
	return r;
}
ZZ eu_clasico(ZZ a, ZZ b){
    if(a<b) return ZZ(-1);
    ZZ r;
	while(b!=ZZ(0)){
		r = modulo(a,b);
	    a=b;
	    b=r;
	}
	return a;
}
ZZ generar_aleatorioNTL(int bits){
    if(bits == 1)
        return RandomBits_ZZ(bits);
    ZZ numero(0);
    ZZ minNum(2);

    for(int x = 0;x<bits-2;x++)
        minNum= 2*minNum;

    while(numero<minNum)
        numero =RandomBits_ZZ(bits);

    return numero;
}
