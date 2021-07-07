#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>
using namespace std;

template<typename Data>
class BSTNode {

	public:

		/** Constructor.  Initialize a BSTNode with the given Data item,
		 *  no parent, and no children.
		 *  TODO
		 */
		BSTNode(const Data & d):left(0),right(0),parent(0),data(d) {
			//data=d;
			//left=0;
			//right=0;
			//parent=0;
		  //left=right=parent=NULL; 
		}


		BSTNode<Data>* left;
		BSTNode<Data>* right;
		BSTNode<Data>* parent;
		Data const data;   // the const Data in this node.
		

		/** Return the successor of this BSTNode in a BST, or 0 if none.
		 *  PRECONDITION: this BSTNode is a node in a BST.
		 *  POSTCONDITION:  the BST is unchanged.
		 *  RETURNS: the BSTNode that is the successor of this BSTNode,
		 *  or 0 if there is none. TODO
		 */
		BSTNode<Data>* successor() {
			BSTNode<Data>* a=right;
			//int counter=0;
			if(a!=0)
			{
			  BSTNode<Data>* b=a->left;
			  if(!(b!=0))
			  {
				  return a;
			  }
			  while(b!=0)
			  {
                BSTNode<Data>* c=b->left;
				if(c!=0)
				{
					b=c;
				}
				else
				{
					return b;
				}
			  }
			  //return b;
			}
			else 
			{
				BSTNode<Data>* parentNode=parent;
				BSTNode<Data>* childnode=this;
				while(parentNode!=0)
				{
				  if( parentNode->left==childnode)
				  {
					  return parentNode;
				  }
				  //BSTNode<Data>* temp=childNode;
				  childnode=parentNode;
				  parentNode=parentNode->parent;
				}

			}
			return 0;
		}

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
ostream & operator<<(ostream& stm, const BSTNode<Data> & n) {
	stm << '[';
	stm << setw(10) << &n;                 // address of the BSTNode
	stm << "; p:" << setw(10) << n.parent; // address of its parent
	stm << "; l:" << setw(10) << n.left;   // address of its left child
	stm << "; r:" << setw(10) << n.right;  // address of its right child
	stm << "; d:" << n.data;               // its data field
	stm << ']';
	return stm;
}

#endif // BSTNODE_HPP
