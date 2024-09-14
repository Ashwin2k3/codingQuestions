class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string tmp;
        int index = 1;

        while (getline(ss, tmp, ' ')) {
            char front = tolower(tmp.front());

            if (front == 'a' || front == 'e' || front == 'i' || front == 'o' || front == 'u') {
                tmp.append("ma");
            } else {
                char firstLetter = tmp.front();
                tmp.erase(0, 1);
                tmp.push_back(firstLetter);
                tmp.append("ma");
            }

            tmp.append(string(index, 'a'));  // Add 'a' based on the word index
            words.push_back(tmp);
            index++;
        }

        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};

