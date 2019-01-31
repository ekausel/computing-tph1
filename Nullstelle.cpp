// Programm: Nullstelle.cpp
// von Marcel & Emanuel (Gruppe08)
// Nullstelle suchen mittels regula falsi
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o Nullstelle Nullstelle.cpp


#include <iostream> 
#include <string>
#include <cmath>
using namespace std;  

 long double R21(long double r)
   {
    long double R ;
    long double const a0=0.529e-10;
   R=2*pow((1/(2*a0)),(3/2.))*(1-r/(2*a0))*exp(-r/(2*a0));
   
   return R;
   }



int main()
{std::cout<<"\a";
   bool Nullstelle = false;
    long double r_neu, k, d, r_l=0, r_r=100;
   
   while (Nullstelle == false){
      k=(R21(r_r)-R21(r_l))/(r_r-r_l);
      d=R21(r_r)-(k*r_r);
      r_neu=-d/k;
      cout<<d<<"  "<<k<<"  "<<r_neu<<"  "<<R21(r_neu)<<"   "<<"TEST1"<<endl;
      if (R21(r_neu)>0){      
         r_l=r_neu;
         cout<<"TEST2"<<endl;
         }
      else {
         if (R21(r_neu)<0){
            r_r=r_neu;
            cout<<"TEST3"<<endl;
            }
         else{
            Nullstelle = true ;
            cout<<"Nullstelle befindet sich bei r= "<<r_neu<<endl;
            }
         }
   }
   
   
   
  return 0;
   }
