#include <stdio.h>
#include<math.h>

 float d2f(double x, double z){
     double f2;
     f2=(9*pow(x,2)+3*z-15)/x;
 return f2;
 }

 float df(double z){
     double f1;
     f1=z;
 return f1;
 }
 float p(double x){
 return pow(x,4)-3*pow(x,3)+5*x;
 }
 float q(double x){
 return 4*pow(x,3)-9*pow(x,2)+5;
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
   h=1;
   esumy=0;
   esumz=0;

    for(i=1;i<6;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<6;i++)
   {
       k1=h*d2f(x[i],z[i]);
       l1=h*df(z[i]);
       k2=h*d2f(x[i]+0.5*h,z[i]+0.5*l1);
       l2=h*df(z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,z[i]+0.5*l2);
       l3=h*df(z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,z[i]+l3);
       l4=h*df(z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;
   }
   printf("when N=5 solutions are :\n");
printf("N\t Y(Ana)\t\t  y\t\t y'(Ana)\t y'\n");
        for(int i=1;i<6;i++)
        {
            printf("%d\t %.1lf \t\t %.2lf\t\t %.1lf \t\t %.2lf\n",i,YA[i],y[i],ZA[i],z[i]);
}

     h=0.5;
    for(i=1;i<11;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<11;i++)
   {
       k1=h*d2f(x[i],z[i]);
       l1=h*df(z[i]);
       k2=h*d2f(x[i]+0.5*h,z[i]+0.5*l1);
       l2=h*df(z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,z[i]+0.5*l2);
       l3=h*df(z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,z[i]+l3);
       l4=h*df(z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;
   }
   printf("===================================================================\n");
printf("when N=10 solutions are:\n");
printf("N\t Y(Ana)\t\t  y\t\t y'(Ana)\t\t y'\n");
        for(int i=1;i<11;i++)
        {
            printf(" %d\t %.1lf \t\t %.2lf\t\t %.2lf \t\t %.2lf\n",i,YA[i],y[i],ZA[i],z[i]);
}

     h=0.25;
    for(i=1;i<21;i++){
       x[i+1]=x[i]+h;
       YA[i]=p(x[i]);
       ZA[i]=q(x[i]);
    }

   for(i=1;i<21;i++)
   {
             k1=h*d2f(x[i],z[i]);
       l1=h*df(z[i]);
       k2=h*d2f(x[i]+0.5*h,z[i]+0.5*l1);
       l2=h*df(z[i]+0.5*l1);
       k3=h*d2f(x[i]+0.5*h,z[i]+0.5*l2);
       l3=h*df(z[i]+0.5*l2);
       k4=h*d2f(x[i]+h,z[i]+l3);
       l4=h*df(z[i]+l3);
       y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
       z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;
       x[i]=x[i]+h;
       y[i]=y[i]+h;
       z[i]=z[i]+h;
   }
      printf("================================================================================\n");
printf("when N=20 solutionsare :\n");
printf(" N\tY(Ana)\t\t  y\t\t y'(Ana)\t\t y'\n");
        for(int i=1;i<21;i++)
        {
            printf(" %d\t %.2lf \t\t %.2lf\t\t %.2lf \t\t %.2lf\n",i,YA[i],y[i],ZA[i],z[i]);
}
return 0;
}

