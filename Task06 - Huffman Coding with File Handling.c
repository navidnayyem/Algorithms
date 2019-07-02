#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *Input, *Output;

typedef struct node
{
    char ch;
    int freq;
    struct node *left;
    struct node *right;
}node;

node * heap[100];
int heapSize=0;

void Insert(node * element)
{
    heapSize++;
    heap[heapSize] = element;
    int now = heapSize;
    while(heap[now/2] -> freq > element -> freq)
    {
            heap[now] = heap[now/2];
            now /= 2;
    }
    heap[now] = element;
}

node * DeleteMin()
{
    node * minElement,*lastElement;
    int child,now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for(now = 1; now*2 <= heapSize; now = child)
    {
        child = now*2;

        if(child != heapSize && heap[child+1]->freq < heap[child] -> freq )
        {
            child++;
        }

        if(lastElement -> freq > heap[child] -> freq)
        {
            heap[now] = heap[child];
        }
        else
        {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}

void print(node *temp,char *code)
{
    if(temp->left==NULL && temp->right==NULL)
        {
            printf("Character [%c] Code = %s\n",temp->ch,code);
            fprintf(Output,"Character [%c] Code = %s\n",temp->ch,code);
            return;
        }
    int length = strlen(code);
    char leftcode[10],rightcode[10];
    strcpy(leftcode,code);
    strcpy(rightcode,code);
    leftcode[length] = '0';
    leftcode[length+1] = '\0';
    rightcode[length] = '1';
    rightcode[length+1] = '\0';
    print(temp->left,leftcode);
    print(temp->right,rightcode);
}

int main()
{
    system("COLOR F0");
    int i,n,freq;
    char ch;
    printf("*** HUFFMAN CODING ***");
    heap[0] = (node *)malloc(sizeof(node));
    heap[0]->freq = 0;

    printf("\n\nEnter the Number of Characters: ");
    scanf("%d",&n);
    printf("\nEnter the Characters with their Frequencies Below\n\n");

    Input = fopen("HUFFMAN_CODING_INPUT.txt", "w");
    for(i=0;i<n;i++)
    {
        printf("Character %d: ",i,ch);
        scanf(" %c",&ch);
        printf("Frequency of %c: ",ch);
        scanf("%d",&freq);
        fprintf(Input, "Character %d: %c\t Frequency of %c: %d\n",i,ch,ch,freq);
        printf("\n");
        node * temp = (node *) malloc(sizeof(node));
        temp -> ch = ch;
        temp -> freq = freq;
        temp -> left = temp -> right = NULL;
        Insert(temp);
    }
    printf("\n");

    Output = fopen("HUFFMAN_CODING_OUTPUT.txt","w");
    if(n==1)
    {
        printf("Character [%c] Code = 0\n",ch);
        fprintf(Output,"Character [%c] Code = 0\n",ch);
        return 0;
    }

    for(i=0;i<n-1;i++)
    {
        node * left = DeleteMin();
        node * right = DeleteMin();
        node * temp = (node *) malloc(sizeof(node));
        temp -> ch = 0;
        temp -> left = left;
        temp -> right = right;
        temp -> freq = left->freq + right -> freq;
        Insert(temp);
    }
    node *tree = DeleteMin();
    char code[10];
    code[0] = '\0';
    print(tree,code);
}
