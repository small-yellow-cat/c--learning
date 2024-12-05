#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename valType>
class BTnode;

template<typename elemType>
class BinaryTree;



template<typename elemType>
class BinaryTree{
    //template<typename valType>
    //friend ostream& operator<<(ostream &os , BinaryTree<valType>& bt);
    public:
    //constructor and destructor
    BinaryTree( );
    BinaryTree( const BinaryTree& );
    ~BinaryTree( );
    
    BinaryTree& operator=(const BinaryTree&);
    
    void insert(const elemType &elem);
    //check whether empty and clean
    bool empty(){ return _root==0;}
    void clear(){if(_root) clear(_root); _root=0; };

    //remove
    void remove(const elemType &elem);
    void remove_root();
    //display in different orders
    void preorder( ){_root->preorder(_root, cout);}
    void inorder( ){_root->inorder(_root, cout);}
     void postorder( ){_root->postorder(_root, cout);}
     // print function
    // ostream& print(BinaryTree&, ostream& os=cout ){ _root->print(_root, os);}
     //
    private:
    BTnode<elemType>* _root;
    void clear(BTnode<elemType>* );
};


template <typename valType>
class BTnode{
    public:
    BTnode( const valType& );
    friend class BinaryTree<valType>;  //the BinaryTree with the same parameters
    void insert_value(const valType&);
    //remove value
    void remove_value(const valType&, BTnode*& );
    //static 
    void static lchild_leaf(BTnode*, BTnode*);
    //preordering function
    void preorder(BTnode * pt=0, ostream &os=cout);
    void inorder(BTnode * pt=0, ostream &os=cout);
    void postorder(BTnode * pt=0, ostream &os=cout);
    void display_val(BTnode *pt, ostream & os){ os<<pt->_val<<" ";}

    private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
    
};

template<typename elemType>
BinaryTree<elemType>::BinaryTree():_root(0)
{}

template<typename elemType>
BinaryTree<elemType>::BinaryTree( const BinaryTree& rhs){copy(_root, rhs._root);}

template<typename elemType>
BinaryTree<elemType>::~BinaryTree(){ clear();}

template<typename elemType>
BinaryTree<elemType>& BinaryTree<elemType>::operator=(const BinaryTree&rhs){
if(this != &rhs){ clear(); copy(_root, rhs._root);}
return *this;
}

//insertion function
template<typename elemType>
void BinaryTree<elemType>::insert(const elemType& elem){
    if(!_root) _root=new BTnode<elemType>(elem);
    else _root->insert_value(elem);
}

//removal function
template<typename elemType> 
void BinaryTree<elemType>::remove(const elemType& elem){
    if(_root){
        if(_root->_val==elem) remove_root();
        else 
        _root->remove_value(elem, _root);
    }

}

template<typename elemType>
void BinaryTree<elemType>::remove_root(){
    if( ! _root) return;
    BTnode<elemType> * tmp=_root;
    if(tmp->_rchild){ _root=_root->_rchild;
    if(tmp->_lchild){BTnode<elemType> *lc=tmp->_lchild; BTnode<elemType> 
    *newlc=_root->_lchild; if(! newlc) _root->_lchild=lc;  
    else BTnode<elemType>::lchild_leaf(lc, newlc); }
    
    }
    else _root=_root->_lchild;
    delete tmp; //remove the previous root
}

//clear the tree 
template<typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType> *pt){
    if (pt) { clear(pt->_lchild); clear(pt->_rchild); delete pt; }
}


//operator << overloaded
/*
template<typename elemType>
inline ostream& operator<<(ostream & os, BinaryTree<elemType>&bt){
os<<"Tree: "<<endl; bt.print(os); return os;
} */

//....................................BTnode

template <typename valType> 
BTnode<valType>::BTnode(const valType& val):_val(val){ _cnt=1; _lchild=_rchild=0;}

template<typename valType>
void BTnode<valType>::insert_value(const valType& val){
if(val ==_val){_cnt++; return;}
if(val<_val){ if(!_lchild) _lchild=new BTnode(val); else _lchild->insert_value(val);}
else{if(!_rchild) _rchild=new BTnode(val); else _rchild->insert_value(val);}
}

template<typename valType>
void BTnode<valType>::lchild_leaf(BTnode* leaf, BTnode* subtree){
    while(subtree->_lchild) subtree=subtree->_lchild;
    subtree->_lchild=leaf;
}

//remove
template<class valType> 
void BTnode<valType>::remove_value(const valType &val, BTnode* &prev){//prev current examined node
    if(val<_val) { if(!_lchild) return; else _lchild->remove_value(val, _lchild);}
    else
    if(val >_val){ if(!_rchild) return; else _rchild->remove_value(val, _rchild);}
    else { if (_rchild){prev=_rchild; if(_lchild) if(! prev->_lchild) prev->_lchild=_lchild;
    else BTnode<valType>::lchild_leaf(_lchild,prev->_lchild ); }
    else prev=_lchild;
    delete this;
    }

}
//.....different orders
//preordering
template<typename valType>
void BTnode<valType>::preorder(BTnode* pt, ostream &os){
    if(pt) { display_val(pt, os); if(pt->_lchild) preorder(pt->_lchild, os); 
    if(pt->_rchild) preorder(pt->_rchild, os);}
}

//inorder
template<typename valType>
void BTnode<valType>::inorder(BTnode* pt, ostream &os){
    if(pt) {if(pt->_lchild) inorder(pt->_lchild, os); display_val(pt, os);
    if(pt->_rchild) inorder(pt->_rchild, os);}
}

//postorder
template<typename valType>
void BTnode<valType>::postorder(BTnode* pt, ostream &os){
    if(pt) {if(pt->_lchild) postorder(pt->_lchild, os); 
    if(pt->_rchild) postorder(pt->_rchild, os); display_val(pt, os); }
}



#endif