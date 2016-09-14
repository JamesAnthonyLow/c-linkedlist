#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

#define NODE_STR_LEN 64

int nodeLength( Node * n );
void printNode( Node * n );
void nodeToBuf( Node * n, char * buf );
void freeNode( Node * n );

Node * newNode( int d )
{
  Node * n;
  if( ! (n = malloc( sizeof( Node ) ) ) )
    perror("Failed to allocate memory for node\n");
  n->next = NULL;
  n->data = d;
  n->length = nodeLength;
  n->print = printNode;
  n->free = freeNode;
  return n;
}

void freeNode( Node * n )
{
  if( n ){
    free( n );
    freeNode( n->next );
  }
}

int nodeLength( Node * n )
{
  if( n ) 
    return 1 +  nodeLength( n->next ) ;
  return 0;
}

void addToTail( Node * n, int d )
{
  Node * end = newNode( d );
  while( n->next != NULL )
    n = n->next;
  n->next = end;
}

void nodeToBuf( Node * n, char * buf )
{
  if( n ){
    sprintf( buf, 
        "\033[1;44mnode(\x1b[0m %d \033[1;44m) -> \x1b[0m", 
        n->data );
    nodeToBuf( n->next , buf + strlen(buf) );
  }
}

void printNode( Node * n )
{
  char * buf; 
  if( ! (buf = malloc( NODE_STR_LEN * n->length( n ) ) ) )
    perror("Failed to allocate memory for Node buffer\n");
  nodeToBuf( n, buf );
  printf( "%s\n", buf );
  free( buf );
}


