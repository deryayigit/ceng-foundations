# Algorithms Basics Directory 

This directory contains implementations of fundamental mathematical and logical algorithms in C.

## Files

- Armstrong Numbers :
  If the sum of the n-th powers of its digits equals the number itself, then the number is called an Armstrong number.  
  Armstrong numbers have at least three digits.  

  Examples:  
  - 153 → 1³ + 5³ + 3³ = 153 → Armstrong number  
  - 1634 → 1⁴ + 6⁴ + 3⁴ + 4⁴ = 1634 → Armstrong number  

  👉 To test whether a number is an Armstrong number, see the code in [**armstrong_number.c**](./armstrong_number.c) 

  
  

- [**factorial_iterative.c**](./factorial_iterative.c)  
  Computes the factorial of a number using an **iterative (loop-based)** approach.  
  Example: 5! = 5 × 4 × 3 × 2 × 1 = 120.

- Leap year is a year introduced in the Gregorian calendar to keep the calendar year synchronized with the astronomical year.  
  The Earth completes one revolution around the Sun in approximately **365.2422 days**, not exactly 365 days.  
  To correct this discrepancy, an extra day (February 29) is added in certain years.  

  The rules are as follows:
  - Any year divisible by **4** is a leap year.  
  - However, if the year is divisible by **100**, it is **not** considered a leap year.  
  - Exception: if the year is also divisible by **400**, then it **is** a leap year.  

  This adjustment ensures long-term alignment between the civil calendar and the solar year.  

  **Examples:**  
  - 2020 → Leap year  
  - 1900 → Not a leap year  
  - 2000 → Leap year

   👉 To test whether a year is a Leap year, see the code in  [**isleap.c**](./isleap.c)


- [**isperfect.c**](./isperfect.c)  
  Checks whether a number is a **perfect number** (sum of its proper divisors equals the number itself).  
  Example: 28 → 1 + 2 + 4 + 7 + 14 = 28 → Perfect number.

- [**isprime.c**](./isprime.c)  
  Tests whether a number is a **prime number**.  
  Example: 7 → Prime, 9 → Not prime.

---












