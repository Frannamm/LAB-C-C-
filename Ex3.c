// ***** Resizing a dynamic array using Realloc ***** //

#include <stdio.h>
#include <stdlib.h>

void CreateArray ( int **arr, int n ) {

    *arr = ( int * ) malloc ( n * sizeof ( int ) );
    if ( *arr == NULL ) {
        printf ( "Memory allocation failed\n" );
        exit ( 1 );
    }

    for ( int i = 0; i < n; i++ ) {
        printf ( "Enter element %d: ", i + 1 );
        scanf ( "%d", &(*arr)[i] );
    }

}

void ResizeArray ( int **arr, int *n ) {

    int newSize;
    printf ( "Enter new size of the array: " );
    scanf ( "%d", &newSize );

    if ( newSize <= 0 ) {
        printf ( "Size of the array must be positive.\n" );
        exit ( 1 );
    }

    int *temp = ( int * ) realloc ( *arr, newSize * sizeof ( int ) );
    if ( temp == NULL ) {
        printf ( "Memory reallocation failed\n" );
        exit ( 1 );
    }

    *arr = temp;

    for ( int i = *n; i < newSize; i++ ) {
        printf ( "Enter element %d: ", i + 1 );
        scanf ( "%d", &(*arr)[i] );
    }

    *n = newSize;

}

int main () {

    int n;
    printf ( "Enter the size of the array: " );
    scanf ( "%d", &n );

    if ( n <= 0 ) {
        printf ( "Size of the array must be positive.\n" );
        return 1;
    }

    int *arr = NULL;
    CreateArray ( &arr, n );

    printf ( "\nArray elements:\n" );
    for ( int i = 0; i < n; i++ ) {
        printf ( "|\t%d\t", arr[i] );
    }
    printf ( "|");
    printf ( "\n" );

    ResizeArray ( &arr, &n );

    printf ("\nResized array elements:\n");
    for ( int i = 0; i < n; i++ ) {
        printf ( "|\t%d\t", arr[i] );
    }
    printf ( "|");
    printf ( "\n" );
    
    free(arr);  // Free the allocated memory
    return 0;

}
