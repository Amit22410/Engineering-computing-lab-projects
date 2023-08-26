#include<stdio.h>
#include<math.h>
double f1(double x)
{
    return exp(x)-8*x*sin(1-x);
}
double f2(double x, double y)
{
    return (x+y-1);
}

double f3(double z)
{
    return pow((z-1),3);
}
double df1(double x)
{
    return exp(x)-8*sin(1-x)+8*x*cos(1-x);
}
double df2(double y)
{
    return (1);
}
double df3(double z)
{
    return 3*pow((z-1),2);
}
int main()
{
    int Iteration=1;
    FILE *fptr;
    fptr=fopen("output_problem_4.txt","w");
    double x0, y0, z0, x, y, z, Error_x=0.0, Error_y=0.0, Error_z=0.0, Error=0.0;
    x0=0.1, y0=0.5, z0=0.5;
    printf("Iteration\t x1\t\t x2\t\t x3\t\t Error\n");
    fprintf(fptr,"Iteration\t x1\t\t x2\t\t x3\t\t Error\n");
    do
    {
        x=x0-(f1(x0)/df1(x0));
        y=y0-(f2(x0,y0)/df2(y0));
        z=z0-(f3(z0)/df3(z0));
        Error_x=fabs(x-x0);
        Error_y=fabs(y-y0);
        Error_z=fabs(z-z0);
        Error=Error_x+Error_y+Error_z;
        x0=x;
        y0=y;
        z0=z;
        printf("%d\t\t %0.5lf\t %0.5lf\t %0.5lf\t %0.10lf\n",Iteration, x, y, z, Error);
        fprintf(fptr,"%d\t\t %0.5lf\t %0.5lf\t %0.5lf\t %0.10lf\n",Iteration, x, y, z, Error);
        Iteration++;
    }
    while(Error>1e-10);
    printf("The values of x1=%0.5lf, x2=%0.5lf, x3=%0.5lf\n",x,y,z);
    fprintf(fptr,"The values of x1=%0.5lf, x2=%0.5lf, x3=%0.5lf\n",x,y,z);
    fclose(fptr);

    return 0;
}
