#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "buildTree.h"
#include "writeTree.h"
#include "treeStructure.h"

// main

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  growTree(head);
  growTree(head);

  // print the tree for Gnuplot
  writeTree( head );

  destroyTree( head );
  return 0;
}
