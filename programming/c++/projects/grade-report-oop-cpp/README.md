# Project TOPIC: CLASS REPORT

Midterm is approaching at your university. The registrar’s office wants to prepare grade reports as soon as students’ grades are recorded. However, some registered students have not yet paid their tuition fees.

1. If a student has paid the tuition, the grades and GPA are shown in the report.
2. If the student has not paid the tuition, grades are not printed. For these students, the report will contain a message stating that the grades are withheld due to unpaid tuition. The report should also display the invoice amount.

---

## Data Format

Data is stored in a file in the format below:

15000 345

studentName studentID isTuitionPaid numberOfCourses  
courseName courseNumber creditHours grade  
courseName courseNumber creditHours grade  
…  

studentName studentID isTuitionPaid numberOfCourses  
courseName courseNumber creditHours grade  
courseName courseNumber creditHours grade  
…

The first line shows the number of registered students and the tuition fee per credit hour. Student data is given afterward.

---

## Sample Input File

3 345

Lisa Miller 890238 Y 4

Mathematics MTH345 4 A  
Physics PHY357 3 B  
ComputerSci CSC478 3 B  
History HIS356 3 A

---

## Expected Output Format

Student Name: Lisa Miller  
Student ID: 890238  
Number of courses enrolled: 4

Course No | Course Name   | Credits | Grade  
--------- | --------------| --------| ------  
CSC478    | ComputerSci   | 3       | B  
HIS356    | History       | 3       | A  
MTH345    | Mathematics   | 4       | A  
PHY357    | Physics       | 3       | B  

Total number of credits: 13  
Mid-Semester GPA: 3.54

---

## Input / Output

**Input:** A file named "input.txt" containing the data in the format above.  
**Output:** A file containing the formatted student report.

---

# Problem Analysis and Algorithm Design

The program should use two main components: student and course.

---

## Course

The essential features of a course are its name, course number, and number of credit hours. Although the grade a student receives is not technically a feature of the course, it is included here for simplicity.

### Operations to be performed on a course object:

1. Edit course information  
2. Print course information  
3. Display credit hours  
4. Display course number  
5. Display grade  

![Course UML](https://github.com/user-attachments/assets/5e675a58-b248-4fd8-96bb-1cdb32c937fc)

---

## Student

A student’s essential features are student name, student ID, number of registered courses, the list of enrolled courses, and the grade for each course.

Since every student is required to pay tuition, add a member that indicates whether the student has paid.

Every student is a person and takes courses.

To process a person’s first and last name, design a class named **personType**.  
To track student information based on personType, derive a class named **studentType**.

### Operations to be performed on a studentType object:

1. Set student information  
2. Print student information  
3. Calculate total credit hours  
4. Calculate GPA  
5. Calculate billing amount  
6. Since the report prints courses in ascending order of course numbers, sort the courses accordingly.

![Student UML](https://github.com/user-attachments/assets/f1762925-1c1b-4d5d-bd07-29263c0c766a)
