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
  makeChildren(head->child[1]);
  makeChildren(head->child[2]);
  makeChildren(head->child[3]);
  removeChildren(head->child[1]);

  // print the tree for Gnuplot
  writeTree( head );

  //free the whole tree
  destroyTree(head);

  return 0;
}

