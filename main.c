#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack-interface.h"

#define BUFSIZE 80

int 
main() 
{
	render_menu();
	printf( "\n> " );

	Item *stack_top;
	init_stack( &stack_top );

	void ( *call_command[] ) ( Item **, void * ) = { call_push, call_pop, call_peek, call_print };
	size_t total_commands = sizeof( call_command ) / sizeof( call_command[ 0 ] );

	char input[ BUFSIZE ];
	while ( fgets( input, BUFSIZE, stdin ) )
	{
		// Parse the valid input
		char **ret = tokenize( input );

		int cmd; 
		if ( !strcmp( ret[0], "push" ) )
		{
			int i = 1;
			cmd = 0;
			for ( i = 1; ret[ i ] != NULL; i++ )
				( *call_command[ cmd ] ) ( &stack_top, ret[ i ] );	

			if ( i == 1 )
				printf( "Please enter valid values to push.\n" );
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
				printf( "> " );
				continue;
			}

			( *call_command[ cmd ] ) ( &stack_top, 0 );	
		}

		printf( "\n> " );
	}
}
