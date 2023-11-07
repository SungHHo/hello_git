#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int** ans = (int**)malloc(sizeof(int*)*(n+2));
    for(int i = 0; i<n+2; i++)
    {
        ans[i] = (int*)malloc(sizeof(int)*(n+2));
    }
    for(int i = 0; i<n+2; i++)
    {
        for(int j = 0; j<n+2; j++)
        {
            ans[i][j] = 0;
        }
    }
    int count = 1;
    int x = 1, y = 1;
    int para = 1;
    while(count <= (n*n))
{
    if(para == 1)
    {
        while(y <= n && !ans[x][y])
        {
            ans[x][y++] = count++;
        }
        y--, x++, para = 2;
    }
    else if(para == 2)
    {
        while(x <= n && !ans[x][y])
        {
            ans[x++][y] = count++;
        }
        x--, y--, para = 3;
    }
    else if(para == 3)
    {
        while(y > 0 && !ans[x][y])
        {
            ans[x][y--] = count++;
        }
        y++, x--, para = 4;
    }
    else if(para == 4)
    {
        while(x > 0 && !ans[x][y])
        {
            ans[x--][y] = count++;
        }
        x++, y++, para = 1;
    }
}
    int** answer = (int**)malloc(sizeof(int*)*(n));
    for(int i = 0; i<n; i++)
    {
        answer[i] = (int*)malloc(sizeof(int)*(n));
        for(int j = 0; j<n; j++)
        {
            answer[i][j] = ans[i+1][j+1];
        }
        free(ans[i+1]);
    }
    free(ans[0]);
    free(ans[n+1]);
    free(ans);
    return answer;
}