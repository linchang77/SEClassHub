#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include"BT.h"

using namespace std;




template<typename valType>
BTnode<valType>::BTnode(const valType &val)
        : _val(val)
{
    _cnt = 1;
    _lchild = _rchild = 0;
}

template<typename valType>
void BTnode<valType>::insert_value(const valType &val) {
    if ( this->_val == val) {
         this->_cnt++;        
         return ;
    }

    if(this->_val > val ) {
        if(!this->_lchild)
            this->_lchild = new BTnode<valType>(val);
        else
            this->_lchild->insert_value(val);
    } else {
        if(!this->_rchild)
            this->_rchild = new BTnode<valType>(val);
        else
            this->_rchild->insert_value(val);
    }

}

template<typename valType>
void BTnode<valType>::remove_value( const valType &val, BTnode *& prev) {   
    if( val < _val ) {
        if ( !_lchild)
            return;
        else
            _lchild->remove_value(val, _lchild);
    }
    else if ( val > _val) {
        if( !_rchild)
            return;
        else
            _rchild->remove_value(val,_rchild);
    }
    else {
        if (_rchild) {
            prev = _rchild;
            if(_lchild)
                if( !prev->_lchild)
                    prev->_lchild = _lchild;
                else
                    BTnode<valType>::lchild_leaf(_lchild,prev->_lchild);
        }
        else
            prev = _lchild;
        delete this;
    }

}

template<typename valType>
inline void BTnode<valType>::lchild_leaf( BTnode *leaf, BTnode *subtree) {
       while (subtree->_lchild)
             subtree = subtree->_lchild;
       subtree->_lchild = leaf;
}

// BinaryTree
template<typename elemType>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator= (const BinaryTree&);

    void insert( const elemType &);
    bool empty() { return _root == 0;}
    void remove(const elemType &elem);
    void remove_root();

    void clear() { if(_root) { clear(_root); _root = 0;}}
    void preorder();
    void preorder(BTnode<elemType> *node, ostream &os = cout);
    static ostream & display_val( elemType &node,ostream &os = cout);
    void pre_recursion(BTnode<elemType> *node);
    BTnode<elemType>* get_root() { return _root;}
private:
    BTnode<elemType> *_root;
    void clear(BTnode<elemType> *node);
    void copy(BTnode<elemType> *tar, BTnode<elemType> *src);
};

template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree() : _root(0) {}

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs) {
    copy(_root,rhs._root);
}

template<typename elemType>
void BinaryTree<elemType>::insert( const elemType &elem) {
    if (!_root)
        _root = new BTnode<elemType>(elem);
        _root->insert_value(elem);
}

template<typename elemType>
inline BinaryTree<elemType>::~BinaryTree() {
    clear();
}

template<typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::operator= (const BinaryTree &rhs) {
    if( ! this = &rhs) {
        clear();
        copy(_root,rhs._root);
    }
    return *this;
}

template<typename elemType>
inline void BinaryTree<elemType>::remove( const elemType &elem) {
    if(_root) {
        if( _root->_val == elem)
            remove_root();
        else
            _root->remove_value(elem, _root);
    }
}

template<typename elemType>
void BinaryTree<elemType>::
remove_root() {
    if (!_root) return;

    BTnode<elemType> *tmp = _root;

    if( !_root->_rchild) {
        _root = _root->_rchild;
        if(tmp->_lchild) {
            if(!_root->_lchild)
                _root->_lchild = tmp->_lchild;
            else
                BTnode<elemType>::lchild_leaf(tmp->_lchild,_root->_lchild);
        }

    }
    else
        _root = _root->_lchild;
    delete tmp;
}
template<typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType> *node) {
    if(node) {
        clear(node->_lchild);
        clear(node->_rchild);
        delete node;
    }
}

template<typename elemType>
void BinaryTree<elemType>::preorder() {
    pre_recursion(_root);
}

template<typename elemType>
void BinaryTree<elemType>::preorder(BTnode<elemType> *node, ostream &os) {

    if(node) {
        display_val(node->_val,os);
        preorder(node->_lchild,os);
        preorder(node->_rchild,os);
    }
}

template<typename elemType>
ostream & BinaryTree<elemType>::display_val(elemType &node , ostream &os) {
    os << node << ' ';
    return os;
}


template<typename elemType>
void BinaryTree<elemType>::pre_recursion(BTnode<elemType> *node) {
    stack<BTnode<elemType>*> s;   
    s.push(node);
    while(!s.empty()) {
        BTnode<elemType>* tmp = s.top();
        s.pop();
        BinaryTree<elemType>::display_val(tmp->_val,std::cout);
        if(tmp->_rchild)
            s.push(tmp->_rchild);    
        if(tmp->_lchild)
            s.push(tmp->_lchild);   
    }
}



int main(int argc, char *argv[])
{
    BinaryTree<string> bt;  
    bt.insert("abc");  
    bt.insert("agcb");  
    bt.insert("kfgd");  
    bt.insert("how are you");  
    bt.preorder();  
    cout << " " << endl;
    //bt.remove("abc");  
    //bt.preorder();  
    bt.remove("kfgd");  
    bt.preorder();    
    system("PAUSE");
    return EXIT_SUCCESS;
}
