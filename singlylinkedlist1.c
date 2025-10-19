#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};

int main()
{

struct node*newNode=(struct node*)malloc(sizeof(struct node));
if(newNode ==NULL)
{
    printf("Error");
}
else
{
    printf("Memory Allocated Succesfully");
}
newNode->data=10;
newNode ->next=NULL;
printf("The value in the node is %d",newNode->data);
return 0;
}
