#pragma once
#include <iostream>
#include <string>
#include <vector>
#define ALPHABET_SIZE 26
using namespace std;

namespace Node {

    struct NodeTrie
    {

        struct NodeTrie* children[ALPHABET_SIZE];
        //isEndOfWord - true, если ключ является концом слова
        bool isEndOfWord;

         NodeTrie* findNodeForPrefix(NodeTrie* root, const std::string& prefix);
         void collectWords(NodeTrie* node, std::string currentWord, std::vector<std::string>& results);
         NodeTrie* remove(NodeTrie* root, std::string key, int depth = 0);
         bool isEmprty(NodeTrie* node);
         bool search(struct NodeTrie* root, std::string key);
        static void insert(NodeTrie* root, std::string word);
        static NodeTrie* getNewNode(void);
        static char getIndexChar(int index);
        static int getCharIndex(char c);

      
         static std::vector<std::string> getAutoCompleteSuggestions(NodeTrie* root, const std::string& prefix);
        

    };
}


