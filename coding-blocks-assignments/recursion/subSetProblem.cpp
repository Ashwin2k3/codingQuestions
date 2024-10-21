/*
   Subset_problem ( Recursion )
Medium
Difficulty
146
Submissions
100
Max Points
Status: Not Attempted

0/100 Points
Problem
Submissions
Leaderboard
Discuss
Take an input N, a number. Take N more inputs and store that in an array. Take an input target, a number

a. Write a recursive function which prints subsets of the array which sum to target.

b. Write a recursive function which counts the number of subsets of the array which sum to target. Print the value returned.


Input Format
Take an input N, a number. Take N more inputs and store that in an array. Take an input target, a number


Constraints
None


Output Format
Display the number of subsets and print the subsets in a space separated manner.


Sample Input
3
1
2
3
3
Sample Output
1 2  3
2
Explanation
Add 2 spaces between 2 subset solutions
*/

/*
   https://hack.codingblocks.com/app/contests/5814/131/problem
*/
#include <iostream>
#include <vector>
using namespace std;

void findt(vector<int>& arr, int i, int target, vector<int>& subset) {
    if (target == 0) {
        for (int x : subset) cout << x << " ";
        cout << "  ";
        return;
    }
    if (i == arr.size() || target < 0) return;
    subset.push_back(arr[i]);
    findt(arr, i + 1, target - arr[i], subset);
    subset.pop_back();
    findt(arr, i + 1, target, subset);
}

int countSubsets(vector<int>& arr, int i, int target) {
    if (target == 0) return 1;
    if (i == arr.size() || target < 0) return 0;
    return countSubsets(arr, i + 1, target - arr[i]) + countSubsets(arr, i + 1, target);
}

int main() {
    int N, target;
    cin >> N;
    vector<int> arr(N), subset;
    for (int &x : arr) cin >> x;
    cin >> target;
    findt(arr, 0, target, subset);
    cout << "\n" << countSubsets(arr, 0, target);
    return 0;
}

