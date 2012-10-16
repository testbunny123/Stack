#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define MAX_TOKENS 10
#define BUFSIZE 80

/*  Clears the console and prints menu options */
static void 
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
		printf( "Top value is %d.\n", element -> data );
}

void 
call_print( Item **top )
{
	Item *current = *top;
	printf( "Stack contents:\n(Top) " );

	while ( current != NULL )
	{
		printf( "%d ", current -> data );
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
		printf( "%d has been popped.\n", element -> data );
}

void 
call_push( Item **top, void **value ) 
{
	stack_push( top, value );
}

void 
init_stack( Item **stack_top )
{
	*stack_top = NULL;
}

static
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

int 
main() 
{
	render_menu();
	printf( "\n>" );

	Item *stack_top;
	init_stack( &stack_top );

	void ( *call_command[] ) ( Item **, void ** ) = { call_push, call_pop, call_peek, call_print };
	size_t total_commands = sizeof( call_command ) / sizeof( call_command[ 0 ] );

	char input[ BUFSIZE ];
	while ( fgets( input, BUFSIZE, stdin ) )
	{
		/*// Check if valid command*/
		/*if ( input > total_commands ) */
		/*continue;*/

		/*// Check if command is quit*/
		/*if ( input == total_commands ) */
		/*break;*/
		
		// Parse the valid input
		char **ret = tokenize( input );

		int cmd, i = 1;
		if ( !strcmp( ret[0], "push" ) )
		{
			cmd = 0;
			for ( i = 1; ret[ i ] != NULL; i++ )
				( *call_command[ cmd ] ) ( &stack_top, ret[ i ] );	
		}
		else
		{
			if ( !strcmp( ret[ 0 ], "pop" ) )
				cmd = 1;
			else if ( !strcmp( ret[ 0 ], "peek" ) )
				cmd = 2;
			else if ( !strcmp( ret[ 0 ], "print" ) )
				cmd = 3;
			else if ( !strcmp( ret[ 0 ], "quit" ) )
				break;
			else
			{
				printf( "Please enter valid input.\n" );
				continue;
			}

			( *call_command[ cmd ] ) ( &stack_top, 0 );	
		}

		printf( "\n> " );
	}
}
