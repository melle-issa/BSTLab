#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

class BSTree {
private:
   //Node *root;
   int size;
   //void increaseSize();
   //vector<Node*> elements;
public:
   /* Constructors */
   /* Default constructor */
   Node* root;
   BSTree();
   //~BSTree();
   void insert(const string &newString);
   /* Remove a specified string from the tree. 
      Be sure to maintain all bianry search tree properties. 
      If removing a node with a count greater than 1, just decrement the count, otherwise, 
      if the count is simply 1, remove the node. 
      You MUST follow the remove algorithm shown in the slides and discussed in class or else 
      your program will not pass the test functions. 
      When removing, 
            if removing a leaf node, simply remove the leaf. Otherwise, 
            if the node to remove has a left child, replace the node to remove with the largest 
            string value that is smaller than the current string to remove 
            (i.e. find the largest value in the left subtree of the node to remove). 
            If the node has no left child, replace the node to remove with the smallest value 
            larger than the current string to remove 
            (i.e. find the smallest value in the right subtree of the node to remove. 
   */
   void remove(const string &key);
   bool search(const string &key) const;
   
   string largest() const;
   string smallest() const;

   /* Compute and return the height of a particular string in the tree. 
      The height of a leaf node is 0 (count the number of edges on the longest path). 
      Return -1 if the string does not exist. 
   */
   int height(const string &) const;
   int getHeight(Node* ) const;
   
   bool isTreeEmpty();

   void preOrder() const;
   void preOrder(Node* ) const;
   
   void postOrder(Node* )const;
   void postOrder() const;
   
   void inOrder() const;
   void inOrder(Node* ) const;

   //Node* toReplace();

   void PrintTree();



   
};

#endif 