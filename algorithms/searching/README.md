## 🔍 Searching Algorithms

Searching algorithms are techniques used to find a specific element within a collection of data.  
In other words, they define **how we look for something in a dataset** — step by step, until the target is found (or confirmed missing).  

The two most common approaches are:  
- **Linear Search:** checks each element one by one.  
- **Binary Search:** works by repeatedly dividing the search space in half (only for sorted data).  

---

### 1. Linear Search (Doğrusal Arama)

- **Definition:**  
  Starts from the first element and checks each item one by one until the target value is found or the list ends.  
  If the target is found, the algorithm returns its index; otherwise, it usually returns `-1` or `"Not found"`.  

- **Use Case:**  
  Mostly used in **unsorted small datasets**.  

**Pseudo Code:**

LinearSearch(collection, key):
    for each element in collection:
        if element == key:
            return index
    return "Not found"


Complexity Analysis:

Best Case: O(1) → Target is at the first element.

Worst Case: O(n) → Target is at the last element or not in the list.

Average Case: O(n)

Auxiliary Space: O(1) → Only a loop variable is used.

### 2. Binary Search (İkili Arama)

**Definition:**
Works on a sorted array by repeatedly dividing the search interval into two halves.
At each step, it compares the middle element with the target value and narrows the search space accordingly.

**Use Case:**
Suitable for large, sorted datasets where efficiency is important.

**Pseudo Code:**
binarySearch(collection, key):
    left = 0
    right = length(collection) - 1
    while left <= right:
        mid = (left + right) // 2
        if collection[mid] == key:
            return mid
        elif collection[mid] < key:
            left = mid + 1
        else:
            right = mid - 1
    return "Not found"


Complexity Analysis:

Best Case: O(1) → Target is the middle element.

Worst Case: O(log n) → Search space halves continuously.

Average Case: O(log n)

Auxiliary Space: O(1)
