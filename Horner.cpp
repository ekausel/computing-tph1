// Programm: Horner.cpp
// von Marcel & Emanuel (Gruppe08)
// Hornerschema
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o Horner Horner.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
using namespace std;  


int main()
{
char L; 
int i_max,i,n,k=0,u=0;
double w,Poly,x;
vector<double>Werte;


ifstream mcin("06_Poly.dat");

mcin>>L;
mcin>>L;
mcin>>i_max;

while (k<=i_max)
   {
   Werte.push_back(0);
   k++;
   }

mcin>>L;
mcin>>w;
Werte.at(i_max)=w;


while (u<i_max && i!=0) 
   {
   mcin>>L;
   mcin>>L;
   mcin>>i;
   mcin>>L;
   mcin>>w;
   Werte.at(i)=w;
   u++;
   }
   

ofstream mcout("Poly_out.dat");

for (x=0;x<=10;x=x+0.1)
   {  
   n=i_max;
   Poly=0;
   while(n>=0)
      {
      Poly=Poly*(x)+Werte.at(n);
      n=n-1;
      }
   mcout<<x<<"     "<<Poly<<endl;
   }






return 0;
}
