#include <iostream>
#include <queue>
#define MOVE_ABLE (_x>=0 && _x<N && _y>=0 && _y<M)
#define INF 100000000
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
typedef pair <int,int> Position;
Position getPoistion(char *maze, char ch, int N, int M)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if (*(maze+i*N+j)==ch)
            {
                Position p;
                p.first=i;
                p.second=j;
                return p;
            }
        }
    }
}
int bfs(char* maze, int N, int M, Position start_position, Position goal_position)
{
    int dis[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            dis[i][j]=INF;
        }
    }
    queue<Position> que;
    que.push(start_position);
    dis[start_position.first][start_position.second]=0;
    while(que.size())//If when queue size ==0 still no break, no way out 
    {
        Position p=que.front();
        que.pop();
        if(p==goal_position)
        {
            break;
        }
        for(int i=0;i<4;i++)
        {
                int _x=p.first+dx[i];
                int _y=p.second+dy[i];
                if(MOVE_ABLE &&  *(maze+_x*N+_y)!= '#' && dis[_x][_y] == INF)
                {
                    que.push(Position(_x,_y));
                    dis[_x][_y]=dis[p.first][p.second]+1;// *** I Forgot This
                }
        }
    }
    return dis[goal_position.first][goal_position.second];
}
    int main()
{
    int N,M;
    cin >> N >> M;
    char maze[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>maze[i][j];
        }
    }
    Position start_position=getPoistion((char*)maze,'S',N,M);
    Position goal_position=getPoistion((char*)maze,'G',N,M);
    int result=bfs((char*)maze,N,M,start_position,goal_position); 
    cout << result <<endl;
}
