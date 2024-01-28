/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

SymbolTable::SymbolTable(){
    int size = 0;
    root = NULL;

}

SymbolTable::~SymbolTable(){
    delete root;
}
SymEntry* searchest(SymEntry* root, string s){
    if(root==NULL or root->key==s){
        return root;
    }
    if(root->key>s){
        return searchest(root->left,s);
    }else{
        return searchest(root->right,s);
    }
}

void SymbolTable::insert(string k, UnlimitedRational* v){
    inserter(k,v,this->root);
    size++;
}

void inserter(string k, UnlimitedRational* v, SymEntry* root){
    if (root==NULL){
        root = new SymEntry(k,v);
    }
    if (root->key>k){
        inserter(k,v,root->left);
    }
    if (root->key<k){
        inserter(k,v,root->right);
    }
}

UnlimitedRational* SymbolTable::search(string k){
    SymEntry* temp = searchest((this)->root, k);
    return temp->val;
}

void SymbolTable::remove(string k){
    // SymEntry* parent = NULL;
    // SymEntry* temp1 = root;
    // while(!(root==NULL or root->key==k)){
    //     if (root->key>k){
    //         parent = root;
    //         root = root->left;
    //     }else{
    //         parent = root;
    //         root = root->right;}
    

    // }
    // if(root->left==NULL and root->right==NULL)
    // {
    //     delete root;
    //     root = temp1;
    //     return;
    // }
    // if(root->left == NULL ){
    //     if(parent->right==root){
    //         parent->right ==root->right;
    //         delete root;
    //         root =         
    //     }else{
    //         parent->left==root->right;
    //     }
    // }
}

int SymbolTable::get_size(){
    return size;
}
SymEntry* SymbolTable::get_root(){
    return root;
}