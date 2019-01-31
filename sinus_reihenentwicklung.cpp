// Programm: sinus_reihenentwicklung.cpp
// von Marcel & Emanuel (Gruppe 08)
// Schreibe ein C++-Programm, das einen Wert x einliest und 
// den zugehörigen Sinus sin(x) über seine Taylorentwicklung berechnet:


#include <iostream>  
using namespace std;   

int main()
{ 

  double x, sum=0;                        //Variablen definieren
  int n=0, fact=1 ;
  
   cout << "Gib eine Zahl ein: ";         //Input auf x speichern
   cin>> x;
   
  double y=x;                             //Neue Variable y einführen 
   
while (n<=24 && y>=1e-8) {                //while-Schleife mit zwei Bedingungen

   sum = sum + fact*y;                    //1.Term der Taylor Entwicklung (sum=x)
   
   fact = fact*(-1);                      //Vorzeichen des Terms der Taylorentwicklung
   n=n+1;                                 //Term-Index
   
   y= y*x*x/(2*n*(2*n+1));                //Rekursive Definition der Terme
      
   
  
}   
 cout<<"x = "<<x<<" ; sinus("<< x<<") = "<< sum<<" ; Anzahl der Terme = "<<n << endl;  
 
  return 0;   
}
