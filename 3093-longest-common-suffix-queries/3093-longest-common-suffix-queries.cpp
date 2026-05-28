class Solution {
public:

    struct TrieNode {

        int child[26];

        // best index for this suffix
        int idx;

        TrieNode() {

            memset(child, -1, sizeof(child));

            idx = -1;
        }
    };

    vector<TrieNode> trie;

    Solution() {

        // reserve memory
        trie.reserve(500000 + 5);

        trie.push_back(TrieNode());
    }


    // better index chooser
    int better(int oldIdx,
               int newIdx,
               vector<string>& wordsContainer) {

        if (oldIdx == -1) {
            return newIdx;
        }

        int oldLen = wordsContainer[oldIdx].size();
        int newLen = wordsContainer[newIdx].size();

        // smaller length better
        if (newLen < oldLen) {
            return newIdx;
        }

        // if equal length -> smaller index
        if (newLen == oldLen && newIdx < oldIdx) {
            return newIdx;
        }

        return oldIdx;
    }


    void insert(string &word,
                int index,
                vector<string>& wordsContainer) {

        int node = 0;

        trie[node].idx =
            better(trie[node].idx,
                   index,
                   wordsContainer);

        // reverse traversal
        for (int i = word.size() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            // create node if absent
            if (trie[node].child[ch] == -1) {

                trie[node].child[ch] = trie.size();

                trie.push_back(TrieNode());
            }

            node = trie[node].child[ch];

            trie[node].idx =
                better(trie[node].idx,
                       index,
                       wordsContainer);
        }
    }


    int search(string &query) {

        int node = 0;

        for (int i = query.size() - 1; i >= 0; i--) {

            int ch = query[i] - 'a';

            // path breaks
            if (trie[node].child[ch] == -1) {
                break;
            }

            node = trie[node].child[ch];
        }

        return trie[node].idx;
    }


    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        // build trie
        for (int i = 0; i < wordsContainer.size(); i++) {

            insert(wordsContainer[i],
                   i,
                   wordsContainer);
        }

        vector<int> ans;

        // answer queries
        for (string &query : wordsQuery) {

            ans.push_back(search(query));
        }

        return ans;
    }
};