#include <bits/stdc++.h>
#define N 10000
using namespace std;
const int maxv = 2847483647; //无穷大
int n, m, q;  //顶点个数  边数
bool visited[N]; //标记访问数组
int edge[N][N], dist[N];  //邻接矩阵  最短距离
//优先队列优化
priority_queue<int,vector<int>,greater<int>>pq;

void dijkstra(){
    for(int i = 1; i < n; i++){
        int minv = maxv;  //最小值
        int used;  //最近点
        for(int j = 1; j <= n; j++){  //寻找没有走过并距离源点最近点
            if(!visited[j] && pq. top () < minv){
                minv = pq .top ();
                used = j;
            }
        }
        visited[used] = true;  //加入已走过
        for(int j = 1; j <= n; j++){  //通过当前加入的更新其他点
            if(edge[used][j] < maxv){
                if(pq . top ( ) > pq.top ( ) + edge[used][j]){
                    pq .push( pq.top ( ) + edge[used][j]);
                }
            }
        }
    }

}


int main()
{
    cin >> n >> m>> q;
    for(int i = 1; i <= n; i++){  //图的初始化
        for(int j = 1; j <= n; j++){
            edge[i][j] = maxv;
        }
        edge[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edge[x][y] = z;
    }
    for(int i = 1; i <= n; i++){
        pq. push( edge[q][i]);
    }
    visited[q] = true;  //源点标记
    dijkstra();
    for(int i = 1; i <= n; i++){
        cout << q.top << " ";
        q.pop ();
    }
    return 0;
}
/*
6 9
1 2 2
1 4 15
2 3 5
2 4 3
2 5 4
3 6 10
3 5 12
4 5 3
5 6 6

0 2 7 5 6 12
*/