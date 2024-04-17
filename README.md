[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/p5HYa83c)
# Start Up Code for Polynomial Class

## Reflection
> This part of the assignment is to get you primed into writing README files for your portfolio,

Write a short reflection about this assignment. This can include:
- What was easy?
- What was hard?
- Was I ready for this assignment?
- What were my challenges? How did I overcome these challenges?
- What I liked about the assignment?
- What I didn't like about the assignment?

Additionally, include an image of your program running here.

## Purpose
The goal of this lab is to practice dynamic memory with a simple class. Additionally, you will have the opportunity to practice command line compilation and memory leak checking using valgrind.

## Design
This Polynomial class will store the coefficients of a one variable polynomial  in a dynamically created array. This class has two data members:
```c++
	size_t _degree;
	float* _coefficients;
```
It is straightforward to see what they represent.
For example:
![equation](https://latex.codecogs.com/gif.latex?7x%5E4-2x%5E2&plus;0.5x&plus;2.23)
would be:
```c++
	_degree = 4
	_coefficients => {2.23, 0.5, -2.0, 0.0, 7}
```
Notice that the array size is `_degree + 1`.

## What is given?

You are provided with the unit tests to test your code, and with the `Polynomial` class declaration.

## What is expected?
- Your code ***must*** compile.
- Your grade will be *almost* the percentage of your passed unit tests.
- Your code needs to show good programming practices: indentation, meaningful variable names, identifiers convention (CamelCase for functions, camelCase for variables, _camelCase for data members, SNAKE_CASE for constants), header comments, correct file names, etc. Failure to code appropriate will result in strong points penalization. See Canvas page *Good Programming Practices*.
- You will need to provide implementation of the following methods:
  ```c++
	Polynomial(size_t degree);                              // Constructor
	Polynomial(size_t degree, const float* coefficients);   // Constructor
	Polynomial(const Polynomial& other);                    // Copy Constructor
	~Polynomial();                                          // Destructor
	const Polynomial Sum(const Polynomial& rhs)const;       // Sum
	const Polynomial Subtract(const Polynomial& rhs)const;  // Subtraction
	const Polynomial Minus()const;                          // Minus (-f)
	const Polynomial Multiply(const Polynomial& rhs)const;  // Multiplication
	const Polynomial Divide(const Polynomial& rhs)const;    // Long Division (No reminder)
	const Polynomial Derive()const;                         // Derivation
	float Evaluate(float x)const;                           // Polynomial Evaluation
	float Integrate(float a, float b)const;                 // Integration 
	const Polynomial& operator=(const Polynomial& rhs);     // Copy Assignment Operator
	string ToString()const;                                 // Convert to String (See tests for format)
	bool Equals(const Polynomial& rhs)const;                // Checks if two polynomials are equal
	ostream& Write(ostream& output)const;                   // Writes to a stream (See tests for format)
	istream& Read(istream& input);                          // Reads from a stream (see tests for format)

    ```
- The following methods will count toward extra credit:
  1. Divide
  2. Integrate

## Brief description of the methods
- `Polynomial(size_t degree)`. Creates a polynomial of degree `degree`, dynamically allocates an array of size `degree + 1` and sets the coefficients to 0.0
- `Polynomial(size_t degree, const float* coefficients)`. Creates a polynomial of degree `degree` and with the values of the coefficients in the `coefficients` array
- `Polynomial(const Polynomial& other)`. Copy constructor, creates a deep copy of the `other` polynomial.
- `~Polynomial`. Destructor, deallocates the allocated memory.
- `const Polynomial Sum(const Polynomial& rhs)const`. Returns a polynomial that will contain the sum of `this` with `rhs`. Notice that this operation does not change `this`.
- `const Polynomial Subtract(const Polynomial& rhs)const`. Returns a polynomial that will contain the subtraction of `this` with `rhs`. Notice that this operation does not change `this`.
- `const Polynomial Minus()const`. Returns a polynomial that will contain the additive inverse of `this`. For instance if the polynomial is $p = 2x^2 - 2$, then `p.Minus()` would return $-2x^2 + 2$. Notice that this operation does not change `this`.
- `const Polynomial Multiply(const Polynomial& rhs)const`. Returns a polynomial that will contain the multiplication of `this` with `rhs`. Notice that this operation does not change `this`.
- `const Polynomial Divide(const Polynomial& rhs)const`. **EXTRA CREDIT**. Returns a polynomial that will contain the division of `this` with `rhs`. Notice that this operation does not change `this`. The reminder is lost if there was one.
- `const Polynomial Divide(const Polynomial& rhs, Polynomial& remainder)const`. **EXTRA CREDIT**. Returns a polynomial that will contain the division of `this` with `rhs`. The remainder will be placed in parameter by reference `remainder`.
- `const Polynomial Derive()const`. Returns a polynomial that will contain the derivative of `this`. Notice that this operation does not change `this`.
- `float Evaluate(float x)const`. Returns the value of evaluating the polynomial with value `x`. Notice that this operation does not change `this`.
- `float Integrate(float a, float b)const`. **EXTRA CREDIT**. Returns the value of the definite integral evaluated from `a` to `b`. Notice that this operation does not change `this`.
- `const Polynomial& operator=(const Polynomial& rhs)`. Assigns the polynomial `rhs` to `this`.
- `bool Equals(const Polynomial& rhs)const`. Returns `true` if `this` is equal to `rhs`.
- `string ToString()const`. GIVEN. Returns a `string` representation of the polynomial.
- `ostream& Write(ostream& output)const`. GIVEN. Writes a polynomial from the `output` stream.
- `istream& Read(istream& input)`. GIVEN. Reads a polynomial from the `input` stream.

## How to "make", run, and memory check your program
For this assignment you are expected to compile, run and do memory check of your code in the command line. Below you will find some instructions to do so. **All the instructions assume that you are located in your project directory**.

### Compiling and running your Code
This assignment includes a `makefile`. This is a file that has the instructions on how to compile your project. The `makefile` has three options:
- Default `make`, this one would compile `polynomial.cpp` and `main.cpp`. Use this when you want to try some method using the `main.cpp` file. Note that we will not grade your `main.cpp` use it just for your own personal tests. To make and run use the following commands:
  ```console
  make
  ./poly
  ```
- Making the test program. This will compile `polynomial.cpp` and `unit-test.cpp`. Use this to run the test script for this assignment. This will be the way that we will grade your lab. What you get on this test is going to be your raw-grade, that is your grade before the deductions that you may get for not following instructions, bad programming practices, etc. To make and run the test use the following commands:
  ```console
  make test
  ./test
  ```
- Compiling and running with a single command. You can make your program and run it with a single command by running the following command:
  ```console
  make run
  ```
- Compiling and running the memory checker. You can make your program and run `valgrind` on your program with a single command by running the following command:
  ```console
  make runmc
  ```


### Testing for Memory Leaks
To test for memory leaks we will use the test script. The following commands can be used:
```console
make test
valgrind --leak-check=full ./test
```
Make sure that your code reports 0 errors, having memory leaks will affect your grade.

### Cleaning your Directory
If you want, you can run the command below to delete the binary code files (.o files and executables):
```console
make clean
```

### Sample of the Command Line Output
#### Display the contents of your dictory
```console
root@4fe9645efc38:/development/CSC2431/polynomial-solution# ll
total 44
drwxr-xr-x 13 root root  416 Apr  5 15:53 ./
drwxr-xr-x 36 root root 1152 Apr  3 18:31 ../
drwxr-xr-x 13 root root  416 Apr  3 23:41 .git/
-rw-r--r--  1 root root  318 Apr  5  2022 .gitignore
drwxr-xr-x  9 root root  288 Apr  5 16:02 .idea/
-rw-r--r--  1 root root  193 Apr  3 20:24 CMakeLists.txt
-rw-r--r--  1 root root 4198 Apr  5  2022 README.md
drwxr-xr-x 10 root root  320 Apr  5 15:53 cmake-build-debug/
-rw-r--r--  1 root root  558 Apr  7  2022 main.cpp
-rw-r--r--  1 root root  487 Apr  3 23:49 makefile
-rw-r--r--  1 root root 5008 Apr  5 15:53 polynomial.cpp
-rw-r--r--  1 root root  907 Apr  5 15:53 polynomial.h
-rw-r--r--  1 root root 4288 Apr  5 15:53 unit-test.cpp
```
#### Default `make`
```console
root@4fe9645efc38:/development/CSC2431/polynomial-solution# make
g++ -c main.cpp -o main.o -std=c++14 -Wall -g
g++ -c polynomial.cpp -std=c++14 -Wall -g
g++ main.o polynomial.o -o poly -std=c++14 -Wall -g
root@4fe9645efc38:/development/CSC2431/polynomial-solution# ./poly
Running the Main Program
-2.50x^3 +0.00x^2 +2.00x^1 -1.00
3 -1 2 0 -2.5


+2.50x^3 -0.00x^2 -2.00x^1 +1.00
```
#### Making `test`
```console
root@4fe9645efc38:/development/CSC2431/polynomial-solution# make test
g++ -c unit-test.cpp -o test.o -std=c++14 -Wall -g
g++ -c polynomial.cpp -std=c++14 -Wall -g
g++ test.o polynomial.o -o test -std=c++14 -Wall -g
root@4fe9645efc38:/development/CSC2431/polynomial-solution# ./test
TEST PASSED (Constructor, degree=0                             ) Total Passed: 1
TEST PASSED (Constructor, degree=2                             ) Total Passed: 2
TEST PASSED (Constructor, degree=3, w/Array                    ) Total Passed: 3
TEST PASSED (Copy Constructor                                  ) Total Passed: 4
TEST PASSED (Read/ToString                                     ) Total Passed: 5
TEST PASSED (Write                                             ) Total Passed: 6
TEST PASSED (Sum                                               ) Total Passed: 7
TEST PASSED (Subtract                                          ) Total Passed: 8
TEST PASSED (Minus                                             ) Total Passed: 9
TEST PASSED (Multiplication                                    ) Total Passed: 10
TEST PASSED (Derivation                                        ) Total Passed: 11
TEST PASSED (Evaluation                                        ) Total Passed: 12
TEST PASSED (Copy Assignment Operator                          ) Total Passed: 13
Base Grade Tests Finished - - - - - - - - - - - - - - - - - -
100
TEST PASSED (Integration                                       ) Total Passed: 14
TEST FAILED (Long Division                                     ) **************
TEST FAILED (Long Division Quotient                            ) **************
TEST FAILED (Long Division Reminder                            ) **************
Extra Credit Tests Finished - - - - - - - - - - - - - - - - -
UNIT TEST FINAL GRADE = 107.692
107.692
```
#### Checking for Memory Leaks (and more)
```console
root@4fe9645efc38:/development/CSC2431/polynomial-solution# valgrind --leak-check=full ./test
==158== Memcheck, a memory error detector
==158== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==158== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==158== Command: ./test
==158==
TEST PASSED (Constructor, degree=0                             ) Total Passed: 1
TEST PASSED (Constructor, degree=2                             ) Total Passed: 2
TEST PASSED (Constructor, degree=3, w/Array                    ) Total Passed: 3
TEST PASSED (Copy Constructor                                  ) Total Passed: 4
TEST PASSED (Read/ToString                                     ) Total Passed: 5
TEST PASSED (Write                                             ) Total Passed: 6
TEST PASSED (Sum                                               ) Total Passed: 7
TEST PASSED (Subtract                                          ) Total Passed: 8
TEST PASSED (Minus                                             ) Total Passed: 9
TEST PASSED (Multiplication                                    ) Total Passed: 10
TEST PASSED (Derivation                                        ) Total Passed: 11
TEST PASSED (Evaluation                                        ) Total Passed: 12
TEST PASSED (Copy Assignment Operator                          ) Total Passed: 13
Base Grade Tests Finished - - - - - - - - - - - - - - - - - -
100
TEST PASSED (Integration                                       ) Total Passed: 14
TEST FAILED (Long Division                                     ) **************
TEST FAILED (Long Division Quotient                            ) **************
TEST FAILED (Long Division Reminder                            ) **************
Extra Credit Tests Finished - - - - - - - - - - - - - - - - -
UNIT TEST FINAL GRADE = 107.692
107.692
==158==
==158== HEAP SUMMARY:
==158==     in use at exit: 0 bytes in 0 blocks
==158==   total heap usage: 106 allocs, 106 frees, 79,298 bytes allocated
==158==
==158== All heap blocks were freed -- no leaks are possible
==158==
==158== For lists of detected and suppressed errors, rerun with: -s
==158== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

#### Cleaning
```console
root@4fe9645efc38:/development/CSC2431/polynomial-solution# make clean
rm test -f poly *.o
```
#### Trying to compile and run
```console
root@4fe9645efc38:/development/CSC2431/polynomial-solution# make run
./test
TEST PASSED (Constructor, degree=0                             ) Total Passed: 1
TEST PASSED (Constructor, degree=2                             ) Total Passed: 2
TEST PASSED (Constructor, degree=3, w/Array                    ) Total Passed: 3
TEST PASSED (Copy Constructor                                  ) Total Passed: 4
TEST PASSED (Read/ToString                                     ) Total Passed: 5
TEST PASSED (Write                                             ) Total Passed: 6
TEST PASSED (Sum                                               ) Total Passed: 7
TEST PASSED (Subtract                                          ) Total Passed: 8
TEST PASSED (Minus                                             ) Total Passed: 9
TEST PASSED (Multiplication                                    ) Total Passed: 10
TEST PASSED (Derivation                                        ) Total Passed: 11
TEST PASSED (Evaluation                                        ) Total Passed: 12
TEST PASSED (Copy Assignment Operator                          ) Total Passed: 13
Base Grade Tests Finished - - - - - - - - - - - - - - - - - -
100
TEST PASSED (Integration                                       ) Total Passed: 14
TEST FAILED (Long Division                                     ) **************
TEST FAILED (Long Division Quotient                            ) **************
TEST FAILED (Long Division Reminder                            ) **************
Extra Credit Tests Finished - - - - - - - - - - - - - - - - -
UNIT TEST FINAL GRADE = 107.692
107.692
```
#### Trying to compile and run the Memory Checker
```console
root@4fe9645efc38:/development/CSC2431/polynomial-solution# make runmc
valgrind --leak-check=full ./test
==162== Memcheck, a memory error detector
==162== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==162== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==162== Command: ./test
==162==
TEST PASSED (Constructor, degree=0                             ) Total Passed: 1
TEST PASSED (Constructor, degree=2                             ) Total Passed: 2
TEST PASSED (Constructor, degree=3, w/Array                    ) Total Passed: 3
TEST PASSED (Copy Constructor                                  ) Total Passed: 4
TEST PASSED (Read/ToString                                     ) Total Passed: 5
TEST PASSED (Write                                             ) Total Passed: 6
TEST PASSED (Sum                                               ) Total Passed: 7
TEST PASSED (Subtract                                          ) Total Passed: 8
TEST PASSED (Minus                                             ) Total Passed: 9
TEST PASSED (Multiplication                                    ) Total Passed: 10
TEST PASSED (Derivation                                        ) Total Passed: 11
TEST PASSED (Evaluation                                        ) Total Passed: 12
TEST PASSED (Copy Assignment Operator                          ) Total Passed: 13
Base Grade Tests Finished - - - - - - - - - - - - - - - - - -
100
TEST PASSED (Integration                                       ) Total Passed: 14
TEST FAILED (Long Division                                     ) **************
TEST FAILED (Long Division Quotient                            ) **************
TEST FAILED (Long Division Reminder                            ) **************
Extra Credit Tests Finished - - - - - - - - - - - - - - - - -
UNIT TEST FINAL GRADE = 107.692
107.692
==162==
==162== HEAP SUMMARY:
==162==     in use at exit: 0 bytes in 0 blocks
==162==   total heap usage: 106 allocs, 106 frees, 79,298 bytes allocated
==162==
==162== All heap blocks were freed -- no leaks are possible
==162==
==162== For lists of detected and suppressed errors, rerun with: -s
==162== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
root@4fe9645efc38:/development/CSC2431/polynomial-solution#
```



