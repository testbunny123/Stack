
typedef struct Item 
{  
	void **data;  
	struct Item *next;  
} Item;

int 
stack_push( Item **p_top, void *value );

Item *
stack_pop( Item **p_top );

Item *
stack_peek( Item *top );

void 
stack_print( Item *top );

int 
size( Item *top );

