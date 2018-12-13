#include "treeStructure.h"
#include "nodeValue.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

// Set nodeValue for every leaf node

void SetnodeValue( Node *head ){

  int i;
  if( head->child[0] == NULL&&head->child[1] == NULL&&head->child[2] == NULL&&head->child[3] == NULL ){
        if(nodeValue( head,0.0 )>0.5)
            head->flag=1;
        else if(nodeValue( head,0.0 )<0.5)
            head->flag=-1;
  }
  else
        for(i=0;i<4;i++)
            SetnodeValue( head->child[i] );
}

// Change the tree by its leaf nodes' flag value

void changeTree( Node *head ){
    extern int nodeAdded,nodeRemoved;
    int i;
    if( head->child[0] == NULL&&head->child[1] == NULL&&head->child[2] == NULL&&head->child[3] == NULL ){
        if( head->flag==1&&head->level<6 ){
            makeChildren(head);
            nodeAdded+=4;
        }
    }
    else{
        if( head->child[0]->flag == -1&&head->child[1]->flag == -1&&head->child[2]->flag == -1&&head->child[3]->flag == -1 ){
            removeChildren(head);
            nodeRemoved+=4;
        }
        else{
            for(i=0;i<4;i++)
                changeTree( head->child[i] );
        }
    }
}

void adapt( Node *head ) {
    extern int nodeAdded,nodeRemoved;
    int i,x;

    x=-1;
    while(x!=nodeAdded)
    {
        x=nodeAdded;
        SetnodeValue(head);
        changeTree(head);
    }
    SetnodeValue(head);
}
