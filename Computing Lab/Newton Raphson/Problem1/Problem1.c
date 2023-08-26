#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
double x0, x1, error;
int iteration;
FILE *Datawrite;

void cuberoot()
{
    iteration = 0;
    fprintf(Datawrite,"The initial guess for NR method (x0) = %lf\n",x0);
    printf("\nIteration (n)\tX_n+1 (NR method)\tError\n\n");
    fprintf(Datawrite, "\nIteration(n)\tX_n+1 (NR method)\tError\n\n");
    do
    {
        x1 = (((2 * pow(x0, 3)) + 11) / (3 * pow(x0, 2)));
        error = fabs(x0 - x1);
        x0 = x1;
        printf("%d\t\t%lf\t\t%lf\n", iteration, x1, error);
        fprintf(Datawrite, "%d\t\t\t\t%lf\t\t\t%lf\n", iteration, x1, error);
        iteration++;
    } while (error > 1e-5);
    printf("\nThe cube root of 11 is %lf\n",x1);
    fprintf(Datawrite,"\nThe cube root of 11 is %lf\n",x1);

}

int main()
{
    Datawrite = fopen("Output_Problem_1.txt", "w");


    printf("Enter the initial guess for NR method (x0): ");
    scanf("%lf", &x0);
    cuberoot();
    printf("\nResults have been written in the output file 'Output_Problem_1.txt'");
    fclose(Datawrite);
    return 0;
}
