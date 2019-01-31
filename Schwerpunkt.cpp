// Programm: Schwerpunkt.cpp
// von Emanuel (Gruppe08)
// 
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o Schwerpunkt Schwerpunkt.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;  



class messung {

   private:
      string S;
      pair<double,double>einschlag;
      vector<pair<double,double>>liste;
      vector<double>winkel_liste;
      double x,y,w;
      double summe_x=0.,summe_y=0.;
      double xs,ys;
      unsigned int i=0,a,ivg,cnt,k=0;
      pair<double,double>schwerpunkt;
   
   public:
      messung(string S): S(S){};     //Konstruktor
       messung(){}; // default konstruktor
      ~messung() {}; /////destruktor
      
      double einlesen(){
         ifstream lese(S);
         while (lese>>x>>y){
            
            einschlag.first=x;
            einschlag.second=y;
            liste.push_back(einschlag);
            i++;
            summe_x+=x;
            summe_y+=y;
         }  
                    
      return 0;}
      
      
      void print(){
         for(auto it = liste.begin(); it != liste.end(); ++it) {
         cout <<"x = "<<it->first << "        y = "<<it->second<< endl;  
      }}
      
      void centerofmass(){
      
         
         for(auto it = liste.begin(); it != liste.end(); ++it) {
         summe_x+=it->first;
         summe_y+=it->second;
         i++;
         }  
         schwerpunkt.first=summe_x/i;
         xs=schwerpunkt.first;
         schwerpunkt.second=summe_y/i; 
         ys=schwerpunkt.second;
         cout<<"Schwerpunkt der Einschläge:"<<endl<<endl;
         cout<<"x = "<<xs<<"   y = "<<ys<<endl;
         
      }
      
      void angle(){
      
         ofstream schreibe("Ausgabe.dat");
         
         for(auto it = liste.begin(); it != liste.end(); ++it) {
         
         w=atan2((it->second-ys),(it->first-xs))/(2*M_PI)*360;  //auf gradmaß umrechnen 
            if (w<0){winkel_liste.push_back(360+w);}         //negative winkel eliminieren
            else {winkel_liste.push_back(w);}
         
         }
         
         sort(winkel_liste.begin(),winkel_liste.end()); //Winkel nach Größe sortieren
         
         /*int a = winkel_liste.size();
            for(int j=0; j<a; j++){
            cout<<winkel_liste[j]<<"  ";
            }*/  
           
         for (ivg=20; ivg<361; ivg+=20){
            cnt=0;
            while (winkel_liste[k]<ivg){cnt++;k++; if (k==winkel_liste.size()) break;}
            cout<<ivg-10<<"   "<<cnt<<endl;
            schreibe<<ivg-10<<"   "<<cnt<<endl;
         
         }
        
           
      }

};




int main(){

   messung m("verteil.dat");
   m.einlesen();
   m.centerofmass();
   cout<<endl<<endl;
   m.angle();
   
   return 0;}
