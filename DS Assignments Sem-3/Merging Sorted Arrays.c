#include <stdio.h>
void mergeArrays(int a1[], int a2[], int len1, int len2)
{
    int ans[len1+len2];
    int i = 0, j = 0, k = 0;
    while (i<len1 && j <len2)
    {
        if (a1[i] < a2[j])
            ans[k++] = a1[i++];
        else
            ans[k++] = a2[j++];
    }

    while (i < len1)
        ans[k++] = a1[i++];
 
    while (j < len2)
        ans[k++] = a2[j++];
        
    printf("\nOUTPUT\n");
    
    for (int i=0; i < len1+len2; i++)
        printf("%d ", ans[i]);
}
int main()
{
    int a1[] = {1, 5, 10, 15, 20};
    int a2[] = {1, 4, 6, 13};
    int len1 = sizeof(a1)/sizeof(a1[0]);
    int len2 = sizeof(a2)/sizeof(a2[0]);
 
    mergeArrays(a1, a2, len1, len2);
    return 0;
}