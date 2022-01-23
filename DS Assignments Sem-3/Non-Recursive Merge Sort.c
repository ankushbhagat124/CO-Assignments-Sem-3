#include <stdio.h>
void Merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            B[k++] = a[i++];
        else
            B[k++] = a[j++];
    }
    while (i <= mid)
        B[k++] = a[i++];
    while (j <= h)
        B[k++] = a[j++];

    for (i = l; i <= h; i++)
        a[i] = B[i];
}
void mergeSort (int a[], int n)
{
    int s = 1;
    while (s < n)
    {
        for (int i = 0; i < n; i = i + 2 * s)
        {
            int l = i;
            int h = i + (2*s - 1);
            int mid = (l + h) / 2;
            if (h >= n)
            {
                h = n - 1;
            }
            Merge(a, l, mid, h);
        }
        s = 2*s;
    }
}
int main ()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter your array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, n);
    printf("SOrted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    return 0;
}

/*
#include <stdio.h>
void Merge(int Arr[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (a[i] < Arr[j])
            B[k++] = Arr[i++];
        else
            B[k++] = Arr[j++];
    }
    while (i <= mid)
    {
        B[k] = Arr[i];
        k++; i++;
    } 
    while (j <= h)
    {
        B[k] = Arr[j];
        k++; j++;
    }
    for (i = l; i <= h; i++)
        Arr[i] = B[i];
}
void mergeSort (int Arr[], int n)
{
    for (int s = 1; s < n; s = s*2)
    {
        for (int i = 0; i < n; i = i + 2 * s)
        {
            int l = i;
            int h = i + (2*s - 1);
            int mid = (l + h) / 2;
            if (h >= n)
            {
                h = n - 1;
            }
            Merge(Arr, l, mid, h);
        }
    }
}
int main ()
{
    int Arr[] = {3, 9, 2, 4, 1, 9};
    int n = sizeof(Arr)/sizeof(Arr[0]);
    mergeSort(Arr, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", Arr[i]);
    
    return 0;
}
*/