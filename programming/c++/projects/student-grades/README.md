# Project Description

This assignment aims to provide a practical experience in basic array operations, file input/output operations, and simple object creation using the C++ programming language. Important details about the assignment are provided below.

## Assignment Explanation

1. A class object will be created by reading data from a file named **girdi.csv**.  
The file contains the following fields:
   
   a. Name → `string[]`  
   b. Number → `string[]`  
   c. Midterm → `float[]`  
   d. Second Exam → `float[]`  
   e. Project → `float[]`  
   f. Final → `float[]`  
   g. Attendance → `int[]`

Each field in the file is separated by commas, and their types are as listed above.  
The specified link for **input.csv** may be used.

2. The name of the class to be created must be **Student**, and the values read from the file should be assigned to the corresponding variables.

3. The designed class must include the following methods: **constructor**, **destructor**, **readFromCSV()**, **average()**, and **print()**.

   a. `constructor` → used to initialize variables and create dynamic arrays.  
   b. `destructor` → used to delete dynamically allocated arrays.  
   c. `readFromCSV()` → used to read data from the file and assign them to variables.  
   d. `average()` → calculates the average score using the following weights:  
      Midterm (20%), Second Exam (20%), Assignment (20%), and Final (40%).  
   e. `print()` → displays the formatted student list on the screen.  
      This method should display:  
      - the entire list when the argument is (-1)  
      - the failed students when the argument is (0)  
      - the passed students when the argument is (1)  
      A score of **50** will be considered the passing threshold.  
   f. `print()` (overloaded) → if the method receives a string argument, the output should be written to a file.

4. Apart from these methods, additional methods may be implemented; however, the inclusion of these four methods is mandatory for the assignment.



