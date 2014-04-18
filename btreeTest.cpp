#include <iostream>
#include "btree.h"

using namespace std;

void bstInsert(BinaryTree<int> *t, int data)
{
  if (data <= t-> getData())
  {
    if(!t->getLeft())
      t->linkLeft(new BinaryTree<int>(data));
    else
      bstInsert(t->getLeft(), data);
  }
  else
  {
    if(!t->getRight())
      t->linkRight(new BinaryTree<int>(data));
    else 
      bstInsert(t->getRight(), data);
  }

}

int main(void)
{
  BinaryTree<int> *t=NULL;
  int data;

  do
  {
    cout << "Enter number (-1 to exit): ";
    cin>>data;

    if (data == -1)
      continue;

    if(!t)
      t = new BinaryTree<int>(data);
    else
      bstInsert(t, data);
  } while (data != -1);

  t -> printTree();
  return 0;
}
