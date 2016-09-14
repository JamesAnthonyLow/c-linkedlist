#include <stdio.h>
#include <stdlib.h>

#define NODE_STR_LEN 64

typedef struct Node {
  int data;
  struct Node * next;
} Node;

Node * newNode( int d )
{
  Node * n;
  if( ! (n = malloc( sizeof( Node ) ) ) )
    perror("Failed to allocate memory for node\n");
  n->next = NULL;
  n->data = d;
  return n;
}

void addToTail( Node * n, int d )
{
  Node * end = newNode( d );
  while( n->next != NULL )
    n = n->next;
  n->next = end;
}

int length( Node * n )
{
  if( n ) 
    return 1 + length( n->next ) ;
  return 0;
}

void nodeToBuf( Node * n, char buf[NODE_STR_LEN] )
{
  if( n ){
    snprintf( buf, 
        NODE_STR_LEN, 
        "\033[1;44mnode(\x1b[0m %d \033[1;44m) -> \x1b[0m", 
        n->data );
    nodeToBuf( n, buf + NODE_STR_LEN );
  }
}

int main()
{
  Node * list;

  list = newNode( 1 );
  addToTail( list, 2 );
  addToTail( list, 3 );
  addToTail( list, 4 );
  addToTail( list, 5 );
  addToTail( list, 6 );
  addToTail( list, 7 );
  addToTail( list, 8 );
  addToTail( list, 9 );
  addToTail( list, 10 );

  printf( "length: %d\n", length( list ));

  return 0;
}
