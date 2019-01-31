// Programm: hamilton.cpp
// von Marcel & Emanuel (Gruppe08)
// 
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o hamilton hamilton.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <map>
#include <eigen3/Eigen/Dense>
using namespace std;  
using namespace Eigen;


int main() {


double a;
int k=0;
vector<double>v_lese;
//Matrix<double,Dynamic,Dynamic>H;

ifstream lese("11_hamiltonian.dat");

while (lese>>a){
v_lese.push_back(a);
k++;}

int l = pow(k,0.5);
Map<MatrixXd> H(v_lese.data(), l, l);

//cout<<H<<endl;

Matrix<double, Dynamic, 1> v1(l);
//Vector<double>v1(16);


for (int i=0;i<l;i++) {
   v1(i,0)=1;
   
   }
v1=v1/v1.norm();


Matrix<double,Dynamic,Dynamic>I=MatrixXd::Identity(l,l); //Einheitsmatrix

/*for(int i=0;i<16;i++){
      for(int k=0;k<16;k++){
         if (k==i) {I(k,i)=1;}
         
         else {I(k,i)=0;}
         
               }}*/



double dt=0.00001;
//Vector<double>v2(16);
Matrix<double, Dynamic, 1> v2(l);
for(int i=0;i<1000000;i++){
   
   v2=H*v1;
   v2=(I-dt*H)*v1;
   if (abs(v1.norm()-v2.norm())<1e-100) {break;} //Abbruchbedingung
   v1=v2/v2.norm();
   
   
}
cout<<v2.transpose()*H*v2<<endl;





return 0;
}

