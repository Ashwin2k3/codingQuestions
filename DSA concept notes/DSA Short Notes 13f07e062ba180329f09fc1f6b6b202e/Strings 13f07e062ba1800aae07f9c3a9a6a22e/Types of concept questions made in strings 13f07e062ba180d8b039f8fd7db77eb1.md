# Types of concept / questions made in strings

In string-related problems, several fundamental concepts and techniques are frequently used in problem-solving. Here are the main concepts:

### **1. String Manipulation**

- **Reversal**: Reversing a string or a portion of a string.
- **Rotation**: Rotating the string by a given number of positions.
- **Concatenation**: Combining two or more strings into a single string.
- **Substrings**: Extracting substrings from a given string.

### **2. Pattern Matching**

- **Naive String Matching**: Simple approach to find a pattern in a string by checking each substring.
- **Knuth-Morris-Pratt (KMP)**: Efficient algorithm for substring search.
- **Rabin-Karp Algorithm**: Efficient hashing-based approach for pattern matching.
- **Z-Algorithm**: Useful for pattern matching and finding repeated patterns in linear time.

### **3. Palindrome**

- **Check for Palindrome**: Determine if a string is a palindrome (reads the same forward and backward).
- **Longest Palindromic Substring**: Finding the longest substring that is a palindrome.
- **Palindrome Partitioning**: Dividing a string into palindromic substrings.
- **Palindrome Permutation**: Check if any permutation of a string can form a palindrome.

### **4. Anagram**

- **Check if Two Strings are Anagrams**: Determine if two strings are anagrams (contain the same characters in any order).
- **Group Anagrams**: Group multiple strings into lists of anagrams.
- **Find the Smallest Window in String Containing All Characters of Another String**: Substring problems related to anagrams.

### **5. String Search & Matching Algorithms**

- **Rabin-Karp Algorithm**: Hashing-based search.
- **KMP Algorithm**: Efficient search using preprocessing.
- **Aho-Corasick**: Used for multi-pattern matching.

### **6. String Compression**

- **Run-Length Encoding**: Compressing a string by encoding consecutive characters with a single character and its count.
- **General String Compression**: Compressing a string using character counts (e.g., "aaabbb" -> "a3b3").

### **7. Substring Search**

- **Substring Search**: Finding a substring in a string (e.g., brute force or optimized with algorithms like KMP, Boyer-Moore, etc.).
- **Longest Common Prefix**: Finding the longest common prefix of two strings.
- **Longest Common Subsequence (LCS)**: Finding the longest subsequence that appears in both strings.

### **8. Edit Distance**

- **Levenshtein Distance**: Finding the minimum number of edits (insertions, deletions, or substitutions) required to convert one string to another.
- **Dynamic Programming**: Used for solving the edit distance problem efficiently.

### **9. String Matching with Wildcards**

- **Matching Wildcards**: Matching a string with wildcards like `` and `?` (commonly used in regular expressions or simplified pattern matching).

### **10. String Parsing and Tokenization**

- **String Splitting**: Dividing a string into substrings based on delimiters (e.g., splitting a sentence into words).
- **Tokenization**: Converting a string into tokens (e.g., for natural language processing or pattern matching).

### **11. String Hashing**

- **Rolling Hash**: A technique for efficiently computing hash values of substrings.
- **Polynomial Hashing**: Used for substring search or comparison.

### **12. String Transformation**

- **Conversion Between Cases**: Converting strings to uppercase or lowercase.
- **Character Shifting**: Shifting each character of the string by a fixed number of places (e.g., Caesar Cipher).
- **String Manipulation**: Replacing characters, trimming spaces, removing characters, etc.

### **13. String Matching with Regular Expressions**

- **Regular Expressions**: Pattern matching using regular expressions (e.g., checking for patterns like email addresses, dates, etc.).
- **Regex Backtracking**: Matching patterns through backtracking and dynamic programming.

### **14. Binary Search on Strings**

- **Binary Search in Lexicographical Order**: Searching for a target string in a sorted array of strings (e.g., finding the first or last occurrence).
- **Binary Search for String Matching**: Using binary search on string indices for matching.

### **15. Suffix Array & Suffix Tree**

- **Suffix Array**: A sorted array of all suffixes of a string.
- **Suffix Tree**: A compressed trie that represents all the suffixes of a string.
- **Longest Common Substring (LCS)**: Using Suffix Arrays or Suffix Trees to solve substring problems efficiently.

### **16. Bit Manipulation with Strings**

- **Binary String Operations**: Performing operations like AND, OR, XOR, NOT on binary strings.
- **Finding Subsets**: Using bit manipulation to find all subsets of a binary string.

### **17. Sliding Window Technique**

- **Sliding Window for Substrings**: Often used to find substrings with specific properties (e.g., longest substring with at most k distinct characters).
- **Windowed Searching**: Finding patterns or values in a moving window.

### **18. String to Integer Conversion (atoi)**

- **String to Integer**: Converting a string to an integer while handling signs and invalid input (similar to `atoi` in C/C++).

---

### **Common Problem Types Based on String Concepts:**

- **Find Palindrome Substring**: Given a string, find the longest palindromic substring.
- **Anagram Grouping**: Group strings into anagrams.
- **Edit Distance**: Find the minimum number of operations required to convert one string to another.
- **Pattern Matching**: Find all occurrences of a pattern in a string.
- **Substring Search**: Search for a substring in a string, or find all substrings that satisfy certain conditions.
- **Character Frequency Problems**: Find substrings with a specific frequency of characters or distinct characters.

---

These concepts cover most of the problems you might encounter in competitive programming or technical interviews based on strings. Understanding these basic techniques will give you a strong foundation in string manipulation and problem-solving.