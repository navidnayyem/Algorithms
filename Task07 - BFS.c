#include<stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v)
{
	for(i = 1; i <= n; i++)
		if(a[v][i] && !visited[i])
			q[++r] = i;
	if(f <= r)
        {
            visited[q[f]] = 1;
            bfs(q[f++]);
        }
}

int main()
{
    system("COLOR F0");
    printf("*** Breadth First Search Implementation ***\n");
	int v;
	printf("\nEnter the Number of Vertices: ");
	scanf("%d", &n);

	for(i=1;i<=n;i++)
        {
            q[i] = 0;
            visited[i] = 0;
        }

	printf("\nEnter Graph Data in Matrix Form:\n\n");
	for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

	printf("\nEnter the Starting Vertex: ");
	scanf("%d", &v);
	bfs(v);
	printf("\nThe Nodes which are reachable are: ");

	for(i=1; i <= n; i++)
        {
            if(visited[i])
			printf("%d\t", i);
		else
            {
                printf("\nBFS is not Possible. Not all nodes are reachable\n");
                break;
            }
        }
    printf("\n");
}
