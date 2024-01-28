/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"
Evaluator::Evaluator()
{
    symtable= new SymbolTable();
}
Evaluator::~Evaluator()
{
    delete symtable;
}
ExprTreeNode* parser(vector<string> codes)
{
    if (codes.size() ==1)
    {
         bool balz =1;
    if (codes[0][0]=='-')
    {
    for(int i =1;i<codes[0].length();i++)
    {
        balz = balz && (codes[0][i]-'0'<=9 && codes[0][i]-'0'>=0); 
    }
    }
    else
        {
    for(int i =0;i<codes[0].length();i++)
    {
        balz = balz && (codes[0][i]-'0'<=9 && codes[0][i]-'0'>=0); 
    }
    }
    if(balz){return new ExprTreeNode(codes[0], new UnlimitedInt(codes[0]));}

    else{ return new ExprTreeNode(codes[0],new UnlimitedInt());}
    }
    
    ExprTreeNode* left_node;
    int kkk =1;
    int k;
    if(codes[kkk] == "(")
    {
      int  counter = 0;
      for (int i =1;i<codes.size(); i++)
      {
        if (codes[i] == "(")
        {
            counter++;
        }
        if (codes[i] == ")")
        {
            counter--;
        }
        if (counter==0 && i !=1)
        {
             k =i;
            break;
        }
      }
      vector <string> subcodes;
      for(int j=1;j<=k;j++)
      {
        subcodes.push_back(codes[j]);
      }
      left_node = parser(subcodes);
    }
    else
    {
        k=kkk;
        vector <string> subcodes;
        subcodes.push_back(codes[kkk]);
        left_node = parser(subcodes);
    }
    k++;
    ExprTreeNode* node = new ExprTreeNode(codes[k], new UnlimitedInt());
    k++;
    vector <string> subnode;
    for(int l=k;l<codes.size()-1;l++)
    {
        subnode.push_back(codes[l]);
    }
    ExprTreeNode* right_node = parser(subnode);
    node->left=left_node;
    node->right=right_node;
    return node;



}
void Evaluator::parse(vector <string> code)
{
    ExprTreeNode* root = new ExprTreeNode(":=", new UnlimitedInt());
    vector <string> newcode;
    for(int i=2;i<code.size();i++)
    {
        newcode.push_back(code[i]);
    }
    root->right = parser(newcode);
    root->left = new ExprTreeNode(code[0], new UnlimitedInt());
    expr_trees.push_back(root);



}
UnlimitedRational* evaluator(SymbolTable* sym,ExprTreeNode* root_node)
{
    if (root_node->type == "VAL")
    {
        root_node->evaluated_value = root_node->val;
        return root_node->evaluated_value;
    }
    else if (root_node->type == "VAR")
    {
        root_node->evaluated_value = sym->search(root_node->id);
        return root_node->evaluated_value;
    }
    else if (root_node->type == "ADD")
    {
        root_node->evaluated_value = UnlimitedRational::add(evaluator(sym,root_node->left),evaluator(sym,root_node->right));
        return root_node->evaluated_value;
    }
    else if (root_node->type == "SUB")
    {
        root_node->evaluated_value = UnlimitedRational::sub(evaluator(sym,root_node->left),evaluator(sym,root_node->right));
        return root_node->evaluated_value;
    }
    else if (root_node->type == "MUL")
    {
        root_node->evaluated_value = UnlimitedRational::mul(evaluator(sym,root_node->left),evaluator(sym,root_node->right));
        return root_node->evaluated_value;
    }
    else if (root_node->type == "DIV")
    {
        root_node->evaluated_value = UnlimitedRational::div(evaluator(sym,root_node->left),evaluator(sym,root_node->right));
        return root_node->evaluated_value;
    }
    return new UnlimitedRational();
}
void Evaluator::eval()
{
ExprTreeNode* root = expr_trees[expr_trees.size()-1];
root->evaluated_value = evaluator(symtable,root->right);
symtable->insert(root->left->id,root->evaluated_value);
}
