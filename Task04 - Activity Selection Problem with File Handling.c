#include<stdio.h>
#include<stdlib.h>

FILE *Start_EndTimeInput, *ASP_OUTPUT;

void activity_selection_problem(int start[], int end[], int size)
{
    int i=0,j=0;
    ASP_OUTPUT = fopen("ASP_OUTPUT.txt","w");
    printf("\nFollowing Activities are Selected: ");
    printf("0 ");
    fprintf(ASP_OUTPUT,"Selected Activities are: %d\t",j);

    for(j=1;j<size;j++)
        if(start[j] >= end[i])
          {
            printf("%d ",j);
            fprintf(ASP_OUTPUT,"%d\t",j);
            i = j;
          }
          printf("\n");
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

    Start_EndTimeInput = fopen("Start&EndTimeInput.txt", "w");
    for(i=0;i<n;i++)
    {
        fprintf(Start_EndTimeInput, "Start Time: %d\t End Time: %d\n", start[i],end[i]);
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
