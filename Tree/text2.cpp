#include "btree.cpp"

void AllPath1(BTNode *b,ElemType path[],int pathlen)
{
    if(b!=NULL)
    {
        if(b->lchild==NULL && b->rchild==NULL)
        {
            printf("    %c到根节点逆路径: %c->",b->data,b->data);
            for(int i=pathlen-1;i>0;i--)
            {
                printf("%c->",path[i]);
            }
            printf("%c\n",path[0]);
        }else
        {
            path[pathlen]=b->data;
            pathlen++;
            AllPath1(b->lchild,path,pathlen);
            AllPath1(b->rchild,path,pathlen);

        }
    }
}

void LongPath1(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],int &longpathlen)
{
    if(b==NULL)
    {
        if(pathlen>longpathlen)
        {
            for(int i=pathlen-1;i>=0;i--)
                longpath[i]=path[i];
            longpathlen=pathlen;
        }
    }else
    {
        path[pathlen]=b->data;
        pathlen++;
        LongPath1(b->lchild,path,pathlen,longpath,longpathlen);
        LongPath1(b->rchild,path,pathlen,longpath,longpathlen);
    }
}

void AllPath2(BTNode *b)
{
    BTNode *st[MaxSize];
    int top=-1;

    BTNode *p,*r;
    bool flag;
    p=b;
    do
    {
        while(p!=NULL)
        {
            top++;
            st[top]=p;
            p=p->lchild;

        }
        r=NULL;
        flag=true;
        while(top>-1 && flag)
        {
            p=st[top];
            if(p->rchild==r)
            {
                if(p->lchild==NULL && p->rchild==NULL)
                {
                    printf("    %c到根节点逆路径:",p->data);
                    for(int i=top;i>0;i--)
                    {
                        printf("%c->",st[i]->data);
                    }
                    printf("%c\n",st[0]->data);
                }
                top--;
                r=p;
            }else
            {
                p=p->rchild;
                flag=false;
            }
        }
    }while (top>-1);
}

void AllPath3(BTNode *b)
{
    struct snode
    {
        BTNode *node;
        int parent;
    }Qu[MaxSize];

    int front,rear,p;
    front=rear=-1;
    rear++;
    Qu[rear].node=b;
    Qu[rear].parent=-1;
    while(front<rear)
    {
        front++;
        b=Qu[front].node;
        if(b->lchild==NULL && b->rchild==NULL)
        {
            printf("    %c到根节点逆路径:",b->data);
            p=front;
            while(Qu[p].parent!=-1)
            {
                printf("%c->",Qu[p].node->data);
                p=Qu[p].parent;
            }
            printf("%c\n",Qu[p].node->data);
        }

        if(b->lchild!=NULL)
        {
            rear++;
            Qu[rear].node=b->lchild;
            Qu[rear].parent=front;
        }
        if(b->rchild!=NULL)
        {
            rear++;
            Qu[rear].node=b->rchild;
            Qu[rear].parent=front;
        }
    }
}

int main(void)
{
    BTNode *b;
    ElemType path[MaxSize],longpath[MaxSize];
    int i,longpathlen=0;
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树b:");
    DispBTree(b);
    printf("\n");
    printf("先序遍历方法:\n");
    AllPath1(b,path,0);
    LongPath1(b,path,0,longpath,longpathlen);
    printf("    第一条最长逆路径长度:%d\n",longpathlen);
    printf("    第一条最长逆路径:");
    for(i=longpathlen-1;i>=0;i--)
    {
        printf("%c",longpath[i]);

    }
    printf("\n");
    printf("后序非递归遍历方法:\n");
    AllPath2(b);
    printf("层次遍历方法:\n");
    AllPath3(b);
    
    system("pause");
    return 0;
}