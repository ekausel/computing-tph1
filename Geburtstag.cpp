// Programm: Geburtstag.cpp
// von Marcel & Emanuel (Gruppe08)
// 2Leute am selben Tag geburtstag
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o Geburtstag Geburtstag.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
using namespace std;  


double prob(int N)
{
   int n=365;
   double q=1.,p;
  
   while (n>=366-N)
      {
      q=q* n/365. ;
      
      n=n-1;
      
      }
   p = 1- q;
   return p;
}


int main()
{
int i,N0,N1;
ofstream mcout("geb_wahr.dat");

cout<<"N0=";
cin>>N0;
cout<<"N1=";
cin>>N1;
for(i=N0; i<=N1; i++)
   {
   mcout<<i<<"     "<<prob(i)<<endl;
   }

return 0;
}
