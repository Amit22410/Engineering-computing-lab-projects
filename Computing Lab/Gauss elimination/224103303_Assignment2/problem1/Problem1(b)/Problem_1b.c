#include<stdio.h>
#include<math.h>
int main(){
    int i,j,c,k;
    float A[5][5];
    FILE *fp;
    fp=fopen("1_b_input.txt","r");
    for(i=1;i<=3;i++){
        for(j=1;j<=4;j++){
            fscanf(fp,"%f",&A[i][j]);
        }
        fscanf(fp,"\n");
    }
    fclose(fp);
	fp=fopen("1_b_output.txt","w");
	for(i=1;i<=3;i++){
        for(j=1;j<=4;j++){
            printf("%0.2f\t",A[i][j]);
			fprintf(fp,"%0.2f\t",A[i][j]);
        }
        printf("\n");
		fprintf(fp,"\n");
    }

    for(j=4;j>=1;j--)
	{
		A[2][j]=-(A[1][j]/A[1][1])*A[2][1]+A[2][j];
		A[3][j]=-(A[1][j]/A[1][1])*A[3][1]+A[3][j];
	}
	for(j=4;j>=1;j--)
	{
		A[3][j]=-(A[2][j]/A[2][2])*A[3][2]+A[3][j];
	}
	printf("The final augmented matrix after forward elimination(upper triangular form)\n");
	fprintf(fp,"\n The augmented matrix after Gauss eliminaition:\n");

		for(i=1;i<=3;i++)
	{
		for(j=1;j<=4;j++)
		{
			printf("%0.2f\t",A[i][j]);
			fprintf(fp,"%0.2f\t",A[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	printf("\n");
	float x,y,z;
	if(A[3][3]==0&&A[3][4]!=0)
	{
		printf("The system of linear equations has No Solution.\n");
		fprintf(fp,"The system of linear equations has No Solution.\n");
	}
	if(A[3][3]==0&&A[3][4]==0)
	{
		printf("The system of linear equations has Multiple Solutions.\n");
		fprintf(fp,"The system of linear equations has Multiple Solutions.\n");
	}
	if(A[3][3]!=0&&A[3][4]!=0)
	{
		printf("The system of linear equations has Unique Solution.\n");
		fprintf(fp,"The system of linear equations has Unique Solution.\n");
		z=A[3][4]/A[3][3];
		y=(A[2][4]-z*A[2][3])/A[2][2];
		x=(A[1][4]-y*A[1][2]-z*A[1][3])/A[1][1];
		printf("The value of x is : %0.2f\nThe value of y is : %0.2f\nThe value of z is : %0.2f\n",x,y,z);
		fprintf(fp,"The value of x is :%0.2f\nThe value of y is:%0.2f\nThe value of z is:%0.2f\n",x,y,z);
		}


    return 0;
}
