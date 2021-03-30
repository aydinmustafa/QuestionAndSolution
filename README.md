## Solution of Triangle Maximum Sum Problem

### Description of the problem

You will have an orthogonal triangle input from a file and you need to find the maximum sum of the numbers according to given rules below;

*  You will start from the top and move downwards to an adjacent number as in below.
* You are only allowed to walk downwards and diagonally.
* You can only walk over NON PRIME NUMBERS.
* You have to reach at the end of the pyramid as much as possible.
* You have to treat your input as pyramid.

### How to run & compile

#### Compilation

~~~~~~~~~~~~~~~{.cpp}
   g++ -std=c++11 main.cpp -o executable
    
~~~~~~~~~~~~~~~

#### Execution

~~~~~~~~~~~~~~~{.cpp}
   ./executable
    
~~~~~~~~~~~~~~~

Program takes a string as an input which is named as '_s_' . String then converted into a 2D-array which resembles lower triangular matrix. Then obtained lower triangular matrix is used to find maximum possible sum obeying the rules above. In order for the no walking over of prime numbers constraint to be satisfied, all the prime numbers of the lower triangular matrix have been replaced with -100. 
