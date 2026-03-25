#include <stdio.h>
#include <stdlib.h>

int count;

int partition(int a[10], int l, int r)
{
    int i, j, temp, pivot;
    pivot = a[l];
    i = l + 1;
    j = r;
    while(1)
    {
            while (i <= r &&  pivot >= a[i])
            {
                count++;
                i++;
            }
            while (j >+ 1 && pivot < a[j])
            {
                count++;
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else
            {
                temp = a[l];
                a[l] = a[j];
                a[j] = temp;
                return j;
            }
    }
}
void quick_sort(int a[10], int l, int r)
{
    int s;
    if (l < r)
    {
        s = partition (a, l, r);
        quick_sort(a, l, s-1);
        quick_sort(a, s + 1, r);
    }
}

int main()
{
    int i, n, a[10];
    printf("\nRead Array size: ");
    scanf("%d", &n);
    printf("\nRead array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(a, 0, n - 1);

    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\nTotal number of comparisons = %d\n", count);
    return 0;
}

