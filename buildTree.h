#include "treeStructure.h"
//functions that create or change the tree

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growTree( Node *head );
void destroyTree( Node *head );
void removeChildren( Node *parent );

