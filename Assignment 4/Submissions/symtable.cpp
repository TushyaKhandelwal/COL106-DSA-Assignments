/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
SymbolTable::SymbolTable()
{
    size=0;
    root = nullptr;
}
SymbolTable::~SymbolTable()
{
    delete root;
}
SymEntry* SymbolTable::get_root()
{
    return root;
}
int SymbolTable::get_size()
{
    return size;
}
void inserter(SymEntry* root, string k, UnlimitedRational* v)
{
if (!root)
{
    root = new SymEntry(k,v);
}
else
{
    if (k<root->key)
    {
        return inserter(root->left, k, v);
    }
    else
    {
        return inserter(root->right, k, v);
    }
}
}
void SymbolTable::insert(string k, UnlimitedRational* v)
{

    inserter( root,k, v);
    size+=1;
}
SymEntry* searcher(SymEntry* root, string k)
{
    if (k> root->key)
    {
        return (searcher(root->right,k));
    }
    if (k< root->key)
    {
        return (searcher(root->left,k));
    }
    else{
        return root;
    }

}
 UnlimitedRational* SymbolTable::search(string k)
 {
    return searcher(root, k)->val;
 }
 SymEntry* successor(SymEntry* root)
 {
    SymEntry* temp= root->right;
    while(temp->left)
    {
        temp = temp->left;
    }
    return temp;
 }
 SymEntry* remover(SymEntry* root, string k)
 { 
    SymEntry* peenous = root;
    if(peenous->key == k)
    {
        if(peenous->left && peenous->right)
        {
            SymEntry* temp = successor(peenous);
            peenous->key = temp->key;
            temp->right = remover(peenous->right,temp->key);
        }

        if(peenous->left && !(peenous->right))
        {
            SymEntry* temp = peenous->left;
            delete peenous;
            return temp;
        }
        if(!(peenous->left) && peenous->right)
        {
            SymEntry* temp = peenous->right;
            delete peenous;
            return temp;
        }
        if (!(peenous->left || peenous->right))
        {
            delete peenous;
            return nullptr;
        }
    }
    else if (peenous->key>k)
    {
        peenous->left = remover(peenous->left,k);
        return peenous;
    }
    else
    {
        peenous->right = remover(peenous->right,k);
        return peenous;
    }

 }

void SymbolTable:: remove(string k)
{
    root = remover(root,k);
    size-=1;
}