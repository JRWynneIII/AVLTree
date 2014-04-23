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
    bstInsert(node,this);
    
    AVLTree<T> *cur = node->getParent();
    while(cur)
    {
      p = cur->getParent();
      rebalance(cur);
      if (p == NULL)
        break;
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
  int getlh()
  {
    int lh=0;
    AVLTree<T> *left = (AVLTree<T> *)this->left;

    if(left)
      lh = left->getlh();

    return 1 + lh;
  }

  int getrh()
  {
    int rh=0;
    AVLTree<T> *right = (AVLTree<T> *)this->right;

    if(right)
      rh = right->getrh();
    return 1 + rh;
  }

  void bstInsert(AVLTree<T> *node, AVLTree<T> *p)
  {
      if(*node <= *p)
      {
        //if theres not a node on the left
        if (!p->getLeft())
        {
          //put one on the left
          p->linkLeft(node);
        }
        else 
        {
          //if there is, walk down to the left
          bstInsert(node,p->getLeft());
        }
      }
      else 
      {
        //if theres not one on the Right
        if (!p->getRight())
        {
          //put one on the right
          p->linkRight(node);
        }
        else
          //else walk down the right and try again
          bstInsert(node,p->getRight());
      }
  }

  void rebalance(AVLTree<T> *node)
  {
    int balance = (node->getlh())-(node->getrh());
    if (balance == -2)
    {
      AVLTree<T> *right = node->getRight();
      if ((right->getlh())-(right->getrh()) == 1)
        rotateRight(right);
      rotateLeft(node);
    }
    else if (balance == 2)
    {
      AVLTree<T> *left = node->getLeft();
      if ((left->getlh()) - (left->getrh()) == -1)
        rotateLeft(left);
      rotateRight(node);
    }
  }

  void rotateLeft(AVLTree<T> *node)
  {
    AVLTree<T> *p = node->getParent();
    AVLTree<T> *node2;
    AVLTree<T> *b;
    node2 = node->getRight();
    b = node->getLeft();
    if (b)
    {
    node2->linkLeft(node);
      node2->linkRight(b);
    }
    //fix p's link if p is not null
    if(p)
    {
       if (p->getRight() == node)
       {
        p->linkRight(node2);
       }
       else
       {
         p->linkLeft(node2);
       }
    }
    else
      node2->reparent(p);
    std::cout << "Rotating Left\n";
  }

  void rotateRight(AVLTree<T> *node)
  {
    std::cout << "Rotating Right\n";
    AVLTree<T> *p = node->getParent();
    AVLTree<T> *node2 =  node->getLeft();
    AVLTree<T> *b = node->getRight();
    node2 = node->getLeft();
    b = node->getRight();
    if (b)
    {
    node2->linkRight(node);
      node2->linkLeft(b);
    }
    
    //fix p's link if p is not null
    if(p)
    {
       if (p->getLeft() == node)
       {
         p->linkLeft(node2);
       }
       else
       {
         p->linkRight(node2);
       }
    }
    else
      node2->reparent(p);
  }

  int lh;
  int rh;
};
#endif
