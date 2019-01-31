// Programm: Strecke1.1.cpp
// von Marcel & Emanuel (Gruppe08)
// Strecke
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o Strecke Strecke1.1.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;  

class strecke {

   private:
   vector<double>x;
   vector<double>y;
   vector<double>z;
   double min;
   double max;
   double sum;
   string S;
   double g,a,b,c;int i,k;
   
   
   
   public:
   strecke(string str):S(str){
   };
   ~strecke() {
   ofstream dat("ergebnisse.dat");
   dat << "Mittlerer Abstand(aufeinanderfolgender Punkte): " << sum/(x.size()-1) << endl << "Minimum: " << min << endl << "Maximum: " << max << endl;
   return;}
   
   
   double Min(){return min;};
   double Max(){return max;};
   double Mittel(){return (sum/x.size());};
   double Re();
};
   
   
double strecke::Re(){
      ifstream mcin(S);
      while (mcin>>a>>b>>c){
         x.push_back(a);
         y.push_back(b);
         z.push_back(c);
         i=0;
         if(k>=2){
            sum+=sqrt((x[k]-x[k-1])*(x[k]-x[k-1])+(y[k]-y[k-1])*(y[k]-y[k-1])+(z[k]-z[k-1])*(z[k]-z[k-1]));
            while(i<k){
               g=sqrt((x[k]-x[i])*(x[k]-x[i])+(y[k]-y[i])*(y[k]-y[i])+(z[k]-z[i])*(z[k]-z[i]));
               if (g>max){
                  max=g;
                  }
               else if (g<min){
                  min=g;
                  }
               i++;
               }
            }
         else if (k==1){
            min=sqrt((x[k]-x[k-1])*(x[k]-x[k-1])+(y[k]-y[k-1])*(y[k]-y[k-1])+(z[k]-z[k-1])*(z[k]-z[k-1]));
            max=min;
            sum=min;
            }
         k++;   
         }
      return 0;
      }

int main(){
   strecke M("07_pfad.dat");
   M.Re();
   return 0;
}
   

   
