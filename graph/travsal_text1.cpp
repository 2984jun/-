#include "travsal.cpp"
#include<stdlib.h>

int main(void)
{
    AdjGraph *G;
    int A[MAXV][MAXV]={{0,5,INF,7,INF,INF},  {INF,0,4,INF,INF,INF},
                        {8,INF,0,INF,INF,9},    {INF,INF,5,0,INF,6},
                        {INF,INF,INF,5,0,INF},   {3,INF,INF,INF,1,0}};
    int n=6,e=10;
    CreateAdj(G,A,n,e);
    printf("图G的邻接表:\n");
    DispAdj(G);
    
    printf("从顶点0开始的DFS(递归算法):\n");
    DFS(G,0);
    printf("\n");

    printf("从顶点0开始的DFS(非递归算法):\n");
    DFS1(G,0);
    printf("\n");

    printf("从顶点0开始的BFS:\n");
    BFS(G,0);
    
    DestroyAdj(G);

    system("pause");
    return 0;
}