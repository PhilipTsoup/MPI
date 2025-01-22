#include <stdio.h>
#include <stdlib.h>

// returns a array NxN
int **create2d_array(int n)
{
    // Alocate collums
    int **array = malloc(n * sizeof(int *));
    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // alocate rows for eache collom
    for (int i = 0; i < n; i++)
    {
        array[i] = malloc(n * sizeof(int));
        if (array[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);
            exit(1);
        }
    }

    return array;
}

// free array NxN
void **free2d_array(int **array, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(array[i]); // free row
    }
    free(array); // free collums
}

// claclulates the sum of a Array with n values
int array_sum(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int n = 5;
    int **array = create2d_array(5);
    int test[] = {2, 3, 5, 6};
    printf("sum: %d", array_sum(test, 4));
    free2d_array(array, n);
}