#include <stdio.h>
#define size 1000
int a[size], n=0;
void Insert (int a[], int *n, int x)
{
    a[*n] = x;
    *n = *n+1;
    int i = *n-1;
    while (i > 0)
    {
        int parent = (i-1)/2;
        if (a[i] > a[parent])
        {
            int temp = a[i];
            a[i] = a[parent];
            a[parent] = temp;
            i = parent;
        }
        else
        break;
    }
}
int Delete (int a[], int *n)
{
    int x = a[0];
    a[0] = a[*n-1];
    *n = *n-1;
    int i = 0;
    while (1)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int largestindex = i;
        if (left < *n && a[left] > a[largestindex])
        largestindex = left;
        if (right < *n && a[right] > a[largestindex])
        largestindex = right;
        if (largestindex == i)
        break;
        else
        {
            int temp = a[i];
            a[i] = a[largestindex];
            a[largestindex] = temp;
            i = largestindex;
        }
    }
    return x;
}
void Display (int a[], int *n)
{
    printf("Max Heap contents are: ");
    for (int i = 0; i < *n; i++)
    printf("%d ", a[i]);
}
int main ()
{
    int choice=0;
    int x, ele;
    while (choice != 4)
    {
        printf("\nMENU:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            Insert (a, &n, x);
            break;
            case 2:
            ele = Delete (a, &n);
            printf("Element deleted is : %d", ele);
            break;
            case 3:
            Display (a, &n);
            break;
            default:
            break;
        }
    }
}
