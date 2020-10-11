#include<stdio.h>
#include<stdlib.h>
int a[10][10],i,n,m,source,s[10],b[10],j;
int visited[10];
void creategraph()
{
    printf("enter the no of vertices");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
}
void bfs()
{
    int front=0,rear=-1,q[10],u;
    printf("enter the source vertex\n");
    scanf("%d",&source);
    q[++rear]=source;
    visited[source]=1;
    printf("the nodes reachable are\n");
    while(front<=rear)
    {
        u=q[front++];
        for(i=1;i<=n;i++)
        {
            if(a[u][i]==1&&visited[i]==0)
            {
                printf("\n%d",i);
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
void dfs(int source)
{
    int u,top=-1;
    s[++top]=1;
    b[source]=1;
    for(u=1;u<=n;u++)
    {
        if(a[source][u]==1&&b[u]==0)
        {
            printf("%d\t",u);
            dfs(u);}
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\nenter your choice\n1.create graph\n2.check reachability\n3.check connectivity\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    creategraph();
                    break;
            case 2: bfs();
                    for(i=1;i<=n;i++)
                        if(visited[i]==0)
                            printf("the vertex is not reachable =%d\n",i);

                    break;
            case 3: printf("enter the source vertex to find connectivity\n");
                    scanf("%d",&source);
                    m=1;
                    dfs(source);
                    for(i=1;i<=n;i++)
                        if(b[i]==0)
                            m=0;
                    if(m==1)
                        printf("Graph is connected");
                    else
                        printf("graph is not connected");
                    break;
            case 4: exit(0);
        }
    }
    return(0);
}
