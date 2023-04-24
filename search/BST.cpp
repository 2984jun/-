#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MaxSize 100
typedef int KeyType;
typedef char InfoType;

typedef struct node
{
    KeyType key;
    InfoType data;
    struct node *lchild,*rchild;
}BSTNode;

int main(void)
{
    bool InsertBST(BSTNode * &bt,KeyType k);
    BSTNode * CreateBST(KeyType A[],int n);
    void Delete1(BSTNode *p,BSTNode * &r);
    void Delete(BSTNode * &p);
    bool DeleteBST(BSTNode * &bt,KeyType k);
    void SearchBST1(BSTNode * bt,KeyType k,KeyType path[],int i);
    int SearchBST2(BSTNode * bt,KeyType k);
    void DispBST(BSTNode *bt);
    bool JudgeBST(BSTNode *bt);
    void DestroyBST(BSTNode *bt);
    //-------------------------------------函数声明-------------------------------

    BSTNode *bt;
    int path[MaxSize];
    KeyType k=6;
    int a[]={4,9,0,1,8,6,3,5,2,7},n=10;
    printf("(1)创建一棵BST树:");
    printf("\n");
    bt=CreateBST(a,n);
    printf("(2)BST:");
    DispBST(bt);
    printf("\n");
    
    printf("(3)bt%s\n",(JudgeBST(bt)?"是一棵BST":"不是一棵BST"));

    printf("(4)查找%d关键字(递归，顺序):",k);
    SearchBST1(bt,k,path,-1);
    printf("(5)查找%d关键字(非递归，逆序)",k);
    SearchBST2(bt,k);
    
    printf("\n(6)删除操作:\n");
    printf("   原BST:");
    DispBST(bt);
    printf("\n");
    printf("   删除结点4");
    DeleteBST(bt,4);
    DispBST(bt);
    printf("\n");
    printf("   删除结点5");
    DeleteBST(bt,5);
    DispBST(bt);
    printf("\n");
    
    printf("(7)销毁BST\n");
    DestroyBST(bt);

    system("pause");
    return 0;
}

bool InsertBST(BSTNode * &bt,KeyType k)
{
    if(bt==NULL)
    {
        bt=(BSTNode *)malloc(sizeof(BSTNode));
        bt->key=k;
        bt->lchild=bt->rchild=NULL;
        return true;
    }else if(k==bt->key)
    {
        return false;
    }else if(k<bt->key)
    {
        return InsertBST(bt->lchild,k);
    }else
    {
        return InsertBST(bt->rchild,k);
    }
}

void DispBST(BSTNode * b);
BSTNode * CreateBST(KeyType A[],int n)
{
    BSTNode *bt=NULL;
    int i=0;
    while(i<n)
    {
        if(InsertBST(bt,A[i])==1)
        {
            printf("    第% d步,插入% d:",i+1,A[i]);
            DispBST(bt);
            printf("\n");
            i++;
        }
    }
    return bt;
}

void Delete1(BSTNode *p,BSTNode * &r)
{
    BSTNode *q;
    if(r->rchild!=NULL)
    {
        Delete1(p,r->rchild);
    }else
    {
        p->key=r->key;
        p->data=r->data;
        q=r;
        r=r->lchild;
        free(q);
    }
}

void Delete(BSTNode * &p)
{
    BSTNode *q;
    if(p->rchild==NULL)
    {
        q=p;p=p->lchild;
        free(q);
    }else if(p->lchild==NULL)
    {
        q=p;
        p=p->rchild;
        free(q);
    }else
    {
        Delete1(p,p->lchild);
    }
}

bool DeleteBST(BSTNode * &bt,KeyType k)
{
    if(bt==NULL)
    {
        return DeleteBST(bt->lchild,k);
    }else if(k>bt->key)
    {
        return DeleteBST(bt->rchild,k);
    }else
    {
        Delete(bt);
        return true;
    }
}

void SearchBST1(BSTNode *bt,KeyType k,KeyType path[],int i)
{
    int j;
    if(bt==NULL)
        return;
    else if(k==bt->key)
    {
        path[i+1]=bt->key;
        for(j=0;j<=i+1;j++)
            printf(" % 3d",path[j]);
        printf("\n");
    }else
    {
        path[i+1]=bt->key;
        if(k<bt->key)
        {
            SearchBST1(bt->lchild,k,path,i+1);
        }else
        {
            SearchBST1(bt->rchild,k,path,i+1);
        }
    }
}

int SearchBST2(BSTNode * bt,KeyType k)
{
    if(bt==NULL)
    {
        return 0;
    }else if(k==bt->key)
    {
        printf(" % 3d",bt->key);
        return 0;
    }else if(k<bt->key)
    {
        SearchBST2(bt->lchild,k);
    }else
    {
        SearchBST2(bt->rchild,k);
    }
    printf(" % 3d",bt->key);
}

void DispBST(BSTNode * bt)
{
    if(bt!=NULL)
    {
        printf("%d",bt->key);
        if(bt->lchild!=NULL || bt->rchild!=NULL)
        {
            printf("(");
            DispBST(bt->lchild);
            if(bt->rchild!=NULL)
            printf(",");
            DispBST(bt->rchild);
            printf(")");
        }
    }
}

KeyType predt=-32767;

bool JudgeBST(BSTNode *bt)
{
    bool b1,b2;
    if(bt==NULL)
        return true;
    else
    {
        b1=JudgeBST(bt->lchild);
        if(b1==false || predt>=bt->key)
            return false;
        predt=bt->key;
        b2=JudgeBST(bt->rchild);
        return b2;
    }
}

void DestroyBST(BSTNode * bt)
{
    if(bt!=NULL)
    {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}
