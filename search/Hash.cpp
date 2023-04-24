#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
#define NULLKEY -1
#define DELKEY -2

typedef int KeyType;
typedef char InfoType;

typedef struct
{
    KeyType key;
    InfoType data;
    int count;
}HashTable;

int main(void)
{
    void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k);
    void CreateHT(HashTable ha[],KeyType x[],int n,int m,int p);
    int SearchHT(HashTable ha[],int m,int p,KeyType k);
    int DeleteHT(HashTable ha[],int m,int p,int &n,int k);
    void DispHT(HashTable ha[],int n,int m);
//------------------------------函数声明----------------------------------

    int x[]={16,74,60,43,54,90,46,31,29,88,77};
    int n=11,m=13,p=13,i,k=29;
    HashTable ha[MaxSize];

    printf("(1)创建哈希表\n");
    CreateHT(ha,x,n,m,p);
    
    printf("输出哈希表:\n");
    DispHT(ha,n,m);

    printf("(3)查找关键字为%d的记录位置\n",k);
    i=SearchHT(ha,m,p,k);
    if(i!=-1)
        printf("    ha[%d].key=%d\n",i,k);
    else 
        printf("    提示:未找到%d\n",k);
    
    k=77;
    printf("(4)删除关键字%d\n",k);
    DeleteHT(ha,m,p,n,k);
    printf("(5)删除后的哈希表\n");
    DispHT(ha,n,m);

    printf("(6)查找关键字为%d的记录位置\n",k);
    i=SearchHT(ha,m,p,k);
    if(i!=-1)
        printf("    ha[%d].key=%d\n",i,k);
    else
        printf("    提示:   未找到%d\n",k);
    
    printf("(7)插入关键字%d\n",k);
    InsertHT(ha,n,m,p,k);
    printf("(8)插入后的哈希表\n");
    DispHT(ha,n,m);
    
    system("pause");
    return 0;
}

void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k)
{
    int i,adr;
    adr=k%p;
    if(ha[adr].key==NULLKEY || ha[adr].key==DELKEY)
    {
        ha[adr].key=k;
        ha[adr].count=1;
    }else
    {
        i=1;
        do
        {
            adr=(adr+1)%m;
            i++;
        }while(ha[adr].key!=NULLKEY && ha[adr].key!=DELKEY);
        ha[adr].key=k;
        ha[adr].count=i;
    }
    n++;
}


void CreateHT(HashTable ha[],KeyType x[],int n,int m,int p)
{
    int i,n1=0;
    for(i=0;i<m;i++)
    {
        ha[i].key=NULLKEY;
        ha[i].count=0;
    }
    for(i=0;i<n;i++)
    {
        InsertHT(ha,n1,m,p,x[i]);
    }
}

int SearchHT(HashTable ha[],int m,int p,KeyType k)
{
    int i=0,adr;
    adr=k%p;
    while(ha[adr].key!=NULLKEY && ha[adr].key!=k)
    {
        i++;
        adr=(adr+1)%m;
    }
    if(ha[adr].key==k)
        return adr;
    else return -1;
}

int DeleteHT(HashTable ha[],int m,int p,int &n,int k)
{
    int adr;
    adr=SearchHT(ha,m,p,k);
    if(adr!=-1)
    {
        ha[adr].key=DELKEY;
        n--;
        return 1;
    }else   
        return 0;
}

void DispHT(HashTable ha[],int n,int m)
{
    float avg=0;
    int i;
    printf("    哈希表地址: ");
    for(i=0;i<m;i++)
        printf(" % -4d",i);
    printf("\n");
    printf("    哈希表关键字:");
    for(i=0;i<m;i++)
    {
        if(ha[i].key==NULLKEY || ha[i].key==DELKEY)
            printf("    ");
        else
            printf(" % -4d",ha[i].key);
    }
    printf("\n");
    printf("    探测次数:   ");
    for(i=0;i<m;i++)
        if(ha[i].key==NULLKEY || ha[i].key==DELKEY)
            printf("    ");
        else
            printf(" % -4d",ha[i].count);
    printf("\n");
    for(i=0;i<m;i++)
        if(ha[i].key!=NULLKEY && ha[i].key!=DELKEY)
            avg=avg+ha[i].count;
    avg=avg/n;
    printf("    平均查找长度ASL(%d)=%g\n",n,avg);
}
