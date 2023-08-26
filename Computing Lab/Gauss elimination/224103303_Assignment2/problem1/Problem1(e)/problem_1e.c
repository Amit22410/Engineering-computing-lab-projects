#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k;
    double A[5][6];
    double sum , x[3],ratio;
    FILE *p;
    p = fopen("1_e_input.txt","r");
    for(i =1;i<5;i++)
    {
        for(j=1;j<6;j++)
        {
            fscanf(p,"%lf",&A[i][j]);
            printf("%lf\t",A[i][j]);
        }
            printf("\n");
    }
    fclose(p);
  for(i=1;i<5;i++)
 {
 for(j=1;j<6;j++)

 if(i>j)
 {
  ratio = A[i][j]/A[j][j];
     for(k=1;k<6;k++)
     {
     A[i][k]=A[i][k]-ratio*A[j][k];
      }
         }
            }
 FILE *q;
 q = fopen("1_e_Output.txt", "w");
if(A[4][4] == 0.0 && A[4][5]!= 0.0)
{
printf("The system has no solution\n");
}
else if(A[4][4] == 0.0 && A[4][5] == 0.0)
{
printf("The system has multiple solution\n");
}
else if(A[4][4]!= 0.0)
{
printf("The system has unique solution\n");

    x[4]=(A[4][5])/(A[4][4]);
    for(i=3;i>=1;i--)
{
    sum =0;
    for(j=i+1;j<5;j++)
    {
    sum = sum + (A[i][j])*x[j];
    }
    x[i]=( A[i][5] - sum )/A[i][i];
}

    fprintf(q,"The solution of given system of linear equations:\n");
        for (i = 1; i < 5; i++)
        {
            fprintf(q,"x[%d]=%lf\t\n",i,x[i]);
        }
    }

    printf("\n\n");
    fprintf(q,"Final Augmented matrix after forward elimination :\n");
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 6; j++)
        {
            fprintf(q, "%f\t", A[i][j]);
        }
           fprintf(q,"\n");
    }
    fclose(q);
    return 0;
    }
