// Do NOT add any other includes
#include "dict.h"

Dict::Dict(){
    // Implement your function here    
    wordCounts=new h();
}

Dict::~Dict(){
    // Implement your function here    
    delete wordCounts;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    std::string word = "";
    string op=" .,-:!\"\'()?—[]“”‘’˙;@";

    for (int i = 0; i < sentence.size(); i++) {
        char currentChar = sentence[i];

        if (std::isalnum(currentChar)) {
            word += std::tolower(currentChar);
        } else if(op.find(currentChar)!=std::string::npos){
            if (!word.empty()) {
                wordCounts->insert(word);
                word = ""; 
            }
        }
        else{
            word += currentChar;
        }
    }
    if (!word.empty()) {
        wordCounts->insert(word);
    }
}

int Dict::get_word_count(string word){
    string w=word;
    if(w==""){
        return -1;
    }
    else if(w!="" && std::isalnum(w[0])){
        w[0]=std::tolower(w[0]);
    }

    return wordCounts->countt(w);
}

void Dict::dump_dictionary(string filename){
    // Implement your function here  
    // Dump the dictionary to a file in lowercase
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for(int i=0;i<wordCounts->capacity;i++){
            for(int j=0;j<wordCounts->v[i].size();j++){
                outFile << wordCounts->v[i][j].s << ", " <<wordCounts->v[i][j].count<< "\n";
            }
        }
        outFile.close();
    }
    return;

}