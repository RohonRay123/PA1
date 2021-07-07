#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>
using namespace std;

template<typename Data>
class BST {

   protected:

      /** Pointer to the root of this BST, or 0 if the BST is empty */
      BSTNode<Data>* root;

      /** Number of Data items stored in this BST. */
      unsigned int isize; 

      /** Height of this BST. */
      unsigned int iheight;

   public:

      /** define iterator as an aliased typename for BSTIterator<Data>. */
      typedef BSTIterator<Data> iterator;

      /** Default constructor.
        * Initialize an empty BST.
        */
      BST() : root(0), isize(0), iheight(-1) {  }

      /** Default destructor.
        * Delete every node in this BST.
        */
      virtual ~BST() {
         deleteAll(root);
      }

      /** Given a reference to a Data item, insert a copy of it in this BST.
       *  Return  true if the item was added to this BST
       *  as a result of this call to insert,
       *  false if an item equal to this one was already in this BST.
       *  Note: This function should use only the '<' operator when comparing
       *  Data items. (should not use ==, >, <=, >=)  For the reasoning
       *  behind this, see the assignment writeup.
       *  TODO
       */
      virtual bool insert(const Data& item) {
         
               if(root==0)
               {
                  root=new BSTNode<Data>(item);
                  isize++;
                  iheight++;
                  return true;
               }
               else
               {
                  BSTNode<Data>* currentPointer=root;
                  int counter=0;
                  while(currentPointer!=0)
                  {
                     if(currentPointer->data < item)
                     {
                        //currentPointer=currentPointer->right;
                        if(currentPointer->right==NULL)
                        {
                           currentPointer->right=new BSTNode<Data>(item);
                           BSTNode<Data>* temp=currentPointer->right;
                           temp->parent=currentPointer;
                           counter++;
                           isize++;
                           if(counter> iheight)
                           {
                              iheight=counter;
                           }
                           return true;
                        }
                        currentPointer=currentPointer->right;
                        
                     }
                      else if(item < currentPointer->data)
                     {
                        // currentPointer=currentPointer->left;
                        if(currentPointer->left==NULL)
                        {
                           currentPointer->left=new BSTNode<Data>(item);
                           BSTNode<Data>* temp=currentPointer->left;
                           temp->parent=currentPointer;
                           counter++;
                           isize++;
                           if(counter> iheight)
                           {
                              iheight=counter;
                           }
                           return true;
                        }
                        currentPointer=currentPointer->left;
                     }
                     else
                     {
                        return false;
                     }
                     counter++;
                  }
                  return true;
               }
         
         return false;
      }

      /** Find a Data item in the BST.
       *  Return an iterator pointing to the item, or pointing past
       *  the last node in the BST if not found.
       *  Note: This function should use only the '<' operator when comparing
       *  Data items. (should not use ==, >, <=, >=).  For the reasoning
       *  behind this, see the assignment writeup.
       *  TODO
       */
      virtual iterator find(const Data& item) const {
         BSTNode<Data>* currentNode=root;
         while(currentNode != 0)
         {
            if(currentNode->data < item)
            {
               currentNode=currentNode->right;
            }
            else if(item < currentNode->data)
            {
               currentNode=currentNode->left;
            }
            else
            {
               return BST::iterator(currentNode);
            }
         }

         return 0; 
      }

      /** Return the number of items currently in the BST.
       *  TODO 
       */
      unsigned int size() const {
         return isize;
      }

      /** Return the height of the BST.
       * The height of an empty tree is -1 and the height of a tree
       * with only one node is 0.
       *  TODO  
       */
      unsigned int height() const {
         return iheight;
      }

      /** Return true if the BST is empty, else false.
       */
      bool empty() const {
         return isize == 0;
      }

      /** Return an iterator pointing to the first item in the BST (not the root).
       */
      iterator begin() const {
         return BST::iterator(first(root));
      }

      /** Return an iterator pointing past the last item in the BST.
       */
      iterator end() const {
         return typename BST<Data>::iterator(0);
      }

      /** Inorder traverse BST, print out the data of each node in ascending order.
       * Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
       * Pseudo Code:
       * if current node is null: return;
       * recursively traverse left sub-tree
       * print current node data
       * recursively traverse right sub-tree
       * TODO
       */
      void inorder() const {
         inorder(root);
      }
   

   private:

     void inorder(BSTNode<Data>* n) const
     {
        if(n!=0)
        {
           inorder(n->left);
           cout<< n->data << endl;
           inorder(n->right);
           
        }
        else
        {
           return;
        }
     }

      /** Find the first element of the BST
       *  TODO 
       */ 
      static BSTNode<Data>* first(BSTNode<Data>* root) {
         BSTNode<Data>* tracker=root;
         while(tracker != NULL)
         {
            if(tracker->left!=0)
            {
               tracker=tracker->left;
            }
            else
            {
               return tracker;
            }
         }
         return 0;
      }

      /** do a postorder traversal, deleting nodes
       *   TODO   
       */
      static void deleteAll(BSTNode<Data>* n) {
         /* Pseudo Code:
            if current node is null: return;
            recursively delete left sub-tree
            recursively delete right sub-tree
            delete current node
            */
           if(n!=0)
           {
              deleteAll(n->left);
              deleteAll(n->right);
              delete n;
           }
           else
           {
              return;
           }

         

      }

};

#endif //BST_HPP
