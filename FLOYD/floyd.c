#include <stdio.h>
#include<math.h>
 
int n=499;
int pathVal[20][20]; 

//Floyd algorithm for finding shortest path.        
void floyd() {      
	int i, j, k;
    	for (k=0;k<n;k++) {
    		for (i=0;i<n;i++){
    			for (j=0;j<n;j++){
				//Calculating the direct and indirect path distances from one node to every other nodes.
				pathVal[i][j]=pathVal[i][j]<(pathVal[i][k]+pathVal[k][j])?pathVal[i][j]:(pathVal[i][k]+pathVal[k][j]);
			}
		}
    	}
    	
	//Displaying distance matrix.
	printf("\n");                          
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++)
			printf("%d\t", pathVal[i][j]);
		printf("\n");
	}
	printf("\n");		
}
    	
int main(int argc, char *argv[]) {
	int i, j;
	//Reading input from the CSV file.
	FILE *file = fopen("input.csv", "r");
    	fscanf(file,"%d",&n);
    	for (i=0;i<n;i++)
    		for (j=0;j<n;j++)
			//Assigning values from input file to the matrix.
    			fscanf(file,"%d,",&pathVal[i][j]);
    	fclose(file);
    	floyd();
    	return 0;
}
