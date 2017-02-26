#include <iostream>
#include <queue>
#define N 5
using namespace std;
int maze[N][N] = {
    {0,2,0,6,0},
    {2,0,3,8,5},
    {0,3,0,0,7},
    {6,8,0,0,9},
    {0,5,7,9,0}
};
int visited[N + 1] = {0};
void DFS(int start)
{
    visited[start] = 1;
    for (int i = 1; i <= N; i++)
       if(!visited[i] && maze[start - 1][i - 1]) DFS(i); 
    cout << start << " ";
}
void BFS(int start)
{
    queue<int> Q;
    Q.push(start);
    visited[start] = 1;
    while(!Q.empty()){
        int front = Q.front();
        cout << front << " ";
        Q.pop();
        for(int i = 1; i <= N; i++){
            if(!visited[i] && maze[front - 1][i - 1]){
                visited[i] = 1;
                Q.push(i);
            }
        }
    }
}
// Prim Algorithm
#include <limits.h>
//找到不在mst集合中的顶点中值最小的一个
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < N; v++)
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}
//输出mst集合
int printMST(int parent[], int n, int graph[N][N])
{
    printf("Edge Weight\n");
    for (int i = 1; i < N; i++)
        printf("%d - %d : %d \n", parent[i], i, graph[i][parent[i]]);
}
//建立mst
void constructMST(int graph[N][N])
{
    int parent[N];
    int key[N];
    bool mstSet[N];
    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < N-1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < N; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
    printMST(parent, N, maze);
}
int main()
{
    for (int i = 1; i <= N; i++){
        if(visited[i] == 1) continue;
        DFS(i);
    }
    constructMST(maze);
    cout << endl;
}
