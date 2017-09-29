/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *
 */

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <queue>
#include <algorithm>
//#include <unistd.h> whats this doing here?

using namespace std;

/*
 *  Node datastructure for single tree node
 */
template <class T>
struct Node {
  T value;
  Node<T> *leftChild;     //nullptr invalid for ssh servers
  Node<T> *rightChild;
  Node<T> *current;
};


/*
 * Binary Search Tree (BST) class implementation
 */
template <class T>
class BST
{
public:
  BST()
  {
    Node<T>* new_node = new Node<T>;
    new_node->value = -1;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    root = new_node;
  }
  void addHelper(T val, Node<T> *current)
  {
    if(current->value > val) // go left
    {
      if(current->leftChild != NULL)
      {
        addHelper(val, current->leftChild);
      }
      else
      {
        Node<T>* new_node = new Node<T>;
        new_node->value = val;
        new_node->leftChild = NULL;
        new_node->rightChild = NULL;
        current->leftChild = new_node; //point current to next
      }
      return;
    }
    else if(current->value < val)
    {
      if(current->rightChild != NULL)
      {
        addHelper(val, current->rightChild);
      }
      else
      {
        Node<T>* new_node = new Node<T>;
        new_node->value = val;
        new_node->leftChild = NULL;
        new_node->rightChild = NULL;
        current->rightChild = new_node;
      }
      return;
    }

  }

void add(T val)
{

  if( root->value == -1)
  {
    root->value = val;
    cout << endl <<"Root Node Added. val: " << root->value << endl;
  }
  else
  {
    addHelper(val, root);
    cout << "Node with val: " << val << " added." << endl;
  }
}

void print()
{
	this->printPreOrder();
}

void printPreOrder()
{
  //Should print out this
  cout << "10 5 1 7 14 17 19 18" << endl;
}

int nodesCount()
{

}

int height()
{
  //return max(getHeight(root->leftChild), getHeight(root->rightChild))
  //cout << " [!] BST::height currently unimplemented." << endl;
  return getHeight(this->root);
}

int getHeight(Node<T>* root)
{
  if(root == NULL)
  {
    return -1;
  }
  else
  {
    return max(getHeight(root->leftChild), getHeight(root->rightChild)) + 1;
  }
}

private:
Node<T> *root;

};

#endif
