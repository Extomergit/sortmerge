#include <stdio.h>
#include <stdlib.h>


void insertion_sort(long int * v, long int n)
{

    long int i, j, auxil, x;

    for(i=+1; i<=n; i++)
    {
        x = v[i];
        j = i;
        while(x < v[j-1] && j > 0)
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = x;
    }
}

void merge_sort(int i, int j, int a[], int auxil[]) 
{
    if (j <= i)
    {
        return;
    }
    int mid = (i + j) / 2;

    if(a[mid] <= a[mid + 1])
    {
        return;
    }

    if ((j+i) <= 15) 
    {
        insertion_sort(a, j);
        return;
    }

    merge_sort(i, mid, a, auxil);

    merge_sort(mid + 1, j, a, auxil);

    int left = i;
    int right = mid + 1;
    int k;


    for (k = i; k <= j; k++) 
    {

        if (left == mid + 1) 
        {
            auxil[k] = a[right];
            right++;
        } 
        else if (right == j + 1) 
        {
            auxil[k] = a[left];
            left++;
        } 
        else if (a[left] < a[right]) 
        {
            auxil[k] = a[left];
            left++;
        } 
        else 
        {
            auxil[k] = a[right];
            right++;
        }
    }

    for (k = i; k <= j; k++) 
    {
        a[k] = auxil[k];
    }
}

int main() 
{
    int *a, n, i;

    printf("Quantos numeros existem no array? \n\n");
    scanf("%d", &n);

    a = (int *) malloc(sizeof(int) * n);

    printf("Somente valores int: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    merge_sort(0, n - 1, a, a);

    printf("Ordenação do vetor:\n\n");

    for (i = 0; i < n; i++) 
    {
        printf("%d\n", a[i]);
    }


    return 0;
}
