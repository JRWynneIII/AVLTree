#ifndef AVLTREE_H
#define AVLTREE_H

#include "btree.h"

template<typename T>
class AVLTree : public BinaryTree<T>
{
public:
  AVLTree(T data) : BinaryTree<T>(data)
  {
    lh=rh=0;
  }

  bool operator<(AVLTree<T> &rhs)
  {
    return this->getData() < rhs.getData();
  }

  bool operator>(AVLTree<T> &rhs)
  {
    return this->getData() > rhs.getData();
  }

  bool operator<=(AVLTree<T> &rhs)
  {
    return this->getData() <=rhs.getData();
  }

  bool operator>=(AVLTree<T> &rhs)
  {
    return this->getData() >= rhs.getData();
  }

  bool operator==(AVLTree<T> &rhs)
  {
    return this->getData() == rhs.getData();
  }

  AVLTree<T> *getLeft()
  {
    return (AVLTree<T> *) BinaryTree<T>::getLeft();
  }

  AVLTree<T> *getRight()
  {
    return (AVLTree<T> *) BinaryTree<T>::getRight();
  }

  AVLTree<T> *getParent()
  {
    return (AVLTree<T> *) BinaryTree<T>::getParent();
  }

  AVLTree<T> *getUncle()
  {
    return (AVLTree<T> *) BinaryTree<T>::getUncle();
  }

  AVLTree<T> *insert(T data)
  {
    AVLTree<T> *node = NULL;
    AVLTree<T> *p;
    node = new AVLTree<T>(data);
    bstInsert(node);
    
    AVLTree<T> *cur = node->getParent();
    while(cur)
    {
      p = cur->getParent();
      rebalance(cur);
      cur = p;
    }

    cur = node;
    while(cur->getParent())
    {
      cur = cur->getParent();
    }
    return cur;
  }

  //Searches for an item in the avl tree. returns the node pointer on success, NULL if none

  AVLTree<T> *search(T item)
  {
    //DO THIS!
  }
  
private:
  void bstInsert(AVLTree<T> *node)
  {
    if(*node <= *this)
    {
      lh++;
      //if theres not a node on the left
      if (!this->getLeft())
      {
        //put one on the left
        this->linkLeft(node);
        std::cout << "lh: " << lh << "\t rh: " << rh << "\t" << "Linked on the left" <<std::endl;
      }
      else 
        //if there is, walk down to the left
        bstInsert(this->getLeft());
    }
    else
    {
      rh++;
      //if theres not one on the Right
      if (!this->getRight())
      {
        //put one on the right
        this->linkRight(node);
        std::cout << "lh: " << lh << "\t rh: " << rh << "\t" << "Linked on the right" <<std::endl;
      }
      else
        //else walk down the right and try again
        bstInsert(this->getRight());
    }
  }

  void rebalance(AVLTree<T> *node)
  {
    int balance = (node->lh)-(node->rh);
    if (balance == -2)
    {
      AVLTree<T> *right = node->getRight();
      if ((right->lh)-(right->rh) == 1)
        rotateRight(right);
      rotateLeft(node);
    }
    else if (balance == 2)
    {
      AVLTree<T> *left = node->getLeft();
      if ((left->lh) - (left->rh) == -1)
        rotateLeft(left);
      rotateRight(node);
    }
  }

  void rotateLeft(AVLTree<T> *node)
  {
    AVLTree<T> *p = node->getParent();
    AVLTree<T> *node2 = (AVLTree<T> *) node->right;
    AVLTree<T> *b = (AVLTree<T> *) node->left;
    node2->linkLeft(node);
    node->linkRight(b);
    //fix p's link if p is not null
    if (p != NULL)
    {
      node->linkLeft(p);      
    }
    rh--;
    lh++;
  }

  void rotateRight(AVLTree<T> *node)
  {
    AVLTree<T> *p = node->getParent();
    AVLTree<T> *node2 = (AVLTree<T> *) node->right;
    AVLTree<T> *b = (AVLTree<T> *) node->left;
    node2->linkRight(node);
    node->linkLeft(b);
    //fix p's link if p is not null
    if (p != NULL)
    {
      node->linkRight(p);      
    }
    lh--;
    rh++;
  }

  int lh;
  int rh;
};
#endif
