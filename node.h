#ifndef NODE_H
#define NODE_H

typedef struct Node {
  int data;
  struct Node * next;
  int ( *length )( struct Node * );
  void ( *print )( struct Node * );
  void ( *free )( struct Node * );
} Node;

extern void addToTail( Node * n, int d );
extern Node * newNode( int d );

#endif
