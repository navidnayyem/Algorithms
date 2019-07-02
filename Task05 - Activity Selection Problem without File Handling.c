#include<stdio.h>
#include<stdlib.h>

void activity_selection_problem(int start[], int end[], int size)
{
    printf("\n|-------------------------------------------------|\n");
    printf(" >>>Following Activities are Selected: ");
    printf("0 ");
    int j,i=0;
    for(j=1; j< size; j++)
        if(start[j] >= end[i])
          {
            printf("%d ",j);
            i = j;
          }
    printf("<<<\n|-------------------------------------------------|\n\n");
}

int main()
{
    system("COLOR E0");
    printf("\t\t***ACTIVITY SELECTION PROBLEM***\n\n");
    int n,i;

    printf("Enter the Size of Array: ");
    scanf("%d",&n);
    int start[n];
    int end[n];

    printf("\nEnter Start Times: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&start[i]);
    }

    printf("\nEnter End Times: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&end[i]);
    }

    printf("\nStart Time: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", start[i]);
    }

    printf("\nEnd Time  : ");
    for(i=0; i<n; i++)
    {
        printf("%d ", end[i]);
    }
    printf("\n\n");

    activity_selection_problem(start,end,n);
    return 0;
}
