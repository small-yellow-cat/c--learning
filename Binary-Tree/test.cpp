#include <iostream>
#include <string>
#include <vector>
#include "BinaryTree.h"
using namespace std;

int main(){
 BinaryTree<string> bt;
 bt.insert("Piglet"); bt.insert("Eeyore"); bt.insert("Roo"); bt.insert("Tiger");
 bt.insert("Chris"); bt.insert("Pooh"); bt.insert("Kanga");
cout<<"Preorder traversal: \n"; bt.preorder(); 
cout<<"\n Inorder traversal: \n";  bt.inorder(); 
cout<<"\n Postorder traversal: \n";  bt.postorder(); 
bt.remove("Piglet");
  cout<<"\n\nPreorder traversal after Piglet removal: \n";
bt.preorder(); bt.remove("Eeyore");
  cout<<"\n\nPreorder traversal after Eeyore removal: \n";
 bt.preorder();
//cout<<bt<<endl;
 return 0;
}