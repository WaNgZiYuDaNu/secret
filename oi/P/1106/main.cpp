//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//rt
string n;
int k;

//循环用
int l_id = 0;

//特判
bool f = 1;

//函数

//主函数
int main ()
{
    //输入
    cin>> n>> k;
    
    //循环找
    for ( int i = 0; i < ( ( int)( n. size ( )) - k); i ++)
    {
        //printf ( "%d", k);
        int min_id = l_id;
        //找能用的最小的
        for ( int j = l_id; j <= ( l_id + k); j ++)
        {
            if ( n [ j] < n [min_id])
            {     
                min_id = j;
            }
        }
        if ( n [ min_id] - '0' || ! f)
        {
            printf ( "%c", n [ min_id]);
        }

        //减机会
        k -= ( min_id - l_id);
        l_id = min_id + 1; 

        //特判
        if ( n [ min_id] - '0')
        {
            f = 0;
        }
        if ( ( ( int)( n. size ( )) - l_id)<= k)
        {
            break;
        }
    }

    //特判
    if ( f)
    {
        printf ( "0");
    }

    printf ( "\n");
    return 0;
}
