// Programm: stella.cpp
// von Marcel & Emanuel (Gruppe08)
// Strecke
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o stella stella.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;  

class stellar {
   private:
      string S;
      pair<double,string>Stern;
      map<pair<double,string>,string>m;
      double x,y,z,r;
      string egal,Sternbild, Name;
      
      map<string,pair<double,string>>n; 
   
   public:

      stellar(string str): S(str){};     //Konstruktor
      ~stellar() {}; /////destruktOar
      double einlesen(){
         ifstream mcin(S);
         while (mcin>>x>>y>>z>>egal>>Sternbild){
            getline(mcin,Name);
            r=sqrt(x*x+y*y+z*z);
            Stern.first=r;
            Stern.second=Name;
            m[Stern] = Sternbild;
            
            n.emplace(Sternbild,Stern);
            if (Stern.first < n[Sternbild].first ){n[Sternbild] = Stern;}
            
            }
         return 0; 
      }
      
      
      void print(){
         for(auto it = m.begin(); it != m.end(); ++it) {
         cout <<"Stern: "<<it->first.second << "                     Distanz:   "<<it->first.first<< endl;
         
      }}
         
      
    
       void count(){
         int c=0;
         for(auto it = m.begin(); it != m.end(); ++it) {
            if (it->first.first <= 100.){
               c++;
            }
         }
      cout<<"Es befinden sich "<<c<<" Sterne im Abstand <=100LJ zur Sonne"<<endl;
      }
      
      
      
       void geringster_abstand(){
       
     
       
         for(auto it = n.begin(); it != n.end(); ++it) {
         cout <<"Im Sternbild:    "<<it->first << "   ist der Stern   "<<it->second.second<<"     der Sonne am nächsten."<< endl;
         
      }
      }
      
      
      
};

int main(){

   stellar X("09_stellar.dat");
   X.einlesen();
   X.print();
   cout<<endl<<endl;
   X.count();
   cout<<endl<<endl;
   X.geringster_abstand();
   
   return 0;}
