#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
        return 0;
}

void Enqueue(struct queue *q, int value)
{

    if (isFull(q))
    {
        printf("Queue is Full ! \n\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int Dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty ! \n\n");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void Display(struct queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d\t", q->arr[i]);
    }
}

int main()
{

    // creating a queue
    struct queue q;
    q.size = 1000;
    q.front = 0;
    q.rear = 0;
    q.arr = (int*) malloc (sizeof(int) * (q.size));

    int initial_node = 6 ;
    int visited_array[7] = {0};


    // input the adjacency matrix 
    int adj_matrix[7][7] =
        {
            {0, 1, 0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 1, 0},
            {0, 1, 0, 1, 0, 1, 0},
            {1, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 0},
            {0, 1, 1, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 1, 0}
        };

    // enqueue the initial node
    Enqueue( &q , initial_node );
    visited_array[initial_node] = 1 ;
    printf( "%d\t" , initial_node ) ;

    // until the queue is not empty , remove visited node and traverse its all adjacent nodes and enqueue them in  the queue and after exploration of that node , dequeue it and update that visited node as 1 and print it ....
    // REPEAT THE PROCESS UNTIL THE QUEUE IS EMPTY

    while ( !isEmpty(&q) )
    {
        int dequeue_visited_node = Dequeue(&q);

        for (int i = 0 ; i < 7; i++)
        {
            if( adj_matrix[dequeue_visited_node][i] == 1 && visited_array[i] != 1 )
            {
                printf( " %d\t " , i );

                // making the visited node as 1
                visited_array [ i ]  =  1 ;

                // enqueing it into the queue
                Enqueue ( &q , i );
            }
        }
    }
}
