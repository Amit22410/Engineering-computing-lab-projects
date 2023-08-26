#include <stdio.h>
#include<conio.h>
#include<math.h>

float f(double x, double y, double z)
{
    return (2*y/(x))-x*z;
}
float g(double x, double y, double z)
{
    return (z+y)/(x);
}
float p(double x)
{
    return x*x*cos(x);
}
float q(double x)
{
    return x*sin(x);
}
int main()
{
    double  x[100],y[100],z[100];
    double L,N,k1,k2,k3,k4,l1,l2,l3,l4,esumy,esumz,h,YA[50],ZA[50];
    double pi=3.14;
    int i;
    x[1]=pi/2;
    y[1]=0;
    z[1]=pi/2;
    h=pi/10;
    esumy=0;
    esumz=0;

    for(i=1; i<6; i++)
    {
        x[i+1]=x[i]+h;
        YA[i]=p(x[i]);
        ZA[i]=q(x[i]);
    }

    for(i=1; i<6; i++)
    {
        k1=h*f(x[i],y[i],z[i]);
        l1=h*g(x[i],y[i],z[i]);
        k2=h*f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
        l2=h*g(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
        k3=h*f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
        l3=h*g(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
        k4=h*f(x[i]+h,y[i]+k3,z[i]+l3);
        l4=h*g(x[i]+h,y[i]+k3,z[i]+l3);
        y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
        z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;

        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;
    }
    printf("when N=5 solutions are :\n");
    printf(" Y(An)\t\t  Y\t\t Z(An)\t\t Z\n");
    for(int i=1; i<6; i++)
    {
        printf(" %.2lf \t\t %.2lf\t\t %.2lf \t\t %.2lf\n",YA[i],y[i],ZA[i],z[i]);
    }

    h=pi/20;
    for(i=1; i<11; i++)
    {
        x[i+1]=x[i]+h;
        YA[i]=p(x[i]);
        ZA[i]=q(x[i]);
    }

    for(i=1; i<11; i++)
    {
        k1=h*f(x[i],y[i],z[i]);
        l1=h*g(x[i],y[i],z[i]);
        k2=h*f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
        l2=h*g(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
        k3=h*f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
        l3=h*g(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
        k4=h*f(x[i]+h,y[i]+k3,z[i]+l3);
        l4=h*g(x[i]+h,y[i]+k3,z[i]+l3);
        y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
        z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;

        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;
    }
    printf("=======================================================\n");
    printf("when N=10 solutions are:\n");
    printf(" Y(An)\t\t  Y\t\t Z(An)\t\t Z\n");
    for(int i=1; i<11; i++)
    {
        printf(" %.2lf \t\t %.2lf\t\t %.2lf \t\t %.2lf\n",YA[i],y[i],ZA[i],z[i]);
    }

    h=pi/40;
    for(i=1; i<21; i++)
    {
        x[i+1]=x[i]+h;
        YA[i]=p(x[i]);
        ZA[i]=q(x[i]);
    }

    for(i=1; i<21; i++)
    {
        k1=h*f(x[i],y[i],z[i]);
        l1=h*g(x[i],y[i],z[i]);
        k2=h*f(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
        l2=h*g(x[i]+0.5*h,y[i]+0.5*k1,z[i]+0.5*l1);
        k3=h*f(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
        l3=h*g(x[i]+0.5*h,y[i]+0.5*k2,z[i]+0.5*l2);
        k4=h*f(x[i]+h,y[i]+k3,z[i]+l3);
        l4=h*g(x[i]+h,y[i]+k3,z[i]+l3);
        y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
        z[i+1]=z[i]+(l1+2*l2+2*l3+l4)/6;

        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;
    }
    printf("=======================================================\n");
    printf("when N=20 solutions are :\n");
    printf(" Y(An)\t\t  Y\t\t Z(An)\t\t Z\n");
    for(int i=1; i<21; i++)
    {
        printf(" %.2lf \t\t %.2lf\t\t %.2lf \t\t %.2lf\n",YA[i],y[i],ZA[i],z[i]);
    }
    return 0;
}


