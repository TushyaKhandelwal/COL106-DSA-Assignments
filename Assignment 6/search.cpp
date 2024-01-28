#include "search.h"

SearchEngine::SearchEngine(){
    // Implement your function here  
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    // Implement your function here 
    for(char& c: sentence)
    {
        if(int(c)>=65 and int(c)<=90)
        {
            c = char(int(c)+32);
        }
    } 
    input.push_back(text(book_code,page,paragraph,sentence_no,sentence));
    return;
}
Node* SearchEngine::search(string pattern, int& n_matches)
{
    // Implement your function here  
    int len_pattern = pattern.length();
    //cout<<"Length of pattern: "<<len_pattern<<endl;
    Node* front = nullptr;
    Node* rear = nullptr;
    for(auto tts:input)
    {
        int i =0;
        string sent = tts.sentence;
        // cout<<"Sentence: "<<sent<<endl;
        int sen_len = sent.length();
        //cout<<"Length of sentence: "<<sen_len<<endl;
        int k =0;
        while(i+len_pattern<=sen_len)
        {
            while(k+i<sen_len&& k<len_pattern && sent[k+i]==pattern[k])
            {
                if(i+len_pattern>sen_len)
                    break;
                k++;
            }
            if(k==len_pattern)
            {
                if(n_matches==0)
                {
                    front = new Node(tts.book_code,tts.page,tts.paragraph,tts.sentence_no,i);
                    front->right = nullptr;
                    front->left = nullptr;
                    rear = front;
                }
                else
                {
                    rear->right = new Node(tts.book_code,tts.page,tts.paragraph,tts.sentence_no,i);
                    rear->right->left = rear;
                    rear->right->right = NULL;
                    rear = rear->right;
                }
                n_matches++;
            }
            i++;
            k=0;
        }
    }
    return front;
}