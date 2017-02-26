#include <iostream>
#include <cstring>
#include <cstdio>
#include <list>
#include <vector>
#include <queue>
using namespace std;
int n;
vector <list<int> > graph;
bool visited[100] = {0};
void dfs(int v)
{
    visited[v] = true;
    printf("%5d", v);
    for(auto it = graph[v].begin(); it != graph[v].end(); ++it)
        if(!visited[*it])
            dfs(*it);
}
void bfs(int v)
{
    printf("%5d", v);
    visited[v] = true;
    queue<int> t;
    t.push(v);
    while(!t.empty()){
        v = t.front();
        t.pop();
        for(auto it = graph[v].begin(); it != graph[v].end(); ++it)
            if(!visited[*it]){
                printf("%5d", *it);
                t.push(*it);
                visited[*it] = true;
            }
    }
    cout << endl;
}
int main()
{
    cin >> n;
    while (n--){
        list<int> il;
        int t;
        while(cin >> t && t != -1)
            il.push_back(t);
        graph.push_back(il);
    }
    bfs(0);
    cout <<endl;
    memset(visited, 0, sizeof(visited));
    dfs(0);
    cout <<endl;
    return 0;
}
    
