// Programm: Nullstelle.cpp
// von Marcel & Emanuel (Gruppe08)
// Nullstelle suchen mittels regula falsi
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o Nullstelle Nullstelle.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <math>
using namespace std;  

double Ru21(r)
   {
   double R ,a=5.2917721067e-11;
   R=2*(1/(2a))**(3/2)*(1-r/(2a))*exp(-r/(2a));
   return R;
   }



int main()
   {
   double r_neu, k, d, r_l=0, r_r=10;
   
   k=(Ru21(r_r)-Ru21(r_l))/(r_r-r_l);
   d=Ru21(r_r)-(k*r_r);
   r_neu=-d/k;
   
   if (Ru21(r_neu)>0){      
      r_l=r_neu;}
   else{
      if (Ru21(r_neu)<0){
         r_r=r_neu;
         }
      else{
         cout<<"Nullsteelle befindet sich bei r= "<<r_neu<<endl;
         }
      }
   }
