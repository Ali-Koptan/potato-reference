#include <bits/stdc++.h>
using namespace std;
const int max_char = 26;
struct trie{
    trie *child[max_char];
    bool leaf;
    trie(){
        memset(child, 0, sizeof child);
        leaf = 0;
    }
    void insert(char *str){
        if (*str == '\0'){
            leaf = 1;
        }else{
            int cur = *str - 'a';
            if (!child[cur])
                child[cur] = new trie();
            child[cur]->insert(str + 1);
 
        }
    }
    void deleteword(char *str){
        if (*str == '\0'){
            leaf = 0;
            return;
        }
        else{
            int cur = *str - 'a';
            child[cur]->wordquery(str + 1);
            delete child[cur];
        }
    }
    bool wordquery(char *str){
        if (*str == '\0')
            return leaf;
        else{
            int cur = *str - 'a';
            if (!child[cur])
                return false;
            return child[cur]->wordquery(str + 1);
        }
    }
};
int main(){
    trie root;
    root.insert("abc");
    root.insert("and");
    root.insert("abcdef");
    cout << root.wordquery("abc") << '\n';
    cout << root.wordquery("abcd") << '\n';
    cout << "before deletion \n";
    root.deleteword("abc");
    cout << "after deletion \n";
    cout << root.wordquery("abc");
    return  0;
}