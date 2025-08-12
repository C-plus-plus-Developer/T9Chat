#include "TrieNode.h"

namespace Node {
    // ���������� ����� ���� � ������� ������
    NodeTrie* NodeTrie::getNewNode(void)
    {
        // �������� ������ ��� ����� ����
        struct NodeTrie* pNode = new NodeTrie;

        // ������������� ���� ����� ����� � false
        pNode->isEndOfWord = false;

        // �������������� ����� ������� ����������
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = nullptr;

        return pNode;
    }

   
    void NodeTrie::insert(NodeTrie* root, std::string word) {
        NodeTrie* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = NodeTrie::getNewNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
   

    bool NodeTrie::search(struct NodeTrie* root, std::string key) {
        NodeTrie* current = root;
        for (int i = 0; i < key.length(); i++) {
            char ch = key[i];
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
              
                return false;
            }
            current = current->children[index];
            if (current->isEndOfWord == true && current != nullptr) {
              
                return true;
            }
            else {
               
                return false;
            }

        }
    }

    bool NodeTrie::isEmprty(NodeTrie* node) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) return false;
            else return true;
        }
    }

    NodeTrie* NodeTrie::remove(NodeTrie* root, std::string key, int depth) {

        if (!root) return nullptr;
        if (depth == key.size()) {
            if (root->isEndOfWord) {
                root->isEndOfWord = false;
            }
            if (isEmprty(root)) {
                delete root;
                root = nullptr;
            }
            return root;
        }
        int index = key[depth] - 'a';
        root->children[index] = remove(root->children[index], key, depth + 1);
        if (isEmprty(root) && root->isEndOfWord == false) {
            delete (root);
            root = nullptr;
        }
        // ���������� ����� ������
        return root;
    }

    
    // ������� ����, ��������������� ��������� ��������
    NodeTrie* NodeTrie::findNodeForPrefix(NodeTrie* root, const std::string& prefix) {
        NodeTrie* current = root;
        for (char ch : prefix) {
            int index = getCharIndex(ch);
            if (index == -1 || current->children[index] == nullptr) {
                return nullptr; // ��� ������ ��������
            }
            current = current->children[index];
        }
        return current;
    }

    // �������� ��� �����, ������������ � ������� ����
    void NodeTrie::collectWords(NodeTrie* node, std::string currentWord, std::vector<std::string>& results) {
        if (node == nullptr) return;
        if (node->isEndOfWord) {
            results.push_back(currentWord);
        }
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i] != nullptr) {
                char nextChar = getIndexChar(i);
                collectWords(node->children[i], currentWord + nextChar, results);
            }
        }
    }
    static void dfs(NodeTrie* current, std::string currentPrefix, std::vector<std::string>& suggestions) {
        if (current->isEndOfWord) {
            
            suggestions.push_back(currentPrefix);
        }
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (current->children[i] != nullptr) {
                
                dfs(current->children[i], currentPrefix + NodeTrie::getIndexChar(i), suggestions);
            }
        }
    }
    // ������� ������� ��� ��������� �������������� �� ��������
    std::vector<std::string> NodeTrie::getAutoCompleteSuggestions(NodeTrie* root, const std::string& prefix) {
       
        NodeTrie* current = root;
        for (char ch : prefix) {
            int index = NodeTrie::getCharIndex(ch);
            if (index == -1 || current->children[index] == nullptr) {
                
                return {}; // ��� ���������� �� ��������
            }
            current = current->children[index];
        }
        // ������ current � ����, ��������������� ���������� ������� ��������
        std::vector<std::string> suggestions;
        
        dfs(current, prefix, suggestions);
        return suggestions;
    }

    int NodeTrie::getCharIndex(char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 'a';
        }
        return -1; // ���� ������ �� � ���������
    }

    char NodeTrie::getIndexChar(int index) {
        if (index >= 0 && index < ALPHABET_SIZE) {
            return 'a' + index;
        }
        return '?'; // ��������� ������
    } 

}

