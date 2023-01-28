/*
* @file Fırat Erdem Doğan-2021221041-Proje2
* @description Iris.csv dosyasından alınan veriler kullanılarak, çeşitli lineer cebir işlemlerinin gerçekleştirilmesi amaçlanmıştır.
* @assignment 2.Proje
* @date 20/12.2022
* @author yazar adı ve mail adresi
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *returnVector(int size)
{
    //Bellekten array için dinamik olarak bellekten yer ayrılmaktadır.
    float *arr = (float *)malloc(size * sizeof(float));
    return arr;
}

float **returnMatrix(int row, int col)
{
    //Bellekten matrixin satırları için dinamik olarak bellekten yer ayrılmaktadır.
    float **matrix = (float **)malloc((row) * sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        //Bellekten matrixin sütunları için dinamik olarak bellekten yer ayrılmaktadır.
        matrix[i] = malloc(sizeof(float) * col);
    }

    return matrix;
}

//Bellekten dinamik olarak boyutu kadar yer ayrılan boyutu, belleğe iade edilmektedir.
void freeMatrix(float **mat, int row)
{

    for (int i = 0; i < row; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

float mean(float *vec, int size)
{
    //Arrayin her elemanını sum değişkenine eklenmektedir.
    

    float sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += vec[i];
    }
    // Eleman toplamlarını arrayin boyutuna bölerek, arrayin ortalaması bulunmaktadır.
    return (sum / size);
}

float correlation(float *vec, float *vec2, int size)
{   
    // Formül

    /*
                    (size * sum(vec.vec2)) - (sum(vec) * sum(vec2))
    R = -------------------------------------------------------------------------------
        sqrt( ((size * sum(vec^2)) - sum(vec)^2) * ((size * sum(vec2^2)) - sum(vec2)^2))

    */

    // vec elemanlar toplamı
    float sum_x = 0;
    // vec2 elemanlar toplamı
    float sum_y = 0;
    // vec ve vec2 elemanlar çarpımı
    float multi_xy = 0;
    // vec elemanlarının karesi toplamı
    float sum_pow_x = 0;
    // vec2 elemanlarının karesi toplamı
    float sum_pow_y = 0;

    // Formül sonucun çıktısı
    float result = 0;

    /* 2 arrayide gezerek elemanları, elemanlarının karesi ve sırasıyla 2 arrayin elemanlarını çarpıp
    değişkenlere eklenmektedir.*/

    for (int i = 0; i < size; i++)
    {
        sum_x += vec[i];
        sum_pow_x += pow(vec[i], 2);
        sum_y += vec2[i];
        sum_pow_y += pow(vec2[i], 2);
        multi_xy += vec[i] * vec2[i];
    }

    //Formülü pay ve payda şeklinde ayrı ayrı hesaplanmaktadır.
    float pay = ((size * multi_xy) - (sum_x * sum_y));
    float payda = sqrt(((size * sum_pow_x) - pow(sum_x, 2)) * ((size * sum_pow_y) - pow(sum_y, 2)));

    result = pay / payda;

    return result;
}

float covariance(float *vec1, float *vec2, int size)
{

    /*
    
    Her iki arrayin elemanları için aşağıdaki
    formül uygulanmaktadır.

    cov = (Xi - Ymean)(Yi - Ymean)
          ------------------------
                     N - 1
    i = eleman sayısı

    */
    // vec1'in ortalaması
    float mean_x = mean(vec1,size);
    // vec2'nin ortalaması
    float mean_y = mean(vec2,size);


    float result = 0;

    //Her iki arrayin elemanları için formül uygulanmaktadır.
    
    for (int j = 0; j < size; j++)
    {
        result += (vec1[j] - mean_x) * (vec2[j] - mean_y);
    }
    return (result / size - 1);
}

float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2)
{

    // Sonuç matrixsin satır sayısı, row1'e eşittir.
    // Sonuç matrixsin sütun sayısı, col2'ye eşittir.
    // Çarpım sonucu oluşacak matrix dinamik olarak oluşturulmaktadır.

    //Sonuç matrix için bellekten dinamik olarak yer ayrılmaktadır.
    float **multi_mat = returnMatrix(row1,col2);


    //Sırasıyla satır ile sütunu elemanlarını çarpılmaktadır.
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            // Sonuç matrixin her elemanı, satır ve sütun elemanlarının sırasıyla çarpımı ile bulunduğu için  1.sütun boyutu  kadar çarpma işlemine devam edilmektedir.
            for (int k = 0; k < col1; k++)
            {
                multi_mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return multi_mat;
}

float **matrixTranspose(float **mat, int row, int col)
{
    float **mat_transpose = returnMatrix(col,row);

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            // Her sütunu yeni matriximizdeki satır olacka şekilde atılmaktadır.
            mat_transpose[i][j] = mat[j][i];
        }
    }
    return mat_transpose;
}

float *rowMeans(float **mat, int row, int col)
{
    // Matrixin satır elemanları toplanıp sütun sayısına bölünmektedir.
    float *result_vec = returnVector(row);

    for (int i = 0; i < row; i++)
    {

        result_vec[i] = mean(mat[i], col);
    }

    return result_vec;
}

