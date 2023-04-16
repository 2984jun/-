#include "sqstring.cpp"
#include<stdlib.h>

void Getnextval(SqString t,int nextval[])
{
    int j,k;
    j=0;k=-1;nextval[0]=-1;
    while(j<t.length-1)
    {
        if(k==-1 || t.data[j]==t.data[k])
        {
            j++;
            k++;
            if(nextval[j]!=nextval[k])
                nextval[j]=k;
            else
                nextval[j]=nextval[k];
        }else
        {
            k=nextval[k];

        }
    }
}

void display(SqString s,SqString t,int i,int j)
{
    int k;
    printf(" ");
    for(k=0;k<i;k++)
        printf("  ");
    printf(" ↓ i=%d,j=%d\n",i,j);
    printf("s:");
    for(k=0;k<s.length;k++)
        printf("%c ",s.data[k]);
    printf("\n");
    printf("t:");
    for(k=0;k<i-j;k++)
    {
        printf("  ");
    }
    for(k=0;k<t.length;k++)
        printf("%c ",t.data[k]);
    printf("\n");
    for(k=0;k<i-j;k++)
        printf("  ");
    for(k=0;k<=j;k++)
    printf("  ");
    printf("↑ \n");

}


int count(SqString s,SqString t)
{
    int nextval[MaxSize],i=0,j=0,count=0;
    Getnextval(t,nextval);
    display(s,t,i,j);
    while(i<s.length && j<t.length)
    {
        if(j==-1 || s.data[i]==t.data[j])
        {
            i++;
            j++;
        }else
        {
            j=nextval[j];
            display(s,t,i,j);
        }
        if(j==t.length)
        {
            display(s,t,i,j);
            printf("成功匹配1次\n");
            count++;
            j=0;
        }
    }
    return count;
}


int main(void)
{
    SqString s,t;
    StrAssign(s,"aaabbdaabbde ");
    StrAssign(t,"aabbd ");
    printf("t在s中出现的次数:%d\n",count(s,t));
    DsetroyStr(s);
    DsetroyStr(t);
    system("pause");
    return 0;
}