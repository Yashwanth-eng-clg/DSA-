#include <stdio.h>
#include <stdlib.h>

void heapify(int h[], int n)
{
    int i, j, k, v, heap;

    for(i = n/2; i >= 1; i--)
    {
        k = i;
        v = h[k];
        heap = 0;

        while(!heap && 2*k <= n)
        {
            j = 2*k;

            if(j < n && h[j] < h[j+1])
                j = j + 1;

            if(v >= h[j])
                heap = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

void heapsort(int h[], int n)
{
    int i, temp;

    for(i = n; i > 1; i--)
    {
        temp = h[1];       // swap root with last element
        h[1] = h[i];
        h[i] = temp;

        heapify(h, i - 1); // rebuild heap
    }
}

int main()
{
    int i, n, h[10];

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &h[i]);

    heapify(h, n);

    printf("Heap elements: ");
    for(i = 1; i <= n; i++)
        printf("%d ", h[i]);

    heapsort(h, n);

    printf("\nSorted elements: ");
    for(i = 1; i <= n; i++)
        printf("%d ", h[i]);

    return 0;
}
