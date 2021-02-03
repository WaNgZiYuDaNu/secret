//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//全局变量||struct||class
//rt
int na, n, m, k;
int j = 0;
int ans = 0;

//新a
struct na_
{
	//id
	int id;

	//值
	int ai;

	//是否被选
	bool f;
} a [ 1010];

//分区
int fq [ 1010];
int c = 0;

//函数
// cmd
bool cmd1 ( na_ x, na_ y)
{
	return x. ai < y. ai;
}

bool cmd2 ( na_ x, na_ y)
{
	return x. id > y. id;
}

//主函数
int main ()
{
    //输入
    cin>> n>> m>> k;
    for ( int i = 1; i <= n; i ++)
    {
    	cin>> na;
    	a [ i]. id = i;
    	a [ i]. ai = na;
    	a [ i]. f = 0;
    }

    //计算
    sort ( a + 1, a + 1 + n, cmd1);
    fq [ ++ c] = 1;
   	for ( int i = 1; i <= k; i ++)
    {
		if ( a [ i]. ai != a [ i + 1]. ai)
		{
			fq [ ++ c] = i + 1;
		}
    }
    fq [ ++ c] = k;
    for ( int i = 1; i < c; i ++)
    {
    	int f1 = fq [ i], f2 = fq [ i + 1];
    	sort ( a + f1, a + f2, cmd2);
    }
    for ( int i = 1; i <= k; i ++)
    {
    	ans += a [ i]. ai;
    }

    //输出
	printf ( "%d", ans);
    return 0;
}