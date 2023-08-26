#include <stdio.h>
#include <math.h>

int main()
{
    float A[100][100], X[50], ratio, d;
    int i, j, k;
    FILE *p;
    p = fopen("input_3.txt", "r");
    printf("System of linear equations in matrix form :\n");
    for (i=1; i<4; i++)
    {
        for (j=1; j<5; j++)
        {
            fscanf(p, "%f\t", &A[i][j]);
            printf("%f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    fclose(p);
    for (i = 1; i <= 3; i++)
    {
        for (j = 3; j>i; j--)
        {
            if (fabs(A[j][i]) > fabs(A[i][i]))
            {
                for (k = 1; k <= 4; k++)
                {
                    d=0.00;
                    d = A[j][k];
                    A[j][k] = A[i][k];
                    A[i][k] = d;
                }
            }
        }
        for (j = i + 1; j <= 3; j++)
        {
            ratio = A[j][i] / A[i][i];
            for (k = 1; k <= 4; k++)
            {
                A[j][k] = A[j][k] - ratio * A[i][k];
            }
        }
    }

    FILE *q;
    q = fopen("output_3.txt", "w");
    printf("\n\n");
    fprintf(q,"Final Augmented matrix after forward elimination :\n");
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            fprintf(q, "%f\t", A[i][j]);
        }
        fprintf(q, "\n");
    }
    float sum;
    if (A[3][3] != 0)
    {
        X[2] = A[3][4] / A[3][3];
        for (i = 2; i >= 1; i--)
        {
            sum = A[i][4];
            for (j = i + 1; j <= 3; j++)
            {
                sum = sum - (A[i][j] * X[j]);
            }
            X[i] = sum / A[i][i];
        }
        fprintf(q, "The solution of given system of linear equations : \n");
        for (i = 1; i <= 3; i++)
        {
            fprintf(q, "x[%d]= %f\n", i, X[i]);
        }
    }
    else if (A[3][4] == 0)
    {
        fprintf(q, " System has multiple solutions \n");
    }
    else
    {
        fprintf(q, "System has no solution\n");
    }
    fclose(q);
    return 0;
}
