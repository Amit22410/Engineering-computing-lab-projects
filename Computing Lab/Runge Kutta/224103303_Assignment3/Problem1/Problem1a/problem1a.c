#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(double x,double y)
{
    return ((y/x)+(4*pow(x,4)));
}
float g(double x)
{
    return (pow(x,5)+(3*x));
}
int main()
{
    int n=50,N;
    double x[n],y[n];
    double L,h,k1,k2,k3,k4,esum,YA[50],YE[50],YM[50],YRK2[50],YRK4[50];
    int i;
    L=6;
    y[1]=4;
    x[1]=1;
    h=1;
    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        y[i]=g(x[i]);
        YA[i]=y[i];


    }

    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
        YE[i]=y[i];
    }

    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];

    }
    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
    }
    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
    }
    printf("when N=5 solutions are:\n");
    printf("x   Ana\t\t  Euler\t\t MP\t\t RK2\t\t\t RK4\n");
    for(int i=1; i<7; i++)
    {
        printf("%d:   %.1f\t\t   %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",i,YA[i],YE[i],YM[i],YRK2[i],YRK4[i]);
    }

    h=0.5;
    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        y[i]=g(x[i]);
        YA[i]=y[i];

    }

    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
        YE[i]=y[i];
    }

    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];

    }
    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
    }
    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
    }
    printf("================================================================================\n");

    printf("when N=10 solutions are:\n");
    printf("x Ana\t\t   Euler\t\t   MP\t\t   RK2\t\t\t   RK4\n");
    for(int i=1; i<11; i++)
    {
        printf("%d:  %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",i,YA[i],YE[i],YM[i],YRK2[i],YRK4[i]);
    }

    h=0.25;
    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        y[i]=g(x[i]);
        YA[i]=y[i];

    }

    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
        YE[i]=y[i];
    }

    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];

    }
    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
    }
    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
    }

    printf("================================================================================\n");
    printf("when N=20 solutions are :\n");
    printf("x   Ana\t\t  Euler\t\t MP\t\t RK2\t\t\t RK4\n");
    for(int i=1; i<21; i++)
    {
        printf("%d:  %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",i,YA[i],YE[i],YM[i],YRK2[i],YRK4[i]);
    }


    return 0;
}
