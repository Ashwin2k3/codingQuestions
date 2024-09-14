class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> m ;
        int maxfruit = 0;
        int left = 0;

        for(int right = 0;right <fruits.size();i++){
            m[fruits[right]]++;
            while (m.size() > 2) {   
                m[fruits[left]] -- ;
                if (m[fruits[left]] == 0 {
                        m.erase(fruits[left]);

                }
                left ++ ;
            }
            maxfruit = max(maxfruit, right - left + 1 );
            
        }
        return maxfruit ;
    }
};

