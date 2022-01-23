#include <stdio.h>
#define sz 1000
int a[sz], n = 0;
void Heapify (int a[], int n, int i)
{
    if (i >= n)
    return;
    int left = 2*i+1;
    int right = 2*i+2;
    int index = i;
    if (left < n && a[left] < a[index])
    index = left;
    if (right < n && a[right] < a[index])
    index = right;
    if (i == index)
    return;
    if (i != index)
    {
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
        i = index;
    }
    Heapify (a, n, i);
}
void MakeHeap (int a[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        Heapify (a, n, i);
    }
}
void HeapSort (int a[], int n)
{
    MakeHeap (a, n);
    int size = n;
    for (int i = 1; i <= n-1; i++)
    {
        int temp = a[0];
        a[0] = a[size-1];
        a[size-1] = temp;
        size--;
        Heapify (a, size, 0);
    }
}
int main ()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter your Array: ");
    for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
    HeapSort (a, n);
    printf("After sorting, the array in descending order is: ");
    for (int i = 0; i < n; i++)
    printf("%d ", a[i]);

}
