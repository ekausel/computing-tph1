// Programm: Potenzmethode.cpp
// von Marcel & Emanuel (Gruppe08)
// 
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o Potenzmethode Potenzmethode.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
#include <eigen3/Eigen/Dense>
using namespace std;  
using namespace Eigen;




vector<double> multnorm(Matrix<double,4,4>A,vector<double>v1) {

vector<double>v2={0,0,0,0};
   double pr=0, bet=0;
   for(int i=0;i<4;i++){
      for(int k=0;k<4;k++){
         v2[i]+=A(k,i)*v1[k];
         
               }
      pr+=v2[i]*v2[i];}
   bet=pow(pr,0.5);
   for (int h=0;h<4;h++){
      v2[h]=v2[h]/bet;
      
      if (v2[h]<1e-10) {v2[h]=0;};
   }

return v2;

}




int main()  {

vector<double>v1={1,1,1,1};
Matrix<double,4,4>A;
A<<1,0,0,0,0,0.8,0,0,0,0,0.8,0,0,0,0,0.8;

vector<double>v2={0,0,0,0};
cout<<"Input-Vektor (transponiert): "<<v1[0]<<"  "<<v1[1]<<"  "<<v1[2]<<"  "<<v1[3]<<endl;
cout<<A<<endl;

for (int h=0; h<1000; h++){
   v2=multnorm(A,v1);
   v1=v2;
   if (v2[0]==0||v2[1]==0||v2[2]==0||v2[3]==0) {break;};     //aBBRUCHBEDINGUNG
   }



cout<<"Output-Vektor (transponiert): "<<v2[0]<<"  "<<v2[1]<<"  "<<v2[2]<<"  "<<v2[3]<<endl;


return 0;
}
