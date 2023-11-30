// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct e
{
    string s;
    int count;
};



class h{
    public:
    int capacity=1024;
    vector<vector<e>> v;

    h(){
        v.resize(capacity);
    }
    
    ~h(){
        for(int i=0;i<capacity;i++){
            v[i].clear();
        }
        v.clear();
    }

    void insert(string st){
        int p=0;
        for(int i=0;i<st.size();i++){
            p=p+static_cast<int>(st[i]);
        }
        int hash=p%capacity;
        bool b=true;
        for(int i=0;i<v[hash].size();i++){
            if(v[hash][i].s==st){
                v[hash][i].count=v[hash][i].count+1;
                b=false;
                break;
            }
        }
        if(b){
            v[hash].push_back(e{st,1});
        }
        return;
    }

    int countt(string st){
        int p=0;
        for(int i=0;i<st.size();i++){
            p=p+static_cast<int>(st[i]);
        }
        int hash=p%capacity;
         for(int i=0;i<v[hash].size();i++){
            if(v[hash][i].s==st){
                return v[hash][i].count;
            }
        }
        return 0;

    }

};

class Dict {
private:
    // You can add attributes/helper functions here
    h* wordCounts;

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};