#include "graph.cpp"
#include<stdlib.h>

#define MaxSize 100

typedef struct
{
    int start;
    int end;
    int w;      //权值
}Edge;

/*
void InsortSotr(Edge E[],int n)
{
    int i,j;
    Edge temp;
    for(i=0;i<n;i++)
    {
        temp=E[i];
        for(j=i+1;j<n;j++)
        {
            if(temp.w>E[j].w)
            {
                temp.w=temp.w ^ E[j].w;
                E[j].w=temp.w ^ E[j].w;
                temp.w=temp.w ^ E[j].w;
            }
        }
    }
}
*/


/*
int Find(int *vset,int f)
{
    while(vset[f]>0)
        f=vset[f];
    return f;
}
*/

void InsertSort(Edge E[],int n)
{
    int i,j;
    Edge temp;
    for(i=1;i<n;i++)
    {
        temp=E[i];
        j=i-1;
        while(j>=0 && temp.w<E[j].w)
        {
            E[j+1]=E[j];
            j--;
        }
        E[j+1]=temp;
    }
}


void Kruskal(MatGraph g)
{
    int i,j,start1,end1,sn1,sn2,k;
    int vset[MAXV];
    Edge E[MaxSize];
    k=0;
    for(i=0;i<g.n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(g.edges[i][j]!=0 && g.edges[i][j]!=INF)
            {
                E[k].start=i;
                E[k].end=j;
                E[k].w=g.edges[i][j];
                k++;
            }
        }
    }

    InsertSort(E,g.e);
    
    
    for(i=0;i<g.n;i++)
    {
        vset[i]=i;
    }
    k=1;
    j=0;
    while(k<g.n)
    {
        start1=E[j].start;
        end1=E[j].end;
        sn1=vset[start1];
        sn2=vset[end1];
        if(sn1!=sn2)
        {
            printf("   (% d,% d):% d\n",start1,end1,E[j].w);
            k++;
            for(i=0;i<g.n;i++)
            {
                if(vset[i]==sn2)
                    vset[i]=sn1;
            }
        }
        j++;
    }
    

/*
        for(i=0;i<g.n;i++)
        {
            vset[i]=0;
        }
        for(i=0;i<g.n;i++)
        {
            start1=Find(vset,E[i].start);
            end1=Find(vset,E[i].end);
            if(start1!=end1)
            {
                vset[start1]=end1;
                printf("   (% d,% d):% d\n",start1,end1,E[j].w);
            }
        }
*/

}


int main(void)
{
    int u=3;
    MatGraph g;
    int A[MAXV][MAXV]={
        {0,5,8,7,INF,3},{5,0,4,INF,INF,INF},{8,4,0,5,INF,9},
        {7,INF,5,0,5,6},{INF,INF,INF,5,0,1},{3,INF,9,6,1,0}
    };
    int n=6,e=10;
    CreateMat(g,A,n,e);
    printf("图G的邻接矩阵:\n");
    DispMat(g);
    
    printf("Kruskal算法求解结果:\n");
    Kruskal(g);

    system("pause");
    return 0;
}