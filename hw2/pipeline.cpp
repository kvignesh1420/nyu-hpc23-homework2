#include <stdio.h>
#include "utils.h"

double inner_product_unroll8_decouple_far(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    double temp5 = 0, temp6 = 0, temp7 = 0, temp8 = 0;
    for(int i = 0; i < N/8 - 1; i++){
        sum1 += temp1;
        temp1 = a[8*i] * b[8*i];

        sum2 += temp2;
        temp2 = a[8*i + 1] * b[8*i + 1];
        
        sum3 += temp3;
        temp3 = a[8*i + 2] * b[8*i + 2];
        
        sum4 += temp4;
        temp4 = a[8*i + 3] * b[8*i + 3];
        
        sum5 += temp5;
        temp5 = a[8*i + 4] * b[8*i + 4];
        
        sum6 += temp6;
        temp6 = a[8*i + 5] * b[8*i + 5];
        
        sum7 += temp7;
        temp7 = a[8*i + 6] * b[8*i + 6];

        sum8 += temp8;
        temp8 = a[8*i + 7] * b[8*i + 7];
    }
    return sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
}

double inner_product_unroll8_decouple(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    double temp5 = 0, temp6 = 0, temp7 = 0, temp8 = 0;
    for(int i = 0; i < N/8 - 1; i++){
        temp1 = a[8*i] * b[8*i];
        temp2 = a[8*i + 1] * b[8*i + 1];
        temp3 = a[8*i + 2] * b[8*i + 2];
        temp4 = a[8*i + 3] * b[8*i + 3];
        temp5 = a[8*i + 4] * b[8*i + 4];
        temp6 = a[8*i + 5] * b[8*i + 5];
        temp7 = a[8*i + 6] * b[8*i + 6];
        temp8 = a[8*i + 7] * b[8*i + 7];
        sum1 += temp1;
        sum2 += temp2;
        sum3 += temp3;
        sum4 += temp4;
        sum5 += temp5;
        sum6 += temp6;
        sum7 += temp7;
        sum8 += temp8;
    }
    return sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
}

double inner_product_unroll8(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
    for(int i = 0; i < N/8 - 1; i++){
        sum1 += a[8*i] * b[8*i];
        sum2 += a[8*i + 1] * b[8*i + 1];
        sum3 += a[8*i + 2] * b[8*i + 2];
        sum4 += a[8*i + 3] * b[8*i + 3];
        sum5 += a[8*i + 4] * b[8*i + 4];
        sum6 += a[8*i + 5] * b[8*i + 5];
        sum7 += a[8*i + 6] * b[8*i + 6];
        sum8 += a[8*i + 7] * b[8*i + 7];
    }
    return sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
}

double inner_product_unroll4_decouple_far(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    for(int i = 0; i < N/4 - 1; i++){
        sum1 += temp1;
        temp1 = a[4*i] * b[4*i];

        sum2 += temp2;
        temp2 = a[4*i + 1] * b[4*i + 1];
        
        sum3 += temp3;
        temp3 = a[4*i + 2] * b[4*i + 2];

        sum4 += temp4;
        temp4 = a[4*i + 3] * b[4*i + 3];
    }
    return sum1 + sum2 + sum3 + sum4;
}

double inner_product_unroll4_decouple(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    for(int i = 0; i < N/4 - 1; i++){
        temp1 = a[4*i] * b[4*i];
        temp2 = a[4*i + 1] * b[4*i + 1];
        temp3 = a[4*i + 2] * b[4*i + 2];
        temp4 = a[4*i + 3] * b[4*i + 3];
        sum1 += temp1;
        sum2 += temp2;
        sum3 += temp3;
        sum4 += temp4;
    }
    return sum1 + sum2 + sum3 + sum4;
}

