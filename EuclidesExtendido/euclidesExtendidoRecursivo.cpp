#include <iostream>
    using std::cout;
    using std::endl;
#include <NTL/ZZ.h>
    using NTL::ZZ;
#include <vector>
    using std::vector;
ZZ mod(ZZ a, ZZ b){
    ZZ q= a/b;
	ZZ	r= a- (q*b);
	if(a<ZZ(0)){
		ZZ ar=r;
	    r= b+ar;
	}
	return r;
}
ZZ d(0),k(0),l(0);
vector <ZZ>  euclides_ext(ZZ a, ZZ b){

  vector<ZZ> res = {d,k, l};
  if (b==ZZ(0))  return res = {a,ZZ(1),ZZ(0)}; //caso base

  ZZ q = mod(a,b);
  ZZ r = (a-q)/b;
  //a= r*b + q
  //a - q = r*b
  //(a-q)/b = r
  res = euclides_ext(b, q);
  d=res[0];
  k=res[1];
  l=res[2];
  return res = {d,l,k-l*r};
}
int main(){

    cout<<euclides_ext(ZZ(309679010214990749391078504540567233294),ZZ(29820878592520697226032517101025307608))[0];
    cout<<euclides_ext(ZZ(309679010214990749391078504540567233294),ZZ(29820878592520697226032517101025307608))[1];
    cout<<euclides_ext(ZZ(309679010214990749391078504540567233294),ZZ(29820878592520697226032517101025307608))[2]<<endl;

}
