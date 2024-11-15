# Code for all the Algorithms

Here are the C++ implementations for some of the most important Dynamic Programming (DP) algorithms. I'll start with a few key ones and cover others in subsequent responses if needed.

### 1. **Fibonacci Sequence**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Fibonacci using Dynamic Programming (Tabulation)
int fib(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}

```

---

### 2. **0/1 Knapsack Problem**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> wt(n), val(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}

```

---

### 3. **Longest Increasing Subsequence (LIS)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // Every element is an LIS of length 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Length of Longest Increasing Subsequence: " << LIS(arr) << endl;
    return 0;
}

```

---

### 4. **Longest Common Subsequence (LCS)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int LCS(string X, string Y) {
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    cout << "Length of Longest Common Subsequence: " << LCS(X, Y) << endl;
    return 0;
}

```

---

### 5. **Edit Distance (Levenshtein Distance)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int editDistance(string str1, string str2) {
    int m = str1.length(), n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    cout << "Edit Distance: " << editDistance(str1, str2) << endl;
    return 0;
}

```

---

### 6. **Coin Change Problem (Min Coins)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of coins: ";
    cin >> n;
    vector<int> coins(n);

    cout << "Enter coins: ";
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;
    return 0;
}

```

---

### 7. **Maximum Subarray Sum (Kadane’s Algorithm)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArraySum(vector<int>& nums) {
    int max_sum = nums[0], current_sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Maximum Subarray Sum: " << maxSubArraySum(nums) << endl;
    return 0;
}

```

---

Here are more C++ implementations for common **Dynamic Programming (DP)** algorithms:

---

### 8. **Matrix Chain Multiplication**

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]);
            }
        }
    }

    return dp[1][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter dimensions of matrices: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum number of multiplications: " << matrixChainMultiplication(arr) << endl;
    return 0;
}

```

---

### 9. **Rod Cutting Problem**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(vector<int>& prices, int length) {
    vector<int> dp(length + 1, 0);

    for (int i = 1; i <= length; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], prices[j] + dp[i - j - 1]);
        }
    }

    return dp[length];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices for each length (1 to " << n << "): ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << "Maximum profit: " << rodCutting(prices, n) << endl;
    return 0;
}

```

---

### 10. **Egg Dropping Problem**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eggDrop(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    for (int i = 1; i <= eggs; i++) {
        for (int j = 1; j <= floors; j++) {
            if (j == 1)
                dp[i][j] = 1;
            else if (i == 1)
                dp[i][j] = j;
            else {
                dp[i][j] = INT_MAX;
                for (int k = 1; k <= j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
                }
            }
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs, floors;
    cout << "Enter number of eggs: ";
    cin >> eggs;
    cout << "Enter number of floors: ";
    cin >> floors;

    cout << "Minimum trials required: " << eggDrop(eggs, floors) << endl;
    return 0;
}

```

---

### 11. **Palindromic Subsequence (Longest Palindromic Subsequence)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindromicSubsequence(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Subsequence: " << longestPalindromicSubsequence(s) << endl;
    return 0;
}

```

---

### 12. **Subset Sum Problem**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter sum: ";
    cin >> sum;

    cout << (isSubsetSum(arr, sum) ? "Yes" : "No") << endl;
    return 0;
}

```

---

### 13. **Coin Change (Unlimited Supply)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of coins: ";
    cin >> n;
    vector<int> coins(n);

    cout << "Enter coins: ";
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;
    return 0;
}

```

---

### 14. **Balanced Parentheses (Catalan Numbers)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

long long catalan(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of pairs: ";
    cin >> n;

    cout << "Number of balanced parentheses combinations: " << catalan(n) << endl;
    return 0;
}

```

---

These are some more **Dynamic Programming (DP)** algorithms implemented in C++. Let me know if you want more or explanations for any specific algorithm!

Here are some more **Dynamic Programming (DP)** algorithms, along with their C++ implementations:

---

### 15. **Longest Common Subsequence (LCS)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string x, string y) {
    int m = x.size(), n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string x, y;
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;

    cout << "Longest Common Subsequence: " << longestCommonSubsequence(x, y) << endl;
    return 0;
}

```

---

### 16. **Longest Increasing Subsequence (LIS)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Longest Increasing Subsequence length: " << longestIncreasingSubsequence(arr) << endl;
    return 0;
}

```

---

### 17. **Word Break Problem**

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n;
    cout << "Enter number of words in dictionary: ";
    cin >> n;

    unordered_set<string> wordDict;
    cout << "Enter words: ";
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        wordDict.insert(word);
    }

    cout << (wordBreak(s, wordDict) ? "Yes" : "No") << endl;
    return 0;
}

```

---

### 18. **0/1 Knapsack Problem**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight: ";
    cin >> W;

    vector<int> wt(n), val(n);
    cout << "Enter weights and values of items: ";
    for (int i = 0; i < n; i++) cin >> wt[i] >> val[i];

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;
    return 0;
}

```

---

### 19. **Count of Subsets with Given Sum**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSubsetsWithGivenSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;  // Subset sum 0 can be formed by not including any elements.
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter the sum: ";
    cin >> sum;

    cout << "Count of subsets with given sum: " << countSubsetsWithGivenSum(arr, sum) << endl;
    return 0;
}

```

---

### 20. **Fibonacci Sequence (Memoization)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << "Fibonacci number is: " << fibonacci(n, dp) << endl;
    return 0;
}

```

---

### 21. **Edit Distance (Levenshtein Distance)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    cout << "Edit Distance: " << editDistance(str1, str2) << endl;
    return 0;
}

```

---

These are additional **Dynamic Programming (DP)** algorithms commonly asked in competitive programming and interviews. Let me know if you need further clarification or more examples!