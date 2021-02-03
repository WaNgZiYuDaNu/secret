//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//rt
int sn;
string n;
int ans;

//循环条件
bool f = 1;

//改值条件
bool love [ ] = { 1, 0, 0, 0};

//函数
// 

//主函数
int main ()
{
    //输入
	cin>> sn>> n;

	//暴力循环
	for ( int i = 0 ; i < sn; i ++)
	{
		//判断开始
		if ( n [ i] == 'l')
		{
			//找答案
			int j = i;
			while ( f)
			{
				//循环条件
				if ( j == sn)
				{
					f = 0;
					break;
				}

				//找love
				if ( n [ j] == 'o')
				{
					love [ 1] = 1;
				}
				if ( n [ j] == 'v')
				{
					//可以加入
					if ( love [ 1])
					{
						love [ 2] = 1;
					}
				}
				if ( n [ j] == 'e')
				{
					//可以加入
					if ( love [ 2])
					{
						love [ 3] = 1;
						ans = max ( ans, j - i);
						f = 0;
					}
				}
			}
		}

	}

	//输出
	printf ( "%d\n", ans);
    return 0;
}