#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arr_lenght(int *arr);
void add(int *x, int var);

typedef struct {
    int size;
    int *content; 
} DynamicIntArr;

void add_to_struct(DynamicIntArr *d, int value);
void remove_from_struct(DynamicIntArr *d, int value);

int *test;

int main() {
    DynamicIntArr* dArr = (DynamicIntArr*) malloc(sizeof(DynamicIntArr));
    
    // test = (int*) malloc(size * sizeof(int));

    // add(test, 1);
    // add(test, 2);
    // add(test, 3);
    // add(test, 4);
    // add(test, 5);
    // add(test, 6);
    // add(test, 7);

    // free(test);
    
    add_to_struct(dArr, 12);
    add_to_struct(dArr, 13);
    add_to_struct(dArr, 14);
    add_to_struct(dArr, 15);
    add_to_struct(dArr, 16);
    add_to_struct(dArr, 17);
    add_to_struct(dArr, 18);
    add_to_struct(dArr, 19);
    add_to_struct(dArr, 11);
    add_to_struct(dArr, 10);
    add_to_struct(dArr, 1);
    add_to_struct(dArr, 2);

    remove_from_struct(dArr, 3);

    free(dArr->content);
    dArr->content = NULL;

    free(dArr);
    dArr = NULL;
    return 0;
}

void add(int *x, int val) {
    int *temp;
    int size = 5;
    if (x == NULL) {
        //error handling
        printf("x is null");
        exit(1);
    }

    int count = arr_lenght(x);
    printf("Count value is: %d\n", count);

    if (count == size - 2) {
        size *= 2;
        temp = realloc(test, size);
        if (temp == NULL) {
            printf("Reallocation failure. Exiting..");
            free(temp);
            free(x);
            exit(1);
        } else {
            x = temp;
        }
        
        printf("Space reallocated, size is now %d\n", size);
    }
    
    *(x + count) = val;
    printf("Value on index: %d is %d\n", count+1, *(x+count));
}

void add_to_struct(DynamicIntArr *d, int value) {
    int *tmp;

    if (d == NULL) {
        printf("Struct pointer is null.");
        exit(1);
    }

    d->size = 5;

    if (d->content == NULL) {
        d->content = malloc(d->size * sizeof(int));
    }

    int len = arr_lenght(d->content); 

    if ((d->size - 2) == len) {
        tmp = realloc(d->content, (d->size *= 2));
        if (tmp == NULL) {
            printf("Reallocation failure.\n");
            free(d->content);
            d->content = NULL;
            free(d);
            d = NULL;
            exit(1);
        }

        d->content = tmp;
    }

    d->content[len] = value;  
    printf("Content lenght: %d and value %d\n", len, d->content[len]);
}

void remove_from_struct(DynamicIntArr *d, int ind) {

    //initial arr value:

    for (size_t i = 0; i < d->size; i++)
    {
        printf("Size of array before remove: %d\n", d->size);
        printf("Value %d\n", d->content[i]);
    }
    

    //remove element from index
    if (d == NULL || d->content == NULL)
    {
        exit(1);
    }

    int cont = arr_lenght(d->content);

    if ((ind+1) > d->size)
    {
        printf("Index out of bound for array.\n");
        exit(1);
    }
    
    if (ind < 0 || cont == 0)
    {
        printf("invalid index!\n");
        exit(1);    
    }

    //left shift the rest of the elements
    int upd = cont - (ind + 1);
    
    for (size_t i = ind; i < upd; i++)
    {
        if ((i + 1) < upd)
        {
            d->content[i] = d->content[i + 1];    
        }
    }

    --cont;
    
    //reallocate if needed
    if (cont * 2 == d->size)
    {
        //realloc down
        d->size = d->size / 2;
        // realloc7()
    }
    

    //print array
    for (size_t i = 0; i < cont; i++)
    {
        printf("Element on index %d is %d\n", i, d->content[i]);
    }
    
}

int arr_lenght(int *arr) {
    int count = 0;
    for (int i = 0; *(arr + i) != '\0'; i++) {
        count++;
    }
    return count;
}