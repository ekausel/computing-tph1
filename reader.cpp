// Programm: reader.cpp
// von Marcel & Emanuel (Gruppe08)
// Text einlesen und analysieren
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o reader reader.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
using namespace std;  


int main()
{
int i;
vector<int>a;
   for (i=0;i<=100;i++ ){
      a.push_back(0);
   }

ifstream istr("05_Englisch.txt"); 

string s;
int e_Anzahl=0,l_max=0,l;
int p;
double u=0.;

   while (istr>>s) 
   {
      l=s.length();
      if (l>l_max){l_max=l;}

                
      u++;
      p = s.find("e");
      while (p!=string::npos)
      {
         e_Anzahl++;
         p = s.find("e", p+1);   
             
             
         } 
         
      a[l]++;
      
   }

cout<<"Es kommt "<<e_Anzahl<<" Mal der Buchstabe 'e' vor"<<endl<<endl;

int k=1;
   while(k<=l_max){
      cout<<k<<"    "<<a[k]<<"    "<<a[k]/u<<endl;
      k++;
   }
}
