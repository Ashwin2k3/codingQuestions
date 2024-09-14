class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        stringstream ss(sentence);
        string tmp;
        int index = 1;  // Start index from 1 for 1-based indexing

        while (getline(ss, tmp, ' ')) {
            words.push_back(tmp);
        }

        int j = searchWord.size(); // Use searchWord.size() directly
        for (int i = 0; i < words.size(); i++) {
            if (words[i].substr(0, j) == searchWord) {  // Match prefix with full size of searchWord
                return i + 1;  // Return 1-based index
            }
        }

        return -1; // Return -1 if no prefix match is found
    }
};

