#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void deleteNode( Node * n, int d )
{
  Node * t;
  if( ! ( n && n->next ) ){
    perror("Node not found\n");
    return;
  }
  if( n->next->data != d )
    return deleteNode( n->next, d );
  t = n->next;
  n->next = n->next->next;
  free( t );
}

int main()
{
  Node * list;

  list = newNode( 0 );
  addToTail( list, 1 );
  addToTail( list, 2 );
  addToTail( list, 3 );
  addToTail( list, 4 );
  addToTail( list, 5 );
  addToTail( list, 6 );
  addToTail( list, 7 );
  addToTail( list, 8 );
  addToTail( list, 9 );
  addToTail( list, 10 );

  printf( "length: %d\n", list->length( list ) );

  deleteNode( list, 3);

  list->print( list );

  list->free( list );

  return 0;
}
