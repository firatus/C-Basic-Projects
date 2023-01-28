/*
 * @file Fırat Erdem Doğan - 2021221041 - Proje1
 * @description Matris ve vektörlerin çeşitli işlemlerini gerçekleştiren fonksiyonların yer aldığı kütüphane oluşturuldu.
 * @assignment 1.Proje
 * @date 02/11/2022
 * @author Fırat Erdem Doğan - firaterdem.dogan@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h"

int main(int argc, char *argv[])
{
    
    int seed = atoi(argv[1]);
    if (argc == 2)
    {
        float **matrix = returnMatrix(3, 3);
        
        float *vector = returnVector(5);

        matrix = flipMatrix(matrix, 3, 3, seed);

        vector = flipVector(vector, 5, seed);

        float mean_vector = mean(vector,5);

        printf("\nDynamic Matrix\n------------------------------------------\n");
        printMatrix(matrix, 3, 3);
        

        printf("\nDynamic Vector\n------------------------------------------\n");
        printVector(vector, 5);
        

        printf("\nVector Mean\n------------------------------------------\n");
        printf("%f\n",mean_vector);
        
      
        printf("\nCorrelation Vectors\n------------------------------------------\n");
        float *vector2 = returnVector(5);
        vector2 = flipVector(vector2, 5, seed);
        float result_correlation = correlation(vector,vector2,5);
        printf("%f\n",result_correlation);
        

        printf("\nCovariance Vectors\n------------------------------------------\n");
        float result_covariance = covariance(vector,vector2,5);
        printf("%f\n",result_covariance);
        free(vector2);

        printf("\nMatrix Multiplication\n------------------------------------------\n");
        float **matrix2 = returnMatrix(3, 3);
        matrix2 = flipMatrix(matrix2, 3, 3, seed);
        float **matrix_multiplication = matrixMultiplication(matrix,matrix2,3,3,3,3);
        printMatrix(matrix_multiplication, 3, 3);
        free(matrix2);
        free(matrix_multiplication);


        printf("\nTranspose Of Matrix \n------------------------------------------\n");
        float **matrix_transpose = matrixTranspose(matrix,3,3);
        printMatrix(matrix_transpose,3,3);
        free(matrix_transpose);

        printf("\nMatrix Row Means\n------------------------------------------\n");
        float *result_row_means = rowMeans(matrix,3,3);
        printVector(result_row_means,3);
        free(result_row_means);
        printf("\n");

        printf("\nMatrix Column Means\n------------------------------------------\n");
        float *result_col_means = columnMeans(matrix,3,3);
        printVector(result_col_means,3);
        free(result_col_means);
        printf("\n");

        printf("\nCovariance Of Matrix\n------------------------------------------\n");
        float **result_covariance_matrix = covarianceMatrix(matrix,3,3);
        printMatrix(result_covariance_matrix,3,3);
        free(result_covariance_matrix);


        printf("\nDeterminant Of Matrix\n------------------------------------------\n");
        float result_determinant = determinant(matrix,3);
        printf("%f\n",result_determinant);

        free(matrix);
        free(vector);


    }
    else
    {

        printf("Invalid Format\n");
        printf("Valid Format: make seed_value OR ./program.exe seed_value");
    }

    return 0;
}