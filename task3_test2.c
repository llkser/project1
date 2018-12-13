#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "buildTree.h"
#include "writeTree.h"
#include "treeStructure.h"
#include "nodeValue.h"
// count of how many nodes are added and how many are removed during task3_stage 2
int nodeAdded,nodeRemoved;
// main

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );
  nodeAdded=nodeRemoved=0;

  // make a tree
  growTree(head);
  growTree(head);
  growTree(head);
  adapt(head);
  printf("Nodes added: %d\n",nodeAdded);
  printf("Nodes removed: %d\n",nodeRemoved);

  // print the tree for Gnuplot
  writeTree( head );

  //free the whole tree
  destroyTree(head);

  return 0;
}
