// Programm: KI.cpp
// von Emanuel und Marcel (Gruppe08)
// 
// kompiliere mit: g++ -Wall -lm -O -std=c++11 -o KI KI.cpp


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

double xmin, ymin, xmax, ymax, r, amax;
double x1,y1,vx1,vy1;
double x2,y2,vx2,vy2;
double ax,ay;
double mx, my;
double dx, dy;
double xl,yl,xr,yr;

cin>>xmin>>ymin>>xmax>>ymax>>r>>amax; //Eckdaten einlesen

mx = (xmax + xmin)/2.;
my = (ymax + ymin)/2.;

while (cin>>x1>>y1>>vx1>>vy1>>x2>>y2>>vx2>>vy2) {


dx= mx-x1;
dy= my-y1;
xl= xmax-xmin;
yl = ymax-ymin;

xr= dx/xl;
yr= dy/yl;



if (dx >0.){   //links der mitte
   ax=amax/pow(1+(yr*yr/xr/xr),0.5);}
else if(dx<0.){  //rechts der mitte
   ax=amax/pow(1+(yr*yr/xr/xr),0.5)*(-1);}
else{ax=0.;}


if (dy >0.){   //unterhalb der mitte
   ay=amax/pow(1+(xr*xr/yr/yr),0.5);}
else if(dy<0.){  //oberhalb der mitte
   ay=amax/pow(1+(xr*xr/yr/yr),0.5)*(-1);}
else{ay=0.;}


cout<<ax<<" "<<ay<<endl; //Beschleunigung Ausgabe

}







}
