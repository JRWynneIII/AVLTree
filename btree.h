#ifndef BTREE_H
#define BTREE_H

#include <iostream>

template<typename T>
class BinaryTree
{
public:
  //always create tree nodes with data
  BinaryTree(T data)
  {
    left = right = parent;
    this -> data = data;
  }

  //destructor
  ~BinaryTree()
  {
    delete left;
    delete right;
  }

  void linkLeft(BinaryTree<T> *node)
  {
    left = node;
    if(node)
      node -> parent = this;
  }

  void linkRight(BinaryTree<T> *node)
  {
    right = node;
    if(node)
      node -> parent = this;
  }

  void reparent(BinaryTree<T> *np)
  {
    parent = np;
  }

  BinaryTree<T> *getLeft()
  {
    return left;
  }

  BinaryTree<T> *getRight()
  {
    return right;
  }

  BinaryTree<T> *getParent()
  {
    return parent;
  }

  BinaryTree<T> *getUncle()
  {
    BinaryTree<T> *gp;

    //root nodes and nongrandchildren have no uncles poor nongrandchildren
    if(!parent || !parent->parent)
      return NULL;

    //get grandparent
    if(parent == gp->left)
      return gp->right;
    else 
      return gp->left;
  }

  T getData()
  {
    return data;
  }

  int getHeight()
  {
    int lh=0, rh=0;

    std::cout << lh << "\t "<< rh << std::endl;
    if(left)
      lh = left->getHeight();
    if(right)
      rh = right->getHeight();
    std::cout << 1+(lh>rh?lh:rh) << std::endl;
    return 1+ (lh>rh?lh:rh);
  }

  void printTree()
  {
    int h = getHeight();
    for (int i=1;i<=h;i++)
    {
      printLevel(i);
      std::cout << std::endl;
    }
  }

  BinaryTree<T> *left;
  BinaryTree<T> *right;
  BinaryTree<T> *parent;
private:
  void printLevel (int h)
  {
    if (h==1)
    {
      std::cout << data << " ";
    }
    else
    {
      if(left)
        left->printLevel(h-1);
      else
        std::cout << "# ";

      if(right)
        right->printLevel(h-1);
      else
        std::cout << "# ";
    }
  }

  T data;
};
#endif


