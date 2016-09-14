###LinkedLists 9/14/2016

Adding to the list:

```c
void addToTail( Node * n, int d )
{
  Node * end = newNode( d );
  while( n->next != NULL )
    n = n->next;
  n->next = end;
}
```

Deleting a node in the list:
```c
void deleteNode( Node * n, int d )
{
  Node * t;
  if( ! ( n && n->next ) )
    return perror("Node not found\n");
  if( n->next->data != d )
    return deleteNode( n->next, d );
  t = n->next;
  n->next = n->next->next;
  free( t );
}
```
