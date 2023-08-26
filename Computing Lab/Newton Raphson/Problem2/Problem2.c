#include <stdio.h>
#include <math.h>
double x0, x1, Error, N;
int itr;
FILE *fp;

void
pie ()
{
  itr = 0;
  fprintf (fp, " Initial value  for NR method = %lf\n", x0);
  printf ("\nIteration (n)\tNR Value \tError\n\n");
  fprintf (fp, "\nIteration(n)\tNR Value\tError\n\n");
  do
    {
      x1 = x0 - 2*((sin(x0/2)-1)/cos(x0/2));
      Error = fabs (x0 - x1);
      x0 = x1;
      printf ("%d\t\t%lf\t%lf\n", itr, x1, Error);
      fprintf (fp, "%d\t\t\t\t%lf\t\t%lf\n", itr, x1, Error);
      itr++;
    }
  while (Error > 0.00001);
  printf ("\nThe value of Pie  = %lf\n",  x1);
  fprintf (fp, "\nAfter all Itr final result for Pie = %lf",  x1);
}

int
main ()
{
  fp = fopen ("Output_Problem_2.txt", "w");

  printf ("Initial value for NR method: ");
  scanf ("%lf", &x0);
  pie ();
  printf("\nResults has been written in the output file 'Output_Problem_2.txt'");

  fclose (fp);
  return 0;
}
