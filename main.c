#include <stdio.h>
#include <stdlib.h>

int count = 0;

void bubblesort(int a[10], int n)
{
    int i, j, temp;
    for(i = 0; i <= n-2; i++)
    {
        for(j = 0; j <= n-2-i; j++)
        {
            count++;   // comparison count
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[10], n, i;

    printf("Read array size: ");
    scanf("%d", &n);

    printf("Read array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bubblesort(a, n);

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nTotal number of comparisons = %d", count);

    return 0;
}
