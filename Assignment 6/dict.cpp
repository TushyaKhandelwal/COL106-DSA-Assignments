// Do NOT add any other includes
#include "dict.h"


Dict::Dict(){
    for (int i=0;i<20000003;i++){
        hash_table.push_back({});
    } 
}


int Dict::hash(string word){
	int sum=0;
    int n=word.length();
    for (int i=0;i<n;i++){
        int c= (int)word[i];
        sum+=c;
        sum=sum%20000003;
    }
    return sum;
}

int Dict::doesExist(string word){
	int ind=hash(word);
	for (int i=0;i<hash_table[ind].size();i++){
		if (hash_table[ind][i].word==word){
			return i;
		}
	}
	return -1;
}

Dict::~Dict(){    
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    int n=sentence.size();
    string s="";
    int i=0;
    while(i<=n){
    	if (sentence[i]=='.' || sentence[i]==',' || sentence[i]==' ' || sentence[i]=='-' || sentence[i]==':' || sentence[i]=='!' || sentence[i]=='"' || sentence[i]=='\'' || sentence[i]=='(' || sentence[i]==')' || sentence[i]=='?' ||  sentence[i]=='[' || sentence[i]==']' || sentence[i]==';' || sentence[i]=='@' || i==n){
    		int ind=hash(s);
    		int val=doesExist(s);
    		if (val!=-1){
    			hash_table[ind][val].count++;
    		}
    		else{
    			Node new_node;
    			if (s!=""){
    			new_node.word=s;
    			new_node.count=1;
    			hash_table[ind].push_back(new_node);
    		}
    		}
    		s="";
    	}
    	else{
    		if (sentence[i]>=65 && sentence[i]<=90){
    			sentence[i]+=32;
    		}
    		s+=sentence[i];
    	}
    	i++;
    }

}

int Dict::get_word_count(string word){
	int ind=hash(word);
	int val=doesExist(word);
	if (val!=-1){
		return hash_table[ind][val].count;
	}
	return 0;
    }

void Dict::dump_dictionary(string filename){
	ofstream myfile;
	myfile.open(filename,ios::app);
    for (int i=0;i<hash_table.size();i++){
    	for (int j=0;j<hash_table[i].size();j++){
    		string s= hash_table[i][j].word + ", " + to_string(hash_table[i][j].count);
    		myfile << s << endl;
			//cout<< s << endl;
    }
    }
    myfile.close();
    return;
}

/*int main(){
	Dict dic1;
	string a="this!!!! is biiook {adhhas";
	dic1.insert_sentence(0,0,0,0,a);
	dic1.dump_dictionary("a.txt");
	// cout << dic.get_word_count("are") << endl;
}*/