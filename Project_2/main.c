/*
* @file Fırat Erdem Doğan-2021221041-Proje2
* @description Iris.csv dosyasından alınan veriler kullanılarak, çeşitli lineer cebir işlemlerinin gerçekleştirilmesi amaçlanmıştır.
* @assignment 2.Proje
* @date 20/12.2022
* @author yazar adı ve mail adresi
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h"
#include <string.h>
typedef struct
{
    float SepalLengthCm;
    float SepalWidthCm;
    float PetalLengthCm;
    float PetalWidthCm;
    float Species;

} IrishDataType;

enum IrishSpecies
{
    IrishSetosa = 1,
    IrishVersicolor = 2,
    IrishVirginica = 3
};

int main()
{

    FILE *fp = fopen("Iris.csv", "r");
    char str[1000];

    if (fp == NULL)
    {
        printf("File not found");
        return 1;
    }

    int data_length = atoi(fgets(str, 1000, fp));
    IrishDataType *iris = (IrishDataType *)malloc(sizeof(IrishDataType) * data_length);
    
    //İlk satırlar atlandı
    fgets(str, 1000, fp);
    fgets(str, 1000, fp);

    //Her satırın virgüllere göre parçalanmış hali burada tutuldu
    char *row = malloc(sizeof(char) * 1000);

    for (int i = 0; i <= data_length; i++)
    {
        
        row = strdup(str);

        (fgets(str, 1000, fp));

        char *part = strtok(row, " ,");
        part = strtok(NULL, " ,");
        int column = 0;

        //Satırın sonuna gelene kadar virgüllere göre parçalanmış değerleri struct içine at
        while (part != NULL)
        {
            
            switch (column)
            {
            case 0:
                iris[i].SepalLengthCm = atof(part);

                break;

            case 1:
                iris[i].SepalWidthCm = atof(part);
                break;

            case 2:
                iris[i].PetalLengthCm = atof(part);
                break;

            case 3:
                iris[i].PetalWidthCm = atof(part);
                break;

            case 4:

                //Son sütun için string karşılaştırması yapıldı
                if (strcmp(part, "Iris-setosa\n") == 0)
                {
                    iris[i].Species = IrishSetosa;
                }
                else if (strcmp(part, "Iris-versicolor\n") == 0)
                {
                    iris[i].Species = IrishVersicolor;
                }
                else if (strcmp(part, "Iris-virginica\n") == 0)
                {
                    iris[i].Species = IrishVirginica;
                }
                
                
                break;

            default:
                break;
            }
            column++;
            part = strtok(NULL, " ,");
        }
    }

    //Matrix içinde species değerleride var
    float **matrix = returnMatrix(data_length, 4);
    for (int i = 0; i < data_length; i++)
    {
        matrix[i][0] = iris[i].SepalLengthCm;
        matrix[i][1] = iris[i].SepalWidthCm;
        matrix[i][2] = iris[i].PetalLengthCm;
        matrix[i][3] = iris[i].PetalWidthCm;
        matrix[i][4] = iris[i].Species;
    }

    //Matrix içinde species değerleride yok
    //Covariance matrix için kullanıldı
    float **matrix2 = returnMatrix(data_length, 4);
    for (int i = 0; i < data_length; i++)
    {
        matrix2[i][0] = iris[i].SepalLengthCm;
        matrix2[i][1] = iris[i].SepalWidthCm;
        matrix2[i][2] = iris[i].PetalLengthCm;
        matrix2[i][3] = iris[i].PetalWidthCm;

    }
    fclose(fp);
    //her sütun arrayde tutuldu
    float *SepalLength = returnVector(data_length);
    float *SepalWidth = returnVector(data_length);
    float *PetalLength = returnVector(data_length);
    float *PetalWidth  = returnVector(data_length);

    for (int i = 0; i < data_length; i++)
    {
        SepalLength[i] = matrix[i][0];
        SepalWidth[i] = matrix[i][1];
        PetalLength[i] = matrix[i][2];
        PetalWidth[i] = matrix[i][3];
        
        
    }

    //Sütun ortalamları
    float SepalLengthMean = mean(SepalLength, data_length);
    float SepalWidthMean = mean(SepalWidth, data_length);
    float PetalLengthMean = mean(PetalLength, data_length);
    float PetalWidthMean = mean(PetalWidth, data_length);

    //Sütun varyansları
    float SepalLengthVar = variance(SepalLength, data_length);
    float SepalWidthVar = variance(SepalWidth, data_length);
    float PetalLengthVar = variance(PetalLength, data_length);
    float PetalWidthVar = variance(PetalWidth, data_length);
    
    //Sütun korelasyonları
    float correlationSepalLengthSepalWidth = correlation(SepalLength, SepalWidth, data_length);
    float correlationSepalLengthPetalLength = correlation(SepalLength, PetalLength, data_length);
    float correlationSepalLengthPetalWidth = correlation(SepalLength, PetalWidth, data_length);
    

    float **covariance_Matrix = covarianceMatrix(matrix2, data_length, 4);


    FILE *fpwr;
    fpwr = fopen("IrisStatistic.txt", "w");
    if (fpwr == NULL)
    {
        printf("File not found");
        return 1;
    }
    
    //Dosya yazdırma işlemleri
    fprintf(fpwr, "Features Means:\n");
    fprintf(fpwr, "SepalLengthMean: %f\n", SepalLengthMean);
    fprintf(fpwr, "SepalWidthMean: %f\n", SepalWidthMean);
    fprintf(fpwr, "PetalLengthMean: %f\n", PetalLengthMean);
    fprintf(fpwr, "PetalWidthMean: %f\n", PetalWidthMean);

    fprintf(fpwr, "------------------------------------------------------------\n");
    
    fprintf(fpwr, "Features Variances:\n");
    fprintf(fpwr, "SepalLengthVar: %f\n", SepalLengthVar);
    fprintf(fpwr, "SepalWidthVar: %f\n", SepalWidthVar);
    fprintf(fpwr, "PetalLengthVar: %f\n", PetalLengthVar);
    fprintf(fpwr, "PetalWidthVar: %f\n", PetalWidthVar);

    fprintf(fpwr, "------------------------------------------------------------\n");

    fprintf(fpwr, "Features Correlation\n");
    fprintf(fpwr, "CorrelationSepalLengthSepalWidth: %f\n", correlationSepalLengthSepalWidth);
    fprintf(fpwr, "CorrelationSepalLengthPetalLength: %f\n", correlationSepalLengthPetalLength);
    fprintf(fpwr, "CorrelationSepalLengthPetalWidth: %f\n", correlationSepalLengthPetalWidth);
    
    fprintf(fpwr,"------------------------------------------------------------\n");

    fprintf(fpwr, "Covariance Matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fprintf(fpwr,"%f\t", covariance_Matrix[i][j]);
        }
        fprintf(fpwr,"\n");
    }
    fclose(fpwr);
    free(SepalLength);
    free(SepalWidth);
    free(PetalLength);
    free(PetalWidth);
    free(matrix);
    free(matrix2);
    free(covariance_Matrix);
    free(iris);
    
    
    return 0;
}