#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ranges_rows는 2차원 배열 ranges의 행 길이, ranges_cols는 2차원 배열 ranges의 열 길이입니다.
double* solution(int k, int** ranges, size_t ranges_rows, size_t ranges_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    double arr[300];
    int count = 0;
    int before = 0;
    double sum = 0;
    arr[0] = 0.0;
    while(k!=1)
    {
        count++;
        before = k;
        if(k%2)
            k = k*3+1;
        else
            k/=2;
        sum += (double)(before+k)/2.0;
        arr[count] = sum;
    }
    double* answer = (double*)malloc(sizeof(double)*ranges_rows);
    for(int i = 0; i<ranges_rows; i++)
    {
        int start = ranges[i][0];
        int end = count+ranges[i][1];
        if(start>end)
            answer[i] = -1;
        else
            answer[i] = arr[end]-arr[start];
    }
    
    return answer;
}