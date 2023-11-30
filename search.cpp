// Do NOT add any other includes
#include "search.h"

class l{
    public:
    Node* h;
    int size;
   
    void insert(Node* p){
        if(size==0){
            h=p;
            size++;
            return;
        }
        Node* nw=h;
        while(nw->right!=nullptr){
            nw=nw->right;
        }
        nw->right=p;
        size++;
        return;
    }
};


SearchEngine::SearchEngine(){
    // Implement your function here  
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
    v.clear();
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    Node* n=new Node(book_code,page,paragraph,sentence_no,-1);
    string s=sentence;
    v.push_back({n,s});
    return;
}

Node* SearchEngine::search(string pattern, int& n_matches){
    // Implement your function here  
    l list=l();
    for(int i=0;i<v.size();i++){
        string st=v[i].s;
        size_t found = st.find(pattern);

        int p;
        int s=st.size();

        if (found != std::string::npos) {
            p=found;
        }

        while(found != std::string::npos){
            Node* g=v[i].n;
            g->offset=p;
            list.insert(g);
            st=st.substr(found+1,st.size());
            found = st.find(pattern);
            p=s-st.size()+found;
        }
    }
    n_matches=list.size;
    return list.h;
}