double inner_product_unroll4(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for(int i = 0; i < N/4 - 1; i++){
        sum1 += a[4*i] * b[4*i];
        sum2 += a[4*i + 1] * b[4*i + 1];
        sum3 += a[4*i + 2] * b[4*i + 2];
        sum4 += a[4*i + 3] * b[4*i + 3];
    }
    return sum1 + sum2 + sum3 + sum4;
}

double inner_product_unroll2_decouple_far(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, temp1 = 0, temp2 = 0;
    for(int i = 0; i < N/2 - 1; i++){
        sum1 += temp1;
        temp1 = a[2*i] * b[2*i];
        
        sum2 += temp2;
        temp2 = a[2*i + 1] * b[2*i + 1];
    }
    return sum1 + sum2;
}

double inner_product_unroll2_decouple(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0, temp1 = 0, temp2 = 0;
    for(int i = 0; i < N/2 - 1; i++){
        temp1 = a[2*i] * b[2*i];
        temp2 = a[2*i + 1] * b[2*i + 1];
        sum1 += temp1;
        sum2 += temp2;
    }
    return sum1 + sum2;
}

double inner_product_unroll2(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double sum1 = 0, sum2 = 0;
    for(int i = 0; i < N/2 - 1; i++){
        sum1 += a[2*i] * b[2*i];
        sum2 += a[2*i + 1] * b[2*i + 1];
    }
    return sum1 + sum2;
}

double inner_product_reference(double* a, double* b, long N){
    // Reference implementation of the inner product between a, b
    double res = 0;
    for(int i = 0; i < N; i++){
        res += a[i] * b[i];
    }
    return res;
}

int main(){

    long N = 10000;
    int NREPEATS=100;
    double* a = (double *) aligned_malloc( N * sizeof(double) );
    double* b = (double *) aligned_malloc( N * sizeof(double) );
    for (int i = 0; i < N; i++){
        a[i] = drand48();
        b[i] = drand48();
    }

    Timer tt;
    tt.tic();
    double res_reference;
    for (int j = 0; j < NREPEATS; j++){
        res_reference = inner_product_reference(a, b, N);
    }
    printf("Time taken: %f  Inner product reference result: %f\n", tt.toc(), res_reference);

    tt.tic();
    double res_unroll2;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll2 = inner_product_unroll2(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 2 result: %f\n", tt.toc(), res_unroll2);

    tt.tic();
    double res_unroll2_decouple;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll2_decouple = inner_product_unroll2_decouple(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 2 decouple result: %f\n", tt.toc(), res_unroll2_decouple);

    tt.tic();
    double res_unroll2_decouple_far;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll2_decouple_far = inner_product_unroll2_decouple_far(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 2 decouple far result: %f\n", tt.toc(), res_unroll2_decouple_far);

    tt.tic();
    double res_unroll4;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll4 = inner_product_unroll4(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 4 result: %f\n", tt.toc(), res_unroll4);

    tt.tic();
    double res_unroll4_decouple;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll4_decouple = inner_product_unroll4_decouple(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 4 decouple result: %f\n", tt.toc(), res_unroll4_decouple);

    tt.tic();
    double res_unroll4_decouple_far;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll4_decouple_far = inner_product_unroll4_decouple_far(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 4 decouple far result: %f\n", tt.toc(), res_unroll4_decouple_far);


    tt.tic();
    double res_unroll8;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll8 = inner_product_unroll8(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 8 result: %f\n", tt.toc(), res_unroll8);

    tt.tic();
    double res_unroll8_decouple;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll8_decouple = inner_product_unroll8_decouple(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 8 decouple result: %f\n", tt.toc(), res_unroll8_decouple);

    tt.tic();
    double res_unroll8_decouple_far;
    for (int j = 0; j < NREPEATS; j++){
        res_unroll8_decouple_far = inner_product_unroll8_decouple_far(a, b, N);
    }
    printf("Time taken: %f  Inner product unroll 8 decouple far result: %f\n", tt.toc(), res_unroll8_decouple_far);


    return 0;
}