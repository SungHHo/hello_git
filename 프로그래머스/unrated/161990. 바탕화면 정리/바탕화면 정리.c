#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// wallpaper_len은 배열 wallpaper의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(16);
    int len = strlen(wallpaper[0]);
    int left = 0, right = 0, up = 0, down = 0;
    for(int i = 0; i<wallpaper_len; i++)
    {
        int para = 0;
        for(int j = 0; j<len; j++)
        {
            if(wallpaper[i][j]=='.')
                continue;
            else
            {
                para = 1;
                up = i;
                break;
            }
        }
        if(para)
            break;
    }
    
    for(int i = wallpaper_len-1; i>=0; i--)
    {
        int para = 0;
        for(int j = 0; j<len; j++)
        {
            if(wallpaper[i][j]=='.')
                continue;
            else
            {
                para = 1;
                down = i;
                break;
            }
        }
        if(para)
            break;
    }
    
    for(int i = 0; i<len; i++)
    {
        int para = 0;
        for(int j = 0; j<wallpaper_len; j++)
        {
            if(wallpaper[j][i]=='.')
                continue;
            else
            {
                para = 1;
                left = i;
                break;
            }
        }
        if(para)
            break;
    }
    
    for(int i = len-1; i>=0; i--)
    {
        int para = 0;
        for(int j = 0; j<wallpaper_len; j++)
        {
            if(wallpaper[j][i]=='.')
                continue;
            else
            {
                para = 1;
                right = i;
                break;
            }
        }
        if(para)
            break;
    }
    answer[0] = up, answer[1] = left, answer[2] = down+1, answer[3] = right+1;
    return answer;
}