// Programm: primzahlmaschin.cpp
// von Marcel & Emanuel (Gruppe08)
// findet primzahlen 
// kompiliere mit: g++ -Wall -o primzahlmaschin -std=c++11 primzahlmaschin.cpp 


#include <iostream> 
#include <vector> 
using namespace std;  

int main()
{

int i=2 , n, N;

cout<<"Alle Primzahlen bis <= ";
cin>>N;

vector<int>f(N+1,true);
vector<int>A;



while(i<=N+1 ){
  if (f[i]==true){
   n=2;
   A.push_back(i);
   cout<<i<<" ";
       while (n*i<N+1){
       f[n*i]=false;
       n++;}
   i++;}
  else{
   i++;}}
cout<<endl;   
   
int l=A.size(),r;
r=l%5;
cout<<"Divisions-Rest="<<r<<" Anzahl der Primzahlen ="<<l<<endl;
int a=0, b=l/5, c=2*(l/5), d=3*(l/5), e=4*(l/5);
int k=0;
int q;
  if (r>0){
    q=1;
    b=(l+5-r)/5, c=2*((l+5-r)/5), d=3*((l+5-r)/5), e=4*((l+5-r)/5);}
  else{
    q=0;}

while(k<(l)/5+q){
cout<<endl<< A[a+k]<<" "<<A[b+k]<<" "<<A[c+k]<<" "<<A[d+k]<<" "<<A[e+k]<<endl;
k++;}


return 0;
}





