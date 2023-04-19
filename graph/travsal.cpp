#include "graph.cpp"

int visited[MAXV];

void DFS(AdjGraph *G,int v)
{
    ArcNode * p;
    printf("% 3d",v);
    visited[v]=1;
    p=G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if(visited[p->adjvex]==0)
            DFS(G,p->adjvex);
        p=p->nextarc;
    }
}

void DFS1(AdjGraph *G,int v)
{
    ArcNode *p;
    int St[MAXV];
    int top=-1,w,x,i;
    for(i=0;i<G->n;i++)
        visited[i]=0;
    printf("% 3d",v);
    visited[v]=1;
    top++;
    St[top]=v;
    while(top>-1)
    {
        x=St[top];
        p=G->adjlist[x].firstarc;
        while(p!=NULL)
        {
            w=p->adjvex;
            if(visited[w]==0)
            {
                printf("% 3d",w);
                visited[w]=1;
                top++;
                St[top]=w;
                break;
            }
            p=p->nextarc;
        }
        if(p==NULL) top--;
    }
    printf("\n");
}

void BFS(AdjGraph * G,int v)
{
    ArcNode *p;
    int queue[MAXV],front=0,rear=0;
    int visited[MAXV];
    int w,i;
    for(i=0;i<G->n;i++)
        visited[i]=0;
    printf("% 3d",v);
    visited[v]=1;
    rear=(rear+1)%MAXV;
    queue[rear]=v;
    while(front!=rear)
    {
        front=(front+1)%MAXV;
        w=queue[front];
        p=G->adjlist[w].firstarc;
        while(p!=NULL)
        {
            if(visited[p->adjvex]==0)
            {
                printf("% 3d",p->adjvex);
                visited[p->adjvex]=1;
                rear=(rear+1)%MAXV;
                queue[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
    printf("\n");
}