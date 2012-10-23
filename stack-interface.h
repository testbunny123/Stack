#include "stack.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*  Clears the console and prints menu options */
void 
render_menu( void );

void 
call_peek( Item **top);

void 
call_print( Item **top );

void 
call_pop( Item **head );

void 
call_push( Item **top, void *value );

void 
init_stack( Item **stack_top );

char**
tokenize( char *str );
