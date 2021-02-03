#include <iostream>
#define maxv 1e9
using namespace std;
int n, m, edge[50][50];
struct node{
    int len;
    int father = 1;
}dis[50];
bool vis[50];


void dij(){
    for(int i = 1; i < n; i++){
        int minv = maxv;
        int used = 1;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && dis[j].len < minv){
                used = j;
                minv = dis[j].len;
            }
        }
        vis[used] = true;
        for(int j = 1; j <= n; j++){
            if(edge[used][j] < maxv){
                if(dis[j].len > dis[used].len+edge[used][j]){
                    dis[j].len = dis[used].len+edge[used][j];
                    dis[j].father = used;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                edge[i][j] = 0;
            else
                edge[i][j] = maxv;
        }
    }
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
    }
    for(int i = 1; i <= n; i++){
        dis[i].len = edge[1][i];
    }
    vis[1] = true;
    dis[1].father = 0;
    dij();
    int s[100], top = 0;
    for(int i = 1; i <= n; i++){
        int k = i;
        while(k > 0){
            s[top++] = k;
            k = dis[k].father;
        }
        while(top){
            cout << s[--top] << " ";
        }
        cout << endl;
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
*/