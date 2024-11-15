# All Types of Concepts asked in DP

Dynamic Programming (DP) is one of the most important techniques in competitive programming and is widely used to optimize problems that involve overlapping subproblems and optimal substructure. Below are the key concepts and types of problems typically encountered in DP:

### 1. **Classic DP Problems**

These are the foundation of DP and are commonly asked in competitive programming interviews and contests:

- **Fibonacci Numbers**: Basic example of DP that builds solutions from smaller subproblems.
- **Factorial Calculation**: Efficiently computing factorial using DP.
- **Nth Tribonacci Number**: Extends Fibonacci sequence, where each number is the sum of the three preceding ones.

### 2. **Knapsack Problem Variants**

These are some of the most important and frequently asked DP problems:

- **0/1 Knapsack**: Given a set of items, each with a weight and value, find the maximum value that can be obtained with a knapsack of limited capacity.
- **Unbounded Knapsack**: A variation where you can take an item multiple times.
- **Subset Sum Problem**: Determine if there exists a subset of a given set that sums to a specific value.
- **Partition Problem**: Check if a set can be partitioned into two subsets with equal sum.

### 3. **Coin Change Problem**

- **Min Coins**: Given a set of coins, find the minimum number of coins needed to make a certain amount.
- **Max Number of Ways to Make Change**: Find the number of ways to make a certain amount using the given coins.

### 4. **Longest Increasing Subsequence (LIS)**

This is a classic DP problem:

- **Standard LIS**: Given an array of numbers, find the length of the longest increasing subsequence.
- **LIS with Binary Search Optimization**: Optimized approach using binary search to reduce time complexity.

### 5. **Longest Common Subsequence (LCS)**

- **LCS between Two Strings**: Find the length of the longest common subsequence between two strings.
- **LCS with Three Strings**: A variation where the LCS is computed for three strings.

### 6. **Longest Palindromic Subsequence**

- **LPS**: Find the longest subsequence of a string that is a palindrome.
- **Minimum Deletions to Make a String Palindromic**: Use LCS on the string and its reverse to find the number of deletions needed.

### 7. **Matrix Chain Multiplication**

- **Optimal Matrix Multiplication Order**: Given a sequence of matrices, find the most efficient way to multiply them together in terms of scalar multiplications.

### 8. **Rod Cutting Problem**

- Given a rod of length `n`, and prices for each length, determine the maximum revenue obtainable by cutting the rod into pieces.

### 9. **0-1 Knapsack with Multiple Items**

- **Multiple Knapsack**: In this variation, the knapsack can hold multiple items of the same type, so you need to handle repetitions efficiently.

### 10. **Edit Distance (Levenshtein Distance)**

- Find the minimum number of operations (insertions, deletions, substitutions) required to convert one string into another.

### 11. **Matrix Path Problems**

- **Unique Paths**: Given a grid, find the number of ways to reach the bottom-right corner from the top-left corner.
- **Minimum Path Sum**: Find the path in a grid that has the smallest sum from top-left to bottom-right.

### 12. **Subset Problems**

- **Count Subsets with Sum K**: Given an array, count the number of subsets whose sum equals a given target.
- **Find All Subsets with Sum K**: Similar to the previous problem, but output the subsets themselves.

### 13. **Game Theory Problems**

- **Nim Game**: Find the winner of a game where players take turns removing objects from piles.
- **Optimal Strategy for a Game**: Involves selecting moves that maximize the player's advantage.

### 14. **Bitmasking (DP with Bitmask)**

- **Traveling Salesman Problem (TSP)**: Find the shortest path that visits all cities and returns to the origin.
- **Subset Sum with DP and Bitmask**: Use bitmask to track subsets and DP to calculate possible sums.

### 15. **Dynamic Programming on Trees**

- **Tree DP**: Problems that involve finding the optimal solution by considering different subtrees of a tree.
    - Examples: Counting the number of paths, finding the longest path, or finding the diameter of the tree.

### 16. **DP with Strings**

- **String Matching and Regular Expressions**: Dynamic programming for pattern matching with wildcards or regex.
- **Palindrome Partitioning**: Given a string, partition it into the fewest palindromic substrings.

### 17. **Knapsack with Dependencies**

- **Task Scheduling**: Given tasks with dependencies, schedule them in a way that optimizes some criterion (e.g., minimizing makespan).

### 18. **Palindrome Subsequence Problems**

- **Max Palindromic Substring**: Find the longest palindromic substring in a string.
- **Palindrome Partitioning**: Partition a string into palindromic substrings with the minimum number of cuts.

### 19. **Subsequence with Maximum Sum**

- Given an array, find the subsequence such that the sum of the elements in the subsequence is maximized.

### 20. **Counting DP**

- **Counting Paths in Grid**: Count the number of distinct paths from one point to another in a grid, considering obstacles or constraints.
- **Counting Triangular Numbers**: Count how many different ways an integer can be expressed as the sum of triangular numbers.

### 21. **Bellman-Ford Algorithm**

- This is used for solving the shortest path problem in graphs with negative edge weights and detecting negative cycles.

### 22. **Maximum Subarray Sum (Kadane’s Algorithm)**

- **Standard Kadane’s Algorithm**: Find the maximum sum of a contiguous subarray.
- **Maximum Sum Subsequence with No Adjacent Elements**: Find the maximum sum subsequence such that no two elements are adjacent.

### 23. **Count of Palindromes**

- **Counting Palindromic Substrings**: Count how many palindromic substrings exist in a string.
- **Min Cuts to Make Palindrome**: Given a string, find the minimum number of cuts required to split the string into palindromes.

### 24. **Longest Common Substring**

- **LCS with Exact Matching**: Unlike subsequences, substrings are contiguous portions of the string.

### 25. **Counting Path Problems**

- **Count Paths in a Grid with Obstacles**: Use DP to count paths from one point to another in a grid with obstacles.

### 26. **Floyd-Warshall Algorithm (All Pair Shortest Path)**

- A DP approach to finding the shortest paths between all pairs of vertices in a weighted graph.

### 27. **Weighted Interval Scheduling**

- Given a set of intervals with associated weights, find the maximum weight of non-overlapping intervals.

### 28. **KnapSack with Limited Item Quantities**

- Each item can appear a limited number of times in the knapsack (similar to bounded knapsack).

---

### Common Patterns in DP Problems:

1. **Overlapping Subproblems**: The problem can be broken down into smaller subproblems that are solved multiple times. Storing the results of subproblems (memoization or tabulation) helps avoid redundant work.
2. **Optimal Substructure**: The optimal solution to the problem can be constructed from optimal solutions to its subproblems.
3. **Tabulation vs. Memoization**:
    - **Memoization** (Top-Down): Using recursion with a cache to store previously computed values.
    - **Tabulation** (Bottom-Up): Building up the solution iteratively using a table, typically avoiding recursion.

---

These concepts form the basis of most DP problems in competitive programming. Mastery of these will provide a strong foundation for solving a wide variety of optimization and decision-making problems.