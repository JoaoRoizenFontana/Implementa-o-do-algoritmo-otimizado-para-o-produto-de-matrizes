/*
Joao Roizen Fontana - 1710431
Pedro Arduini - 2110132
*/

#include <stdio.h>
#include <stdlib.h>

int scalar_matrix_mult(float scalar_value, struct matrix *matrix){
	int i;
	unsigned long itens;
	float *aux;

	if(matrix == NULL){
		return 0;
	}
	
	itens = matrix->height * matrix->width;
	
	aux = matrix->rows;
	for(i=0;i<itens;i++){
	
		*aux *= scalar_value;
		
		aux ++; 
	}
	
	return 1;
}


int matrix_matrix_mult(struct matrix *matrixA, struct matrix *matrixB, struct matrix *matrixC){
	int i,j,k;
	float *auxA;
	float *auxB;
	float *auxC;	

	if(matrixA == NULL || matrixB == NULL || matrixC == NULL || matrixA->width != matrixB->height){
		return 0;
	}

	auxA = matrixA->rows;
	auxB = matrixB->rows;
	auxC = matrixC->rows;
	


	for(i=0;i<matrixA->height;i++){
		for(j=0;j<matrixA->width;j++){		
				for(k=0;k<matrixB->width;k++){
					auxC[i*matrixB->width+k] += auxA[(i*matrixA->width)+j] * auxB[j*matrixB->width + k];	
					
				}


			
		}


	}


	return 1;
}