float *columnMeans(float **mat, int row, int col)
{
    // Matrixin sütun elemanları toplanıp satır sayısına bölünmektedir.

    float *result_vec = returnVector(col);
    float **transpose_mat = matrixTranspose(mat, row, col);

    // Matrixin transpozunu alarak sütunları satır haline getirdik.Böylelikle daha kolay bir şekilde sütun ortalamasını hesaplanılmaktadır.
    for (int i = 0; i < col; i++)
    {

        result_vec[i] = mean(transpose_mat[i], row);
    }

    free(transpose_mat);
    return result_vec;
}

float **covarianceMatrix(float **mat, int row, int col)
{
    // Her bir sütunun  ortaması alınıp arrayde tutulmaktadır.
    float *col_mean = columnMeans(mat, row, col);

    // Matrixin sütun elemanlarından, sütunlar ortalamasını tutulan arrayde, index sayısı sütun sayınına denk gelen değerlerden çıkarılmaktadır. 
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {

            mat[i][j] = mat[i][j] - col_mean[j];
        }
    }

    float **new_mat = returnMatrix(col, row);
    // Çıkarma işlemlerinin ardından yeni oluşan matriximizin transpozunu alınmaktadır.
    new_mat = matrixTranspose(mat, row, col);
    
     // Çıkarma işlemlerinin ardından yeni oluşan matrix ile aynı matrixin transpozu olan matrix çarpılmaktadır.
    float **result_multi_mat = matrixMultiplication(new_mat, mat, col, row, row, col);

    // Çarpma işlemi ardından oluşan matrixin elemanları satır sayısına bölünmektedir.
    for (int i = 0; i < col; i++)
    {

        for (int j = 0; j < col; j++)
        {

            result_multi_mat[i][j] = result_multi_mat[i][j] / row;
        }
    }
    
    return result_multi_mat;
}

float determinant(float **mat, int row)
{
    // 3x3 Matrixin boyutunu sütun sayısı 5 olacak şekilde güncellenmektedir.
    for (int i = 0; i < row; i++)
    {
        mat[i] = realloc(mat[i], sizeof(int) * 5);
    }

    // İlk iki sütun elemanları 3. ve 4. sütundaki elemanlara atanmaktadır.
    for (int i = 0; i < row; i++)
    {
        for (int j = row; j < 5; j++)
        {
            mat[i][j] = mat[i][j - row];
        }
    }

    //Pozitif çaprazların toplamı
    float sum_positive = 0;
    //Negatif çaprazların toplamı
    float sum_negative = 0;

    // Positif çaprazlar(1.2.3)
    float positive_multiple1 = 1;
    float positive_multiple2 = 1;
    float positive_multiple3 = 1;

    // Negatif çaprazlar(1.2.3)
    float negative_multiple1 = 1;
    float negative_multiple2 = 1;
    float negative_multiple3 = 1;
    
    
        
    // Tüm Pozitif ve Negatif çarpanlar için çarpanların elemanları birbirleriyle çarpılmaktadır.
    for (int i = 0, j = 1, k = 2, a = 2; i < 3; i++,j++,k++,a--)
    {
        positive_multiple1 *= mat[i][i];

        positive_multiple2 *= mat[i][j];

        positive_multiple3 *= mat[i][k];

        negative_multiple1 *= mat[a][i];

        negative_multiple2 *= mat[a][j];

        negative_multiple3 *= mat[a][k];

    }

    // Pozitif ve negatif çarpanlar toplanmaktadır.
    // Pozitif ve negatif çarpanlar toplamı birbirinden çıkarılmaktadır.
    sum_positive = positive_multiple1 + positive_multiple2 + positive_multiple3;
    sum_negative = negative_multiple1 + negative_multiple2 + negative_multiple3;

    return (sum_positive - sum_negative);
}

void printVector(float *vec, int N)
{
    // Arrayin her elemanını yazdırılmaktadır.
    for (int i = 0; i < N; i++)
    {

        printf("%f\t", vec[i]);
    }
}
void printMatrix(float **mat, int row, int col)
{
    // Matrixin her elemanını yazdırılmaktadır.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%f\t", mat[i][j]);
        }
        printf("\n");
    }
}

float *flipVector(float *vec, int N, int seed)
{
    // Terminalden alınan seed değeri yardımıyla sürekli farklı değerler üreten array oluşturulmaktadır.
    srand(seed);


    for (int i = 0; i < N; i++)
    {

        vec[i] = (1 + rand() % 10);
    }
    return vec;


}
float **flipMatrix(float **mat, int row, int col, int seed)
{
    // Terminalden alınan seed değeri yardımıyla sürekli farklı değerler üreten matrix oluşturulmaktadır.
    srand(seed);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = (1 + rand() % 10);
        }
    
    }
    return mat;

}

float variance(float *vec, int N)
{
    // Arrayin ortalaması
    float meanofVector = mean(vec, N);
    // Arrayin ortalaması ile her elemanının farkının karesi toplanmaktadır.
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += pow(vec[i] - meanofVector, 2);
    }
    
    return sum / N;
}