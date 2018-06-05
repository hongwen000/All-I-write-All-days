#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <climits>
using namespace std;
#define MAX_V_NUM 1000

struct MatrixGraph{
    int 	vex_num = 0;
    bool    M[MAX_V_NUM][MAX_V_NUM];
    long 	W[MAX_V_NUM][MAX_V_NUM];
};

int dijkstra(MatrixGraph *graph, int start, int dest) {
    vector<int> L;
    for(int i = 0; i < graph->vex_num; ++i) L.push_back(INT_MAX);
    L.push_back(INT_MAX);
    L[start] = 0;
    set<int> S;
    while(!S.count(dest)) {
        int u = graph->vex_num;
        for(int i = 0; i < graph->vex_num; ++i)
            if(!S.count(i) && L[i] < L[u]) u = i;
        S.insert(u);
        for(int v = 0; v < graph->vex_num; ++v)
            if(!S.count(v) && L[u] + graph->W[u][v] < L[v]) L[v] = L[u] + graph->W[u][v];
    }
    return L[dest];
}
int main() {
    int cases;
    cin >> cases;
    int total = 0;
    while(cases--){
        MatrixGraph *mp = new MatrixGraph;
        for(int i = 0; i < MAX_V_NUM; i++) {
            for(int j = 0; j < MAX_V_NUM; ++j) {
                mp->M[i][j] = false;
                if(i == j)
                    mp->W[i][j] = 0;
                else
                    mp->W[i][j] = INT_MAX;
            }
        }
        int N;
        cin >> N;
        mp->vex_num = 1 + N;
        int ori = N;
        while(N--) {
            int a, b;
            cin >> a >> b;
            a = a == 0 ? 0 : a - total;
            b = b == 0 ? 0 : b - total;
            mp->M[a][b] = true;
            mp->W[a][b] = 1;
        }
        for(int i = 1; i <= ori; ++ i) {
            int ret = dijkstra(mp, 0, i);
            if(ret != INT_MAX)
                cout << total + i << ':' << ret << endl;
        }
        cout << "---" << endl;
        total += ori;
    }
}
