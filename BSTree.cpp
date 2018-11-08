#include <iostream>
#include <string>
#include <fstream>
#include <initializer_list>
#include <vector>
#include "BSTree.hpp"

using namespace BSTree;
using namespace std;

#define NIL &sentinel
Node sentinel = { 0, nullptr, nullptr, nullptr , BLACK};

Tree::Tree(): root(NIL) {};

auto Tree::insert(int value) -> void {
	Node *node=new Node{value, NIL , NIL ,nullptr,BLACK};
	insert(node);
}
auto Tree::show_tree(int stage) -> void {
	show_tree(root,stage);
}
auto Tree::show_tree(Node* root,int stage)->void {
	if(root->right != NIL)
		show_tree(root->right,stage+1);
	if(root!=this->root) {
		cout.width(stage*4);
		cout<<"--";
	}
	if(root->color == RED)
	    cout<<"("<< root->data <<" "<<"*RED*"<<")"<< endl;
	else if(root->color == BLACK)
	    cout<<"("<< root->data <<" "<<"*BLACK*"<<")"<< endl;
	if(root->left != NIL)
		show_tree(root->left,stage+1);
}

auto Tree::insert(Node *&value) -> void {
	Node* y = NIL;
	Node* x = root;
	while(x != NIL){
		y=x;
		if(value->data < x->data)
			x=x->left;
		else x=x->right;
	}
	value->parent=y;
	if(y == NIL)
		root=value;
	else if(value->data < y->data)
		y->left=value;
	else y->right=value;
	value->left = NIL;
	value->right = NIL;
	value->color=RED;
	insert_fixup(value);
	//show_tree(root,1);
}
auto Tree::insert_fixup(Node *z) -> void {
    Node* y = nullptr;
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{ 
                if(z == z->parent->right){
                    z = z->parent;
                    left_rotate(z);
                }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            right_rotate(z->parent->parent);
            }
        }else{
            y = z->parent->parent->left;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{ 
                if(z == z->parent->left){
                    z = z->parent;
                    right_rotate(z);
                }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            left_rotate(z->parent->parent);
        }
    }
    }
    root->color = BLACK;
}
auto Tree::left_rotate(Node *x) -> void{
    Node* y = x->right;
    x->right = y->left;
    
    if(y->left != NIL)
        y->left->parent = x;
        
    y->parent = x->parent;
    
    if(x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}
auto Tree::right_rotate(Node *x) -> void{
    Node* y = x->left;
    x->left = y->right;
    
    if(y->right != NIL)
        y->right->parent = x;
        
    y->parent = x->parent;
    
    if(x->parent == NIL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else 
        x->parent->left = y;
    
    y->right = x;
    x->parent = y;
}
/*
auto Tree::rb_transplant(Node* u,Node* v) -> void{
    if(u->parent == NIL)
        root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    
    v->parent = u->parent; 
}
auto Tree::rb_delete(Node* z) -> void{
    Node* y = z;
    Node* x= nullptr;
    short int y_original_color = y->color;
    if(z->left == NIL){
        x = z->right;
        rb_transplant(z,z->left);
    }else if(z->right == NIL){
        x = z->left;
        rb_transplant(z,z->right);
    }else{
        y = tree_minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == z)
            x->parent = y;
        else{
            rb_transplant(y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    
    if(y_original_color == BLACK)
        rb_delete_fixup(x);
}
auto Tree::tree_minimum(Node* x) -> Node* {
    
}
auto Tree::rb_delete_fixup(Node* z) -> void {
    Node* w = nullptr;
    while(x != root && x->color == BLACK){
        if(x == x->parent->left){
            w = x->parent->right;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            }else{
                if(w->right->color == BLACK){
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(x);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(x->parent);
                x = root;
            }
        }
    }
}*/
auto Tree::show(Node* root, std::ostream& os, int stage) const -> void{
    if(root->right != NIL)
		show(root->right,os,stage+1);
	if(root!=this->root) {
		os.width(stage*4);
		os<<"--";
	}
	if(root->color == RED)
	    os<<"("<< root->data <<" "<<"*RED*"<<")"<< endl;
	else if(root->color == BLACK)
	    os<<"("<< root->data <<" "<<"*BLACK*"<<")"<< endl;
	if(root->left != NIL)
		show(root->left,os,stage+1);   
}
namespace BSTree {
	auto operator<<(std::ostream& os, const Tree& tr) -> std::ostream& {
		if(tr.root) {
			tr.show(tr.root, os, 1);
			return os;
		} else{
			os << "tree is empty" << endl;
			return os;
		}
	}
}

auto Tree::delete_tree(Node *&node) -> void {
	if(node != NIL) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
		node = NIL;
	}
}
Tree::~Tree() {
	delete_tree(root);
}
