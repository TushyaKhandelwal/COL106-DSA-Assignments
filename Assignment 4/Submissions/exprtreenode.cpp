/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"
   ExprTreeNode:: ExprTreeNode(string t, UnlimitedInt* v)
   {
    left = nullptr;
    right= nullptr;
    if (t == "+" )
    {
        type = "ADD";
    }
    if (t == "-")
    {
        type = "SUB";
    }
    if(t=="*")
    {
        type = "MUL";
    }
    if(t=="/")
    {
        type = "DIV";
    }
    bool balz =1;
    if (t[0]=='-')
    {
    for(int i =1;i<t.length();i++)
    {
        balz = balz && (t[i]-'0'<=9 && t[i]-'0'>=0); 
    }
    }
    else
        {
    for(int i =0;i<t.length();i++)
    {
        balz = balz && (t[i]-'0'<=9 && t[i]-'0'>=0); 
    }
    }
    if(balz)
    {
        type = "VAL";
        val = new UnlimitedRational(v, new UnlimitedInt ("1"));
    }
    else
    {
        if (t == ":=")
        {
            type = "ASSIGNMENT";
            id = t;
        }
        else{
            type = "VAR";
            id =t;
        }
    }
    

   }

   ExprTreeNode:: ExprTreeNode(string t, UnlimitedRational* v)
   {
    left = nullptr;
    right= nullptr;
    if (t == "+" )
    {
        type = "ADD";
    }
    if (t == "-")
    {
        type = "SUB";
    }
    if(t=="*")
    {
        type = "MUL";
    }
    if(t=="/")
    {
        type = "DIV";
    }
    bool balz =1;
    if (t[0]=='-')
    {
    for(int i =1;i<t.length();i++)
    {
        balz = balz && (t[i]-'0'<=9 && t[i]-'0'>=0); 
    }
    }
    else
        {
    for(int i =0;i<t.length();i++)
    {
        balz = balz && (t[i]-'0'<=9 && t[i]-'0'>=0); 
    }
    }
    if(balz)
    {
        type = "VAL";
        val = v;
    }
    else
    {
        if (t == ":=")
        {
            type = "ASSIGNMENT";
            id = t;
        }
        else{
            type = "VAR";
            id =t;
        }
    }
    

   }

ExprTreeNode:: ExprTreeNode()
{
    id = "";
    type = "";
    left = nullptr;
    right=nullptr;
    val = nullptr;
    evaluated_value = nullptr;
}
ExprTreeNode:: ~ExprTreeNode()
{
    delete val;
    delete evaluated_value;
    delete left;
    delete right;
}