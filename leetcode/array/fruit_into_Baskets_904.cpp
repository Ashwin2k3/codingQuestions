/*
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitCount;

        for (auto fruit : fruits) {
            fruitCount[fruit]++;
        }

        vector<pair<int, int>> v(fruitCount.begin(), fruitCount.end());

        sort(v.begin(), v.end(), greater<pair<int,int>>());

        int sum = 0;
        for (int i = 0; i < min(2, (int)v.size()); ++i) {
            sum += v[i].second;
        }

        return sum;
    }
};
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitCount;
        int maxFruits = 0;
        int left = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            fruitCount[fruits[right]]++;

            // If there are more than 2 types of fruits, shrink the window from the left
            while (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }

            // Update the maximum number of fruits we can collect
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};

