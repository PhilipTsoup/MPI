#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// dose not anitialize array
int *create_array(int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    return array;
}

void free_array(int *array)
{
    if (array != NULL)
    {
        free(array);
    }
}

void initialize2d_array(int **array, int n, int arg1, int arg2, int (*func)(int, int))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = func(arg1, arg2); // Call the function and assign value
        }
    }
}

// if invalid input return -1
int get_random_int(int a, int b)
{
    if (a > b)
    {
        return -1;
    }

    return a + rand() % (b - a + 1);
}

void print2d_array(int **array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Function to print a 1D array
void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}