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
    double L,h,k1,k2,k3,k4,esum,YA[50],YE[50],YM[50],YRK2[50],YRK4[50],esumE,esumM,esumRK2,esumRK4,eE2,eM2,eRK2,eRK4;
    int i;
    y[1]=4;
    x[1]=1;
    h=1;
    for(i=1; i<=3; i++)
    {
        x[i+1]=x[i]+h;
        y[i]=g(x[i]);
        YA[i]=y[i];

    }

    for(i=1; i<=3; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
        YE[i]=y[i];
        esumE=esumE+pow((YE[i+1]-g(x[i]+h)),2);
    }

    eE2=(pow(esumE,0.5))/2;

    for(i=1; i<=3; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];
        esumM=esumM+pow((YM[i+1]-g(x[i]+h)),2);

    }
    eM2=(pow(esumM,0.5))/2;

    for(i=1; i<=3; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
        esumRK2=esumRK2+pow((YRK2[i+1]-g(x[i]+h)),2);
    }
    eRK2=(pow(esumRK2,0.5))/2;

    for(i=1; i<=3; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
        esumRK4=esumRK4+pow((YRK4[i+1]-g(x[i]+h)),2);
    }
    eRK4=(pow(esumRK4,0.5))/2;
    printf("**** caculation of error ****\n");
    printf("N\t Euler\t\t\t MP\t\t\t RK2\t\t\t RK4\n");
    {
        printf("2\t  %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",eE2,eM2,eRK2,eRK4);
    }

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
        esumE=esumE+pow((YE[i+1]-g(x[i]+h)),2);
    }

    eE2=(pow(esumE,0.5))/5;

    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];
        esumM=esumM+pow((YM[i+1]-g(x[i]+h)),2);

    }
    eM2=(pow(esumM,0.5))/5;

    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
        esumRK2=esumRK2+pow((YRK2[i+1]-g(x[i]+h)),2);
    }
    eRK2=(pow(esumRK2,0.5))/5;

    for(i=1; i<=6; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
        esumRK4=esumRK4+pow((YRK4[i+1]-g(x[i]+h)),2);
    }
    eRK4=(pow(esumRK4,0.5))/5;

    {
        printf("5\t  %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",eE2,eM2,eRK2,eRK4);
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
        esumE=esumE+pow((YE[i+1]-g(x[i]+h)),2);
    }

    eE2=(pow(esumE,0.5))/10;

    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];
        esumM=esumM+pow((YM[i+1]-g(x[i]+h)),2);

    }
    eM2=(pow(esumM,0.5))/10;

    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
        esumRK2=esumRK2+pow((YRK2[i+1]-g(x[i]+h)),2);
    }
    eRK2=(pow(esumRK2,0.5))/10;

    for(i=1; i<=11; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
        esumRK4=esumRK4+pow((YRK4[i+1]-g(x[i]+h)),2);
    }
    eRK4=(pow(esumRK4,0.5))/10;

    {
        printf("10\t  %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",eE2,eM2,eRK2,eRK4);
    }




    h=0.3333333;
    for(i=1; i<=16; i++)
    {
        x[i+1]=x[i]+h;
        y[i]=g(x[i]);
        YA[i]=y[i];

    }

    for(i=1; i<=16; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
        YE[i]=y[i];
        esumE=esumE+pow((YE[i+1]-g(x[i]+h)),2);
    }

    eE2=(pow(esumE,0.5))/15;

    for(i=1; i<=16; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];
        esumM=esumM+pow((YM[i+1]-g(x[i]+h)),2);

    }
    eM2=(pow(esumM,0.5))/15;

    for(i=1; i<=16; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
        esumRK2=esumRK2+pow((YRK2[i+1]-g(x[i]+h)),2);
    }
    eRK2=(pow(esumRK2,0.5))/15;

    for(i=1; i<=16; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
        esumRK4=esumRK4+pow((YRK4[i+1]-g(x[i]+h)),2);
    }
    eRK4=(pow(esumRK4,0.5))/15;

    {
        printf("15\t  %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",eE2,eM2,eRK2,eRK4);
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
        esumE=esumE+pow((YE[i+1]-g(x[i]+h)),2);
    }

    eE2=(pow(esumE,0.5))/20;

    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];
        esumM=esumM+pow((YM[i+1]-g(x[i]+h)),2);

    }
    eM2=(pow(esumM,0.5))/20;

    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
        esumRK2=esumRK2+pow((YRK2[i+1]-g(x[i]+h)),2);
    }
    eRK2=(pow(esumRK2,0.5))/20;

    for(i=1; i<=21; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
        esumRK4=esumRK4+pow((YRK4[i+1]-g(x[i]+h)),2);
    }
    eRK4=(pow(esumRK4,0.5))/20;

    {
        printf("20\t  %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",eE2,eM2,eRK2,eRK4);
    }



    h=0.2;
    for(i=1; i<=26; i++)
    {
        x[i+1]=x[i]+h;
        y[i]=g(x[i]);
        YA[i]=y[i];

    }

    for(i=1; i<=26; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
        YE[i]=y[i];
        esumE=esumE+pow((YE[i+1]-g(x[i]+h)),2);
    }

    eE2=(pow(esumE,0.5))/25;

    for(i=1; i<=26; i++)
    {
        x[i+1]=x[i]+h;
        y[i+1]=y[i-1]+2*h*f(x[i],y[i]);
        y[0]=4;
        YM[i]=y[i];
        esumM=esumM+pow((YM[i+1]-g(x[i]+h)),2);

    }
    eM2=(pow(esumM,0.5))/25;

    for(i=1; i<=26; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f((x[i]),(y[i]));
        k2=h*f((x[i+1]),(y[i]+k1));
        y[i+1]=((y[i]+(0.5*(k1+k2))));
        YRK2[i]=y[i];
        esumRK2=esumRK2+pow((YRK2[i+1]-g(x[i]+h)),2);
    }
    eRK2=(pow(esumRK2,0.5))/25;

    for(i=1; i<=26; i++)
    {
        x[i+1]=x[i]+h;
        k1=h*f(x[i],y[i]);
        k2=h*f((x[i]+(h/2)),(y[i]+(k1/2)));
        k3=h*f((x[i]+(h/2)),(y[i]+(k2/2)));
        k4=h*f(x[i+1],(y[i]+k3));
        y[i+1]=((y[i]+(0.1666*(k1+(2*k2)+(2*k3)+k4))));
        YRK4[i]=y[i];
        esumRK4=esumRK4+pow((YRK4[i+1]-g(x[i]+h)),2);
    }
    eRK4=(pow(esumRK4,0.5))/25;


    {
        printf("25\t   %.lf\t\t   %.lf\t\t   %.lf\t\t   %.lf\n",eE2,eM2,eRK2,eRK4);
    }


    return 0 ;
}
