// Programm: QM.cpp
// von Marcel & Emanuel (Gruppe08)
// quantenmechanischer harmonischer oszillator 
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o QM QM.cpp


#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;  

double eigenzust(double x)
{

   double y=pow(M_PI,-0.25)*exp(-x*x/2.);
   return y;
}


long double integriere(vector<double>v_x,vector<double>v_y,int n)
{
   

   long double integral,summe=0;
   int i=0;
   while (i<n){
      summe=summe+(v_x[i+1]-v_x[i])*(v_y[i+1]+v_y[i]);      
      i++;
    }
    
   integral = 0.5*summe;
   return integral;
}


int main()
{
   int n,i=0;
   double x_max,x,a=0,da;
   cout<<"x_max = ";
   cin>>x_max;
   cout<<"n = ";
   cin>>n;
   da=(2*x_max)/(n-1);
   
   vector<double>v_x;
   vector<double>v_y;
   
   while (i < n){
      x=-x_max+a;
      v_x.push_back(x);
      v_y.push_back(x*x*eigenzust(x)*eigenzust(x));
      a=a+da;
      
      cout<<"x = "<<x<<", psi(x) = "<<eigenzust(x)<<endl;
      cout<<"y= "<<v_y[i]<<endl;
      i++;
   }
   
   cout<<"Integral = "<<integriere(v_x,v_y,n)<<endl;
  

   return 0;
}
