#include <stdio.h>
#define size 100
struct queue
{
    int arr[size];
    int front, rear;
};
void Enque (struct queue *q, int x)
{
    if ((q->rear+1)%size == q->front)
    printf("Queue is Full.");
    else
    {
        q->arr[q->rear] = x;
        q->rear = (q->rear + 1)%size;
    }
}
int Deque (struct queue *q)
{
    int y;
    if (q->rear == q->front)
    {
        printf("Queue is Empty.");
        y = -1;
    }
    else
    {
        y = q->arr[q->front];
        q->front = (q->front+1)%size;
    }
    return y;
}

void display (struct queue q)
{
    int i;
    if (q.rear == q.front)
    return;

    i = q.front;
    printf("Elements are: ");
    do
    {
        printf("%d ", q.arr[i]);
        i = (i+1)%size;
    } while (i != q.rear);
    printf("\n");

}
int main ()
{
    struct queue q;
    int x, option;
    q.rear = 0;
    q.front = 0;
    do
    {
        printf("\nMENU Options:\n");
        printf("1.Enque\n");
        printf("2.Deque\n");
        printf("3.Display\n");
        printf("4.EXIT\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d", &x);
                    Enque(&q, x);
                    break;
            case 2: x = Deque(&q);
                    if (x == -1)
                        printf("%d is deleted.", x);
                    break;
            case 3: display(q);
                    break;
        }
    }while (option != 4);

}
