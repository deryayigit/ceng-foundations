## Basic Algorithms and Links

- ✨ ***Armstrong Numbers***:  
  If the sum of the n-th powers of its digits equals the number itself, then the number is called an Armstrong number.  
  Armstrong numbers have at least three digits. Also Armstrong numbers also called Narcissistic numbers.

  Examples:  
  - 153 → 1³ + 5³ + 3³ = 153 → Armstrong number  
  - 1634 → 1⁴ + 6⁴ + 3⁴ + 4⁴ = 1634 → Armstrong number  

  👉 To check if any integer entered instead of a fixed length is an Armstrong number, see the code in [**armstrong_number.c**](./armstrong_number.c) 

   📊 ***Complexity Analysis***:  
    **Time Complexity Analysis:**  
    Input cleaning loop: O(n) if strlen is stored once, otherwise O(n^2).  
    Counting digits (while loop): O(d), where d = number of digits.  
    Armstrong check (while loop with inner for): O(d * n) ≈ O(n^2).  
  
    **Space Complexity Analysis:**  
    Fixed-size arrays (input[100], cleaned[100]): O(1)  
    Constant number of variables: O(1)  

- 🔁 ***Iterative Factorial Calculate***:  
  Computes the factorial of a number using an **iterative (loop-based)** approach.  
  Example: 5! = 5 × 4 × 3 × 2 × 1 = 120.  

  👉 To test factorial calculation, see the code in [**factorial_iterative.c**](./factorial_iterative.c)  

   📊 ***Complexity Analysis***:  
    **Time Complexity Analysis:**  
    **Space Complexity Analysis:**  

- 📅 ***Leap Year***:  
  A year introduced in the Gregorian calendar to keep the calendar year synchronized with the astronomical year.  
  The Earth completes one revolution around the Sun in approximately **365.2422 days**, not exactly 365 days.  
  To correct this discrepancy, an extra day (February 29) is added in certain years.  

  The rules are as follows:  
  - Any year divisible by **4** is a leap year.  
  - However, if the year is divisible by **100**, it is **not** considered a leap year.  
  - Exception: if the year is also divisible by **400**, then it **is** a leap year.  

  👉 To test whether a year is a Leap year, see the code in [**isleap.c**](./isleap.c)  

  📊 ***Complexity Analysis***:  
  **Time Complexity Analysis:**  
  **Space Complexity Analysis:**  

- 💎 ***Perfect Number***:  
  A positive integer equal to the sum of all its divisors except itself.  In other words, numbers whose sum of divisors equals twice the number itself.

  Examples:  
  - 6 → 1 + 2 + 3 = 6 → Perfect number  
  - 28 → 1 + 2 + 4 + 7 + 14 = 28 → Perfect number  

  👉 To test whether a number is a Perfect number, see the code in [**isperfect.c**](./isperfect.c)  
    
     📊 ***Complexity Analysis***:  
      **Time Complexity Analysis:**  
      **Space Complexity Analysis:**  

- 🔑 ***Prime Number***:  
  A positive integer greater than 1 that has no divisors other than 1 and itself.  

  👉 To test whether a number is prime, see the code in [**isprime.c**](./isprime.c)  

   📊 ***Complexity Analysis***:  
    **Time Complexity Analysis:**  
    **Space Complexity Analysis:**  



