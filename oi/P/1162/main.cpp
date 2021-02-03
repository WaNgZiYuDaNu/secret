//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 35

using namespace std;

//struct||class


//全局变量
int n;
char map[MAXN][MAXN];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

//函数
//


//工作2
inline void work2()
{
    scanf( "%d", &n);
    
    
    for( int i = 1; i <= n; i ++)
    {
        for( int j = 1; j <=n; j++)
        {
            scanf( "%c", &map[i][j]);
            if( (map[i][j] != '1')&& ( (i != 1)&& (i != n)&& (j != 1)&& (j != n)))
            {
                map[i][j] = '2';
            }
        }
        
    }
    
    
}

//工作3
inline void work3()
{
    //printf( "", );
    
    
    for( int i = 1; i <= n; i ++)
    {
         
        for(int j = 1; j <= n; j++)
        {
            printf( "%c", map[i][j]);
        }
        printf("\n");
    }
    
    
    printf("\n");
}

//


//dfs
void dfs( int i, int j)
{
    if( (map[i][j] == '1')|| (map[i][j] == '0'))
    {
        return ;
    }
    for( int k = 0; k < 4; k ++)
    {
        if( map[i + dx[k]][j + dy[k]] == '0')
        {
            map[i][j] = '0';
        }
        else
        {
            dfs( i + dx[k], j + dy[k]);
        }
    }

}

//主函数
int main()
{
    work2();
    
    work3();
    return 0;
}