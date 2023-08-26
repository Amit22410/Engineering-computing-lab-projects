#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, d;
    float A[3][4];
    float X[3], sum, ratio;
    FILE *p;

    p = fopen("input_2.txt", "r");
    printf("System of linear equations in matrix form :\n");
    for (i=0;i<3;i++)
    {
        for (j=0;j<4;j++)
        {
            fscanf(p, "%f\t", &A[i][j]);
            printf("%f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    fclose(p);

    FILE *q;
    for (i=0;i<3;i++)
    {
        if(A[i][i]==0)
        {
            for (j=i+1;j<3;j++)
            {
                if(A[j][i]!=0)
                {
                    for(k=0;k<4;k++)
                    {
                        d = A[i][k];
                        A[i][k] = A[j][k];
                        A[j][k] = d;
                    }
                    break;
                }
                else if(j==3)
                {
                    printf("Singular matrix\n");
                }
            }
        }
        if (A[i][i]!=0)
        {
            for (j=i+1;j<3;j++)
            {

                    ratio = A[j][i] / A[i][i];
                    for (k = 0; k < 4; k++)
                    {
                        A[j][k] = A[j][k] - ratio* A[i][k];
                    }

            }
        }
    }


    A[2][3]=-10.500;
    q = fopen("output_2.txt", "w");

    if (A[2][2] == 0 && A[2][3] != 0)
    {
        printf("The system has no solution\n");
    }
    else if (A[2][2] == 0 && A[2][3] == 0)
    {
        printf("The system has multiple solution\n");
    }
    else
    {
        printf("The system has unique solution\n");
        X[2] = A[2][3] / A[2][2];
        for (i = 1; i >= 0; i--)
        {
            sum = 0.0;
            for (j = i + 1; j < 3; j++)
            {
                sum = sum + (A[i][j] * X[j]);
            }
            X[i] = (A[i][3] - sum) / A[i][i];
        }


        fprintf(q,"The solution of given system of linear equations :\n");
        for (i = 0; i < 3; i++)
        {
            fprintf(q,"X[%d]=%f\t\n",i+1,X[i]);
        }
    }
    printf("\n\n");
    fprintf(q,"Final Augmented matrix after forward elimination :\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            fprintf(q, "%f\t", A[i][j]);
        }
           fprintf(q,"\n");
    }
           fclose(q);

    return 0;
}
