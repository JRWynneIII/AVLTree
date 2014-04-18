#include <iostream>
#include "avltree.h"

using namespace std;

int main(void)
{
  AVLTree<int> *t = NULL;
  int data;

  do
  {
    cout << "Enter number (-1 to exit): ";
    cin>>data;

    if (data == -1)
      continue;

    if(!t)
      t = new AVLTree<int>(data);
    else
      t->insert(data);
  } while (data != -1);

  t -> printTree();
  return 0;
}
