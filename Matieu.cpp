// Programm: Matieu.cpp
// von Marcel & Emanuel (Gruppe08)
// 
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o matieu Matieu.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;  

class atom {
   protected:
      string symbol;
      int z;
      double am; //Atommasse
      
   public:
      atom(string symbol,int z,double am):symbol(symbol),z(z),am(am){}; //Konstruktor
      atom(){}; // default konstruktor
      ~atom() {}; // Destruktor
      
      void atshow() {cout<<"Element: "<<symbol<<"  "<<"Ordnungszahl: "<<z<<"  "<<"Atommasse [g/mol]: "<<am<<endl;};
      double get_am() {return am;};
      int get_z() {return z;};
      string get_symbol() {return symbol;};
      void set_am(double am_neu) {am=am_neu;};
      void set_z(int zn) {z=zn;};
      void set_symbol(string str) {symbol=str;};
};


class molek {
   private:
      atom A;
      atom B;
      
   protected:
      int a,b;
     // stringstream sa; sa<<a; string k = sa.str();
     // stringstream sb; sb<<b; string l = sb.str();
      
      
      string formel = A.get_symbol()+to_string(a)+" "+B.get_symbol()+to_string(b) ;
      
      double mm=a*A.get_am()+b*B.get_am();   //Molekularmasse
      
      
   public:
      
      molek(atom A, int a, atom B, int b):A(A), a(a), B(B), b(b) {}; //Konstruktor
      // molek() {}; //default konstruktor
      ~molek() {};
      
      //void show() {cout<<formel<<z<<am<<endl;};
      double get_mm() {return mm;};
      int get_a() {return a;};
      int get_b() {return b;};
      string get_formel() {return formel;};
      
      void set_a(double a_neu) {a=a_neu;};
      void set_b(double b_neu) {b=b_neu;};  
       
      void molshow() {cout<<"Molekül: "<<formel<<"    Molekülmasse [g/mol]: "<<mm<<endl;};
      
      
      
};

class material: public molek {

   private:
      double schm;
      double sied;
      
   protected:
   
   public:
      material(atom A, int a, atom B, int b,double schm, double sied):molek(A, a, B, b),schm(schm),sied(sied){} //Konstruktor
      ~material() {}; //Destruktor
      double get_schm() {return schm;};
      double get_sied() {return sied;};
      
      void set_schm(double schm_neu) {schm=schm_neu;};
      void set_sied(double sied_neu) {sied=sied_neu;};
      
      void matshow() {cout<<"Material: "<<formel<<"   Schmelzpunkt: "<<schm<<"  "<<"Siedepunkt: "<<sied<<"  "<<endl;};
      
      string aggro() {
         double temp;
         cout<<"Welche Temperatur hat das Material? ";
         cin>>temp;
         if (temp < schm) cout<<"Material ist fest"<<endl;
         else if (temp> sied) cout<<"Material ist gasförmig"<<endl;
         else cout<<"Material ist flüssig"<<endl;
      }
      
};

int main(){

atom sauerstoff("O",8,16.00);
sauerstoff.atshow();
atom schwefel("S",16,32.065);
schwefel.atshow();

molek s2o(schwefel,2,sauerstoff,1);
s2o.molshow();

material so3(schwefel, 1,sauerstoff,3,16.9,45);
so3.matshow();

so3.aggro();

return 0;}


