#include <stdio.h>
#include<math.h>
#include<stdlib.h>


 float d2f(double x, double y, double z){
     double f2;
     f2=(3*z)/(x)+9*x-15/x;
 return f2;
 }

 float df(double x, double y, double z){
     double f1;
     f1=z;
 return f1;
 }
 float p(double x){
 return x*x*x*x-3*x*x*x+5*x;
 }
 float q(double x){
 return 9*x*x+15;
 }
int main()
{
   double  x[50],y[50],z[50];
   double L,N,k1,k2,k3,k4,l1,l2,l3,l4,esumy,esumz,h,YA[50],ZA[50],eyl2,ezl2;
   double pi=3.14;
   int i;
   x[1]=1;
   y[1]=3;
   z[1]=0;
   h=2.5;
   esumy=0;
   esumz=0;

    for(i=1;i<3;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<3;i++)
   {
       k1=h*d2f(x[i],y[i],z[i]);
       l1=h*df(x[i],y[i],z[i]);
       k2=h*d2f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       l2=h*df(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       l3=h*df(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,y[i]+k3,z[i]+l3);
       l4=h*df(x[i]+h,y[i]+k3,z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
       esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;


   }
       printf("caculation of error\n");
   eyl2=(pow(esumy,0.5))/2;
   ezl2=(pow(esumz,0.5))/2;
printf("N\t eyl2\t\t ezl2\n");
printf("2\t %.2lf\t\t %.2lf\n",eyl2,ezl2);


         h=1;
    for(i=1;i<6;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<6;i++)
   {
       k1=h*d2f(x[i],y[i],z[i]);
       l1=h*df(x[i],y[i],z[i]);
       k2=h*d2f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       l2=h*df(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       l3=h*df(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,y[i]+k3,z[i]+l3);
       l4=h*df(x[i]+h,y[i]+k3,z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
       esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;
   }
   eyl2=(pow(esumy,0.5))/5;
   ezl2=(pow(esumz,0.5))/5;
printf("5\t%.2lf\t\t %.2lf\n",eyl2,ezl2);


         h=0.5;
    for(i=1;i<11;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<11;i++)
   {
      k1=h*d2f(x[i],y[i],z[i]);
       l1=h*df(x[i],y[i],z[i]);
       k2=h*d2f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       l2=h*df(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       l3=h*df(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,y[i]+k3,z[i]+l3);
       l4=h*df(x[i]+h,y[i]+k3,z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
       esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;


   }
   eyl2=(pow(esumy,0.5))/10;
   ezl2=(pow(esumz,0.5))/10;
printf("10\t%.2lf\t\t %.2lf\n",eyl2,ezl2);

         h=0.3333333;
    for(i=1;i<16;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<16;i++)
   {
      k1=h*d2f(x[i],y[i],z[i]);
       l1=h*df(x[i],y[i],z[i]);
       k2=h*d2f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       l2=h*df(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       l3=h*df(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,y[i]+k3,z[i]+l3);
       l4=h*df(x[i]+h,y[i]+k3,z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
       esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;


   }
   eyl2=(pow(esumy,0.5))/15;
   ezl2=(pow(esumz,0.5))/15;
printf("15\t%.2lf\t\t %.2lf\n",eyl2,ezl2);

    h=0.25;
    for(i=1;i<21;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<21;i++)
   {
       k1=h*d2f(x[i],y[i],z[i]);
       l1=h*df(x[i],y[i],z[i]);
       k2=h*d2f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       l2=h*df(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       l3=h*df(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,y[i]+k3,z[i]+l3);
       l4=h*df(x[i]+h,y[i]+k3,z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
       esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;


   }
   eyl2=(pow(esumy,0.5))/20;
   ezl2=(pow(esumz,0.5))/20;
printf("20\t%.2lf\t\t %.2lf\n",eyl2,ezl2);


    h=0.2;
    for(i=1;i<26;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<26;i++)
   {
      k1=h*d2f(x[i],y[i],z[i]);
       l1=h*df(x[i],y[i],z[i]);
       k2=h*d2f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       l2=h*df(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       l3=h*df(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,y[i]+k3,z[i]+l3);
       l4=h*df(x[i]+h,y[i]+k3,z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
       esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;


   }
   eyl2=(pow(esumy,0.5))/25;
   ezl2=(pow(esumz,0.5))/25;
printf("25\t%.2lf\t\t %.2lf\n",eyl2,ezl2);

return 0;
}
