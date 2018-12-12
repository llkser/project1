#include "treeStructure.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

//recursively destroy the whole tree

void destroyTree( Node *head ){
    if( head->child[0] == NULL )
        free(head);
    else {
        for ( int i=0; i<4; ++i ) {
            destroyTree( head->child[i] );
    }
}
}
//remove children from a node

void removeChildren( Node *parent ){
    for ( int i=0; i<4; ++i ) {
        free( parent->child[i] );
        parent->child[i]=NULL;
    }
}
