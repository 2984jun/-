#include "graph.cpp"
#include<stdlib.h>

void Prim(MatGraph g,int v)
{
    int lowcost[MAXV],min,n=g.n;
    int closest[MAXV],i,j,k;
    for(i=0;i<n;i++)
    {
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }

    for(i=1;i<n;i++)
    {
        min=INF;
        for(j=0;j<n;j++)
        {
            if(lowcost[j]!=0 && lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;

            }
        }
        printf("   边( % d,% d)权为:%d\n",closest[k],k,min);
        lowcost[k]=0;
        for(j=0;j<n;j++)
        {
            if(g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
                {
                    lowcost[j]=g.edges[k][j];
                    closest[j]=k;
                }
        }
    }
}

int main(void)
{
    int v=3;
    MatGraph g;
    int A[MAXV][MAXV]={
        {0,5,8,7,INF,3},{5,0,4,INF,INF,INF},{8,4,0,5,INF,9},
        {7,INF,5,0,5,6},{INF,INF,INF,5,0,1},{3,INF,9,6,1,0}
    };
    int n=6,e=10;
    CreateMat(g,A,n,e);
    printf("图G的邻接矩阵:\n");
    DispMat(g);

    printf("Prim算法求解结果:\n");
    Prim(g,0);

    system("pause");
    return 0;
}