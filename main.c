#include <stdio.h>
#include <stdlib.h>

int hash[50], tsize, count = 0;

int Cal_Hash(int key)
{
    return key % tsize;
}

int Cal_Rehash(int key)
{
    return (key + 1) % tsize;
}

void insert(int key)
{
    int index;
    if (count != tsize)
    {
        index = Cal_Hash(key);
        while (hash[index] != -1)
            index = Cal_Rehash(index);

        hash[index] = key;
        count++;
    }
    else
        printf("Table is full");
}

int search(int key)
{
    int i, index, loc = -1;

    index = Cal_Hash(key);

    for (i = 0; i < tsize; i++)
    {
        loc = (index + i) % tsize;
        if (hash[loc] == key)
            return loc;
    }
    return -1;
}

void delete(int key)
{
    int loc;
    if (count == 0)
    {
        printf("\nHash table empty, can't delete");
    }
    else
    {
        loc = search(key);
        if (loc != -1)
        {
            hash[loc] = -1;
            count--;
            printf("\nKey deleted");
        }
        else
        {
            printf("\nKey not found");
        }
    }
}

void display()
{
    int i;
    printf("\nThe elements in the hash table are:\n");
    for (i = 0; i < tsize; i++)
        printf("Element at position %d : %d\n", i, hash[i]);
}

int main()
{
    int key, i, ch;

    printf("Enter the size of the hash table: ");
    scanf("%d", &tsize);

    for (i = 0; i < tsize; i++)
        hash[i] = -1;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("\nEnter key to search: ");
            scanf("%d", &key);
            i = search(key);
            if (i != -1)
                printf("\nKey found at location %d", i);
            else
                printf("\nKey not found");
            break;

        case 3:
            printf("\nEnter key to delete: ");
            scanf("%d", &key);
            delete(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
        }
    }
}
