# Array Most Important Algorithms

Here are some of the most commonly asked and widely applicable **array-based algorithms** that are highly useful in problem-solving:

---

### **1. Kadane’s Algorithm (Maximum Subarray Sum)**

- **Problem**: Find the maximum sum of a contiguous subarray.
- **Application**:
    - Solving problems related to subarray sums.
    - Variants include finding the maximum circular subarray sum.
- **Complexity**: \(O(n)\).

---

### **2. Two-pointer Technique**

- **Problem**: Solve problems like finding pairs, triplets, or subarrays with specific properties.
- **Application**:
    - Find two numbers that sum to a given value.
    - Check if an array is a palindrome.
    - Count pairs with a difference of \(k\).
- **Complexity**: \(O(n)\) or \(O(n \log n)\) with sorting.

---

### **3. Sliding Window Algorithm**

- **Problem**: Solve problems related to fixed-size or dynamic-size subarrays.
- **Application**:
    - Find the maximum/minimum in all subarrays of size \(k\).
    - Longest substring with at most \(k\) distinct characters.
    - Longest subarray with sum at most \(k\).
- **Complexity**: \(O(n)\).

---

### **4. Dutch National Flag Algorithm (Three-way Partitioning)**

- **Problem**: Rearrange elements in an array into three groups (e.g., 0s, 1s, and 2s).
- **Application**:
    - Sort an array of 0s, 1s, and 2s.
    - Partition an array based on a pivot.
- **Complexity**: \(O(n)\).

---

### **5. Merge Intervals**

- **Problem**: Merge overlapping intervals.
- **Application**:
    - Scheduling problems (e.g., meeting room problems).
    - Identify free time slots.
- **Complexity**: \(O(n \log n)\).

---

### **6. Binary Search (and Variants)**

- **Problem**: Search for elements or optimize problems using sorted arrays.
- **Application**:
    - Find the first/last occurrence of an element.
    - Search in a rotated sorted array.
    - Find the minimum in a rotated sorted array.
    - Median of two sorted arrays.
- **Complexity**: \(O(\log n)\).

---

### **7. Prefix Sum and Difference Array**

- **Problem**: Efficiently calculate sums or manipulate ranges in arrays.
- **Application**:
    - Range sum queries.
    - Longest subarray with a given sum.
    - Update ranges in \(O(1)\) using difference arrays.
- **Complexity**: \(O(n)\) for preprocessing, \(O(1)\) per query.

---

### **8. Partitioning Algorithms**

- **Problem**: Rearrange elements based on specific properties.
- **Application**:
    - QuickSort partitioning.
    - Partition array into two subsets with minimal sum difference.
- **Complexity**: \(O(n)\).

---

### **9. Monotonic Stack/Deque for Arrays**

- **Problem**: Solve problems involving the next/previous greater or smaller elements.
- **Application**:
    - Maximum of all subarrays of size \(k\).
    - Find the nearest greater/smaller element to the left or right.
- **Complexity**: \(O(n)\).

---

### **10. Longest Increasing Subsequence (LIS)**

- **Problem**: Find the length of the longest increasing subsequence.
- **Application**:
    - Analyze trends in stock prices.
    - Variants include maximum sum increasing subsequence.
- **Complexity**: \(O(n^2)\) (DP) or \(O(n \log n)\) (binary search + DP).

---

### **11. Majority Element Algorithms**

- **Problem**: Find the element that occurs more than \(n/2\) times or \(n/k\) times.
- **Application**:
    - Boyer-Moore Voting Algorithm.
    - Frequency-based analysis.
- **Complexity**: \(O(n)\).

---

### **12. Merge Sort**

- **Problem**: Sort an array and solve inversion count problems.
- **Application**:
    - Sorting.
    - Count inversions (number of pairs where \(arr[i] > arr[j]\) for \(i < j\)).
- **Complexity**: \(O(n \log n)\).

---

### **13. XOR-based Problems**

- **Problem**: Solve problems using XOR properties.
- **Application**:
    - Find the missing number in an array of size \(n\).
    - Find the number that appears once while all others appear twice.
- **Complexity**: \(O(n)\).

---

### **14. Matrix to Array Conversion (Spiral Traversal)**

- **Problem**: Traverse a 2D matrix in a spiral order.
- **Application**:
    - Convert a 2D matrix into a 1D array for specific patterns.
- **Complexity**: \(O(n \times m)\).

---

### **15. Greedy Algorithms for Arrays**

- **Problem**: Solve optimization problems.
- **Application**:
    - Minimize the maximum difference between array elements after \(k\) modifications.
    - Partition labels in arrays.
- **Complexity**: Problem-dependent, generally \(O(n \log n)\) or \(O(n)\).

---

### **16. Fast Median/Order Statistics**

- **Problem**: Find the \(k\)-th smallest/largest element.
- **Application**:
    - Quickselect algorithm for median finding.
    - Top \(k\) largest elements.
- **Complexity**: \(O(n)\) on average.

---

### **17. Counting Sort and Variants**

- **Problem**: Sort arrays with limited range efficiently.
- **Application**:
    - Frequency analysis.
    - Bucket/Counting/Radix sort for non-comparative sorting.
- **Complexity**: \(O(n + k)\).

---

These algorithms cover a wide range of problems, including optimization, searching, sorting, and dynamic programming, making them essential for solving competitive programming and real-world challenges.