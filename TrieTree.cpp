
#include <iostream>
#include "TrieNode.h"

using namespace Node;
using namespace std;

int main()
{
    NodeTrie* root = NodeTrie::getNewNode();
    NodeTrie::insert(root, "apple");
    NodeTrie::insert(root, "allocate");
    NodeTrie::insert(root, "boom");
    NodeTrie::insert(root, "blood");
    NodeTrie::insert(root, "clown");
    NodeTrie::insert(root, "crow");
    NodeTrie::insert(root, "door");
    NodeTrie::insert(root, "doom");

    std::string prefix;

    while (prefix != "q") {

        cin >> prefix;
        auto arr = NodeTrie::getAutoCompleteSuggestions(root, prefix);
        for (const auto& a : arr) {
            cout << a << " ";
        }
        cout << "\n";
    }
}
