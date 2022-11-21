#include <stdio.h>
#include <stdlib.h>
struct queue{
    int capacity;
    int front;
    int rear;
    int *array;
};
int isEmpty(struct queue *s1){
    if((s1->front==-1) &&(s1->rear==-1)){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *s1){
    if(((s1->rear==(s1->capacity)-1) &&(s1->front==0))||(s1->front==(s1->rear)+1)){
        return 1;
    }
    else{
        return 0;
    }
}
void insert(struct queue *s1,int p){
    if(!(isFull(s1))){
        if((s1->front==-1) && (s1->rear==-1)){
            s1->front=0;
            s1->rear=0;
            s1->array[s1->rear]=p;
        }
        else if((s1->rear)==((s1->capacity)-1)){
            
            s1->rear=0;
            s1->array[s1->rear]=p;
        }
        else{
            s1->rear=((s1->rear)+1);
            s1->array[s1->rear]=p;
        }
    }
    else{
        printf("Full");
    }
    
}
//this is for deletionn
int delete(struct queue *s1){
    if(!(isEmpty(s1))){
        if((s1->front==s1->rear)){
            int temp=s1->array[s1->front];
            s1->array[s1->front]='\0';
            s1->front=-1;
            s1->rear=-1;
            return temp;
        }
        else if((s1->front)==(s1->capacity)-1){
            int temp=s1->array[s1->front];
            s1->array[s1->front]='\0';
            s1->front=0;
            return temp;

        }
        else{
            int temp=s1->array[s1->front];
            s1->array[s1->front]='\0';
            s1->front=(s1->front)+1;
            return temp;
        }
    }
}
//display thie bfs traversal
void display(int n,int a[n][n],struct queue* s1,int status[n]){
    printf("Your graph: ");
    int i1=0;
    printf("v%d ",i1+1);
    status[0]=1;
    insert(s1,i1);
    while(!isEmpty(s1)){
        int node =delete(s1);
        for(int j=0;j<n;j++)
        {
            if(a[node][j]==1 && status[j]==0){
                printf("v%d ",j+1);
                status[j]=1;
                insert(s1,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(status[i]==0){
            printf("v%d ",i+1);
        }
    }
}

int main(){
int n;
printf("Enter number of vertices");
scanf("%d",&n);
int path[n][n];
struct queue *s1 = (struct queue*) malloc(sizeof(struct queue));
s1->capacity=n;
s1->front=-1;
s1->rear=-1;
s1->array=(int *)malloc(s1->capacity*sizeof(int));
int c;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("Any edge from vertice %d and %d: ",(i+1),(j+1));
        scanf("%d",&c);
        if(c==1){
            path[i][j]=1;
        }
        else{
            path[i][j]=0;
        }
        }
    }
printf("Your Adjacency Matrix: \n");
printf("   ");
for(int i=1;i<=n;i++){
    printf("v%d ",i);
    }
printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                printf("v%d ",(i+1));
            }
            printf("%d  ",path[i][j]);
            }
        printf("\n");
        }
    int status[n];
    for(int i=0;i<n;i++){
        status[i]=0;
    }
    //status means visited
    display(n,path,s1,status);
}



