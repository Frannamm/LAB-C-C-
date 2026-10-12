#include <stdio.h>
#include <stdlib.h>

void CreateString ( char **str ){

    *str = ( char *) malloc ( 100 * sizeof ( char ) );
    if ( *str == NULL ) {
        printf ( "Memory allocation failed\n" );
        exit ( 1 );
    }

    fgets ( *str, 100, stdin ); // Read the phrase from the user

}

int String ( char *str ){

    int l=0;
    while ( str[l] != '\0' ) {
        l++;
    }
    return l;

}

int CountWords ( char *str ){

    int count = 0;
    int inWord = 0;

    for ( int i = 0; str[i] != '\0'; i++ ) {
        if ( str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ) {
            inWord = 0;
        } else if ( inWord == 0 ) {
            inWord = 1;
            count++;
        }
    }

    return count;

} 

int main () {

    char *str = NULL;
    CreateString ( &str );

    int length = String ( str );
    int wordCount = CountWords ( str );

    printf ( "Length of the string: %d\n", length );
    printf ( "Number of words in the string: %d\n", wordCount );

    free ( str ); // Free the allocated memory
    return 0;

}

