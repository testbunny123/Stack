#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Item *
stack_pop( Item **p_top )
{
	if ( *p_top == NULL)
		return NULL;

	Item *top = *p_top;
	*p_top = top -> next;
	return top;
}

int 
stack_push( Item **top, void **value )
{
	Item *new = ( Item * ) malloc( sizeof ( Item ) );
	new -> data = value;
	new -> next = *top;
	*top = new;
}

Item *
stack_peek( Item *top )
{
	return top;
}

int 
size( Item *top)
{
	int count;
	while ( top != NULL )
	{
		count++;
		top = top -> next;
	}
}
