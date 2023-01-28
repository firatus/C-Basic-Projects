/*
* @file Fırat Erdem Doğan-2021221041-Proje2
* @description Iris.csv dosyasından alınan veriler kullanılarak, çeşitli lineer cebir işlemlerinin gerçekleştirilmesi amaçlanmıştır.
* @assignment 2.Proje
* @date 20/12.2022
* @author yazar adı ve mail adresi
*/


float *returnVector(int size);
float **returnMatrix(int row, int col);
void freeMatrix(float **mat, int row);
float mean(float *vec, int size);
float correlation(float *vec, float *vec2, int size);
float covariance(float *vec1, float *vec2, int size);
float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2);
float **matrixTranspose(float **mat, int row, int col);
float *rowMeans(float **mat, int row, int col); 
float *columnMeans(float **mat, int row, int col);
float **covarianceMatrix(float **mat, int row, int col);
float determinant(float **mat, int row);
void printVector(float *vec, int N);
void printMatrix(float **mat, int row, int col);
float *flipVector(float *vec, int N, int seed);
float **flipMatrix(float **mat, int row, int col, int seed);
float variance(float *vec, int N);