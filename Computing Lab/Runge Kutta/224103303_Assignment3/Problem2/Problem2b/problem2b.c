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
    double L,N,k1,k2,k3,k4,l1,l2,l3,l4,esumy,esumz,h,YA[50],ZA[50],eyl2,ezl2;
    double pi=3.14;
    int i;
    x[1]=pi/2;
    y[1]=0;
    z[1]=pi/2;
    h=pi/4;
    esumy=0;
    esumz=0;

    for(i=1; i<3; i++)
    {
        x[i+1]=x[i]+h;
        YA[i]=p(x[i]);
        ZA[i]=q(x[i]);
    }

    for(i=1; i<3; i++)
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
        esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
        esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;


    }
    printf("**** caculation of error ****\n");
    eyl2=(pow(esumy,0.5))/2;
    ezl2=(pow(esumz,0.5))/2;
    printf("N\t eyl2\t\t ezl2\n");
    printf("2\t %lf\t %lf\n",eyl2,ezl2);


    h=pi/10;
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
        esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
        esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;
    }
    eyl2=(pow(esumy,0.5))/2;
    ezl2=(pow(esumz,0.5))/2;
    printf("5\t%lf\t %lf\n",eyl2,ezl2);


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
        esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
        esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;


    }
    eyl2=(pow(esumy,0.5))/2;
    ezl2=(pow(esumz,0.5))/2;
    printf("10\t%lf\t %lf\n",eyl2,ezl2);

    h=pi/30;
    for(i=1; i<16; i++)
    {
        x[i+1]=x[i]+h;
        YA[i]=p(x[i]);
        ZA[i]=q(x[i]);
    }

    for(i=1; i<16; i++)
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
        esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
        esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;


    }
    eyl2=(pow(esumy,0.5))/2;
    ezl2=(pow(esumz,0.5))/2;
    printf("15\t%lf\t %lf\n",eyl2,ezl2);


    h=pi/40;
    for(i=1; i<26; i++)
    {
        x[i+1]=x[i]+h;
        YA[i]=p(x[i]);
        ZA[i]=q(x[i]);
    }

    for(i=1; i<26; i++)
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
        esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
        esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;


    }
    eyl2=(pow(esumy,0.5))/2;
    ezl2=(pow(esumz,0.5))/2;
    printf("20\t%lf\t %lf\n",eyl2,ezl2);


    h=pi/50;
    for(i=1; i<26; i++)
    {
        x[i+1]=x[i]+h;
        YA[i]=p(x[i]);
        ZA[i]=q(x[i]);
    }

    for(i=1; i<26; i++)
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
        esumy=esumy+pow((y[i+1]-p(x[i]+h)),2);
        esumz=esumz+pow((z[i+1]-q(x[i]+h)),2);
        x[i]=x[i]+h;
        y[i]=y[i]+h;
        z[i]=z[i]+h;


    }
    eyl2=(pow(esumy,0.5))/2;
    ezl2=(pow(esumz,0.5))/2;
    printf("25\t%lf\t %lf\n",eyl2,ezl2);

    return 0;
}
