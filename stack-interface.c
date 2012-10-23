#include "stack-interface.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 10

/*  Clears the console and prints menu options */
void 
render_menu( void )
{
	system("cls");

	printf( "Enter a command:\n" );
	printf( "1) push [val 1] [val 2] [ ... ]\n" );
	printf( "2) pop\n" );
	printf( "3) peek\n" );
	printf( "4) print\n" );
	printf( "5) quit\n" );
}

void 
call_peek( Item **top) 
{
	Item *element = stack_peek( *top);
	if ( element == NULL )
		printf( "Stack is empty.\n" );
	else
		printf( "Top value is %s.\n", element -> data );
}

void 
call_print( Item **top )
{
	Item *current = *top;
	printf( "Stack contents:\n(Top) " );

	while ( current != NULL )
	{
		printf( "%s ", current -> data );
		current = current -> next;
	} 
	
	printf( "(Bottom)\n" );
}

void 
call_pop( Item **head ) 
{
	Item *element = stack_pop( head );
	if ( element == NULL )
		printf( "Stack is empty.\n" );
	else
		printf( "%s has been popped.\n", element -> data );
}

void 
call_push( Item **top, void *value ) 
{
	stack_push( top, value );
}

void 
init_stack( Item **stack_top )
{
	*stack_top = NULL;
}

char**
tokenize( char *str )
{
	int i = 0, j = 0, t = 0;

	// Initalize return array
	char **ret = (char ** ) malloc ( MAX_TOKENS );

	while ( str[ i ] != '\n' )
	{
		while ( str[ i ] != '\n' && isspace( str[ i ] ) )
			i++;
		
		j = i;
		while ( str[ j ] != '\n' && !isspace( str[ j ] )  )
			j++;

		ret[ t ] = ( char * ) malloc( j - i );
		strncpy( ret[ t ], str + i, j - i );
		ret[ t++ ][ j - i ] = '\0';
		i = j;

	}

	ret[ t ] = NULL;

	return ret;
}
