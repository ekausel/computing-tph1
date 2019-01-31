// poly-Klasse
//
// von: Marcel & Emanuel

#ifndef _poly  
#define _poly

#include<iostream>
#include<cmath>

using namespace std;

class poly
{
private:
  size_t num;
  double *feld;
  
  void add0(size_t n=1)  // Gibt n mal 0 dazu...  Falls beim Addieren verschieden groß
  {
    double *neu;
    neu = new double[num+n];  // neues Feld mit richtiger Größe
    for (size_t i=0; i<num; i++) neu[i]=feld[i];  // alte Elemente kopieren
    for (size_t i=num; i<num+n; i++) neu[i]=0;  // alte Elemente kopieren
    
    delete [] feld; // altes Feld weg
    feld = neu;  // feld mit neuem überschreiben
    num +=n;  // neues num schreiben
    return;
  }
  
 public:
 
 poly(size_t n=1) : num(n)
  {
    feld = new double[num];
  }
  // Konstruktor: neu
 poly(const double pv[],size_t n) : num(n)
  {
    feld = new double[num];
    int i;
    for (i=0; i<num;i++) {feld[i]=pv[i];}
  }
  // Destruktor
  ~poly () { delete [] feld; }

  // Kopierkonstruktor
  poly (poly const &reS) : num(reS.num)
  {
    feld = new double[num];
    for (size_t i=0; i<num; i++) {feld[i]=reS.feld[i];}
  }

  // Zuweisungsoperator
  poly &operator=(const poly &reS)
  {
    if (this==&reS) return *this;  // schützt vor Selbstzerstörung bei Selbstzuweisung
    delete [] feld;  // weg mit dem originalen Feld!
    num = reS.num;
    feld = new double[num];
    for (size_t i=0; i<num; i++) feld[i]=reS.feld[i];
    return *this; 
  }
  
  void info()
  {
    cout << "Feld ("<< num <<"): " << endl;
    for (size_t i=0; i<num; i++) cout << feld[i] << ' '; 
    cout << endl<< endl;
    return;
  }

  bool setVal(const size_t i, const double &x) {if(i<num) {feld[i] = x; return true;} return false;}

  poly &operator+=(const poly & rS)
  {
    if (num<rS.num){
      int n = rS.num-num;
      add0(n);
    }
      
    for (size_t i=0; i<num; i++)
      feld[i] += rS.feld[i];
    return *this;
  }

  poly operator+(const poly & rS)
  {
    poly sum(*this);
    sum += rS;
    return sum;
  }

  poly &operator*(const poly & rS)
  {
   int sizel=num, sizer=rS.num;
   poly feld2(sizel+sizer-1);
   
   //feld2.feld[0]=feld[0]*rS.feld[0];
   for (size_t i=0;i<sizel;i++){
      for (size_t k=0; k<sizer;k++){
         feld2.feld[i+k]+=feld[i]*rS.feld[k];
         //cout << "feld2("<< i <<"+"<< k <<"): "<< feld2.feld[i+k]<< endl;
  
      }
   }
  //cout<<rS.feld[0]<<"  "<<feld[0]<<endl;
   cout << "feld2[0]"<< feld2.feld[0]<<endl;
   add0(sizer-1);
   for (size_t i=0; i<num; i++){
      feld[i] = feld2.feld[i];}
   return *this;
  }

  void pop_back() {
    num--;
  }
  
  
  double eval(double x){
    double summe=0;
    for (size_t i=0; i<num;i++){
        summe+=feld[i]*pow(x,(i));
         
    }
      return summe;
     
  }
};
#endif
