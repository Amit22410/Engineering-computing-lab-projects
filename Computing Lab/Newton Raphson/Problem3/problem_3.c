#include<stdio.h>
#include<math.h>

  double fx(double x0)
  {
      return pow(x0,2)*(1+pow(sin(x0),2));
  }
  double Dfx(double x0)
  {
      return pow(x0,2)*sin(2*x0) + 2*x0*(1 + pow(sin(x0),2));
  }
  double DDfx(double x0)
  {
      2*x0*sin(2*x0) + 2*pow(x0,2)*cos(2*x0) + 2*(1+pow(sin(x0),2)) + 2*x0*sin(2*x0);
  }
  double dx(double x0)
  {
       return 2*(x0-2) + 2*fx(x0)*Dfx(x0);
  }
  double Ddx(double x0)
  {
      return 2 + 2*pow(Dfx(x0),2) + 2*fx(x0)*DDfx(x0);
  }

     int main ()
     {
          FILE *fp=fopen("output_problem_3.txt","w");
         fprintf(fp,"Iteration\tStroke Length\tError\n\n");
         printf("Iteration\tStroke length\tError\n\n");
         int iteration=0;
         double error,x1,m,d;
         double x0=0.0;
         do
         {

             error=0;
             m=dx(x0)/Ddx(x0);
             x1 = x0 - m;
             error = fabs(x0-x1);
            d=sqrt(pow((x1-2),2)+pow((fx(x1)),2));
            fprintf(fp,"%d\t\t%0.5lf\t\t%0.5lf\n",iteration,d,error);
            printf("%d\t\t%0.5lf\t\t%0.5lf\n",iteration,d,error);
             x0=x1;
             iteration++;
         }while(error>pow(10,-6));
        fprintf(fp,"The value of Stroke Length is %0.5lf\n Value of Diameter is %lf",d,2*d);
        printf(" The value of Stroke Length is %0.5lf\n Value of Diameter is %lf",d,2*d);
        return 0;
     }






