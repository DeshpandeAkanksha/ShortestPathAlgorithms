
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>


int n=0;

void optsearchtree(int r, float p[])
{ 
int i, j, k, diagonal;
float A[n+1][n];
int R[n+1][n];

int d;
for (int r = 1; r <= n+1; r++)
    {
        for (int c = 0; c <=n; c++)
        {
            printf(" %0.1f ", A[r][c]);
           
        }
        printf("\n");
    }
for (i = 1; i <= n; i++) //initialization
{ 
 A[i][i-1] = 0;
 R[i][i-1] = 0;
 A[i][i] = p[i];
 R[i][i] = i;
}


A[n+1][n] = 0;
R[n+1][n] = 0;
for (int r = 1; r <= n+1; r++)
    {
        for (int c = 0; c <=n; c++)
        {
            printf(" %0.1f ", A[r][c]);
           
        }
        printf("\n");
    }

printf("*************************************************");
for (diagonal = 1; diagonal <= n-1; diagonal++)

{
	for (i = 1; i <= n - diagonal; i++)
	{
                  float min1=0;
                      float sum=0;
                       
                        
			j = i + diagonal;
                       
                        for(k=i;k<=j;k++)
                        {
                        float min=0;
                        //printf("A[i][k-1]:%f\n",A[i][k-1]);
                       // printf("A[k+1][j]:%f\n",A[k+1][j]);
                         min=A[i][k-1]+A[k+1][j];
                         

                         if(min<min1)
                             {
                               A[i][j]=min;
                               R[i][j]=k;
                              
                               
                             }
if(min==min1)
{
R[i][j]=k-1;
}

                            min1=min;

                         }
                      
  for(int m=i;m<=j;m++)
  {
  sum=sum+p[m];

  }
//printf("sum:%f",sum);
  float e=A[i][j];
  e=e+sum; 
A[i][j]=e;
printf("A[i][j]:%f\n",A[i][j]);
//printf("e:%f\n",e);           
// R[i][j]=d;	               
	
}

}
for (int r = 1; r <= n+1; r++)
    {
        for (int c = 0; c <=n; c++)
        {
            printf(" %0.1f ", A[r][c]);
           
        }
        printf("\n");
    }

}



int main(int argc,char ** argv) {

if(argc<1){
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name\n");
return 0;
        }



n=atoi(argv[1]);

float array[n];

int j=1;

for(int i=2;i<=n+1;i++)
{  
  
   float c;

c=atof(argv[i]);
array[j]=c;
j++;
}
printf("n=%d\n",n);

optsearchtree(n,array);
return 0;
}
           
       


