/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Anurag Akella (01990503)

Hours to complete assignment: 2 hours

(look at bottom of file for extra credit explanation)

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg’s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/

I used dynamic programming (Needleman-Wunsch) with a matrix because it was simple and it was explained in class.
Filling the matrix is relatively simple using the formula + using 
std::min to fill the rest of the matrix.

pros:
+ easy to implement
+ simple and fast
+ performance is good

cons 
- it can be hard to understand the code when one looks at it without any context or information about the problem.



/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: 
atattat
tattata

Expected output:
Edit distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

What happened:

The output was correct, took 0.000421 seconds.

/**********************************************************************
 * Look at your computer’s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
I have 16 GB of RAM.
This means that my operating system can handle 16 GB of data at a time, which includes
all currenly running programs and all of their data/memory.
(like the icons in my code editor, the icons on my web browser, fonts, text data, other images, etc.)

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 0.  
b = 2

- for 4 bytes (int) and 24 bytes overhead per vector.

largest N = roughly 30000 (could be more, depends on many other factors too)

For a vector, each int is 4 bytes + the vector's size (C++, internal - vector properties) = approx 24 bytes.

Assuming 24 bytes per vector and 4 bytes per int that needs to be stored:

largest n at 8GB:
    I used a vector of vectors, MxN, so the parent vector has a length of M, 
    and each of the child vectors has a length of N.
    All of these hold ints, 4 bytes each.

    So for 1,000,000,000 bytes:
    
    24 + 24n + 4*n*n = 1000000000
    
    huge number, neglecting the the vector sizes, 4n^2 = 1000000000

    n = 22360.679775

    so approximately the max n is around 22000 (or more) (from my calculations)
    (reduced, because it has to store the input string too, an array of chars)

calculating for N = 7

24 + 24 * 5000 + 4*5000*5000 = 100120024 bytes
= ~100MB

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you’re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************

I ran valgrind and it recorded about 156.2 MiB of memory usage.
(I have attached the output file in this submission, massif.out.25289)
This is higher than the calculation above (100MB) and I believe it is 
because I did not calculate the size of the input string and other vector/object overheads.
Note that it also uses memory for printing the strings, creating objects, etc.

So the memory usage is close to the calculation in the question above. (for N=5000)


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
-----------------------------------------------------------------
ecoli2500.txt          118             1.3705          39.3 MiB 
ecoli5000.txt          160             5.775409        156.2 MiB   
ecoli7000.txt          194             10.7301         217.2 MiB
ecoli10000.txt         223             20.9834         622.2 MiB
ecoli20000.txt         3135            87.9346         2400 GiB    
ecoli28284.txt         8394            190.434         3400 GiB

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 0.0000002
b = 2

if we re-calculate the time for each N above for the ecoli data, with the formula:
0.0000002 * N^2, we get similar results to the above. (the table)

largest N = using the table of values above, I plotted a parabola for the time.
at 86400 seconds (24 hours), the n value is approx. 550000.

With the formula, it is 657267

So it can calculate a string with a lengh of around 650000, ON MY COMPUTER.
This might vary with the computer.

approx. 550000 < x < 660000, depending on other factors.

**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
yes, I used a simple lambda expression to calculate the penality.

method, EDistance.cpp:line 12

int EDistance::penalty(char a, char b){
  // lambda
  return [](char a, char b) {
    return a == b ? 0 : 1;
  }(a, b);
}

**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/

I used cplusplus.com for some info on vectors and the std::min function.
That's it.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None.


/**********************************************************************
 *  List any other comments here.     

***Extra credit***

std::min vs regular ifelse

Practical, I ran a main function with just the compare function (twice, 2 implementations) and used sf::Clock, etc
for time.

The min function with an if else block ran in:
Execution time is 1e-06 seconds //own

The min function with the std::min function ran in:
Execution time is 2e-06 seconds //system

The internal std::min function uses a template to compare the two values.
But we need to call this function 2 times, and store the value in a variable.
We can simplify this by directly using the min function inside another min() call, but we still call a function 
twice.

If a simple main function with just a comparision (no printing or inputs) is compiled into assembly,
we can see that the version that uses std::min is slower because we call 2 functions, which is more expensive.
Even without examining the assembly, we can see that the file is larger (#include, function call, etc)
We also store the final value in a variable, which is more expensive. (but optional)

But if we nest ifelse statements and use that to just compare the values and return the min, it would be
faster.
This is because here we just compare the values and nothing else.

This small differnce in time is neglegible and would not affect execution time, even for large inputs.
But for very very large inputs, this could shave off a few milliseconds.

The memory usage would depend on the implementation, but here too, the if else solution would use
less memory, because we use the variables in place [O(1)] and just compare the values.
Again, these differnces are neglegible and would not effect real-world performance.


Details:
Array method: vectors,
algorithm: Needleman-Wunsch,
OS: Ubuntu 20.04,
CPU: Intel Core i7-8550U (laptop), 16GB RAM
 **********************************************************************/

