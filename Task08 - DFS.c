#include<stdio.h>
#include<stdlib.h>

int a[20][20],reach[20],n;

void dfs(int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
	  if(a[v][i] && !reach[i])
        {
            printf("\n %d->%d",v,i);
            dfs(i);
        }
}
int main()
{
    system("COLOR F0");
    printf("*** Depth First Search Implementation ***\n");
	int i,j,v,count=0;
	printf("\nEnter Number of Vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        {
            reach[i]=0;
            for(j=1;j<=n;j++)
                a[i][j]=0;
        }
	printf("\nEnter the Graph Data in Matrix Form:\n\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);

    printf("\nEnter the Starting Vertex: ");
	scanf("%d", &v);
	dfs(v);
	printf("\n");
	for(i=1;i<=n;i++)
        {
            if(reach[i])
            count++;
        }

	if(count==n)
	  printf("\nGraph is Connected\n");
    else
	  printf("\nGraph is Not Connected\n");
	  return 0;
}
