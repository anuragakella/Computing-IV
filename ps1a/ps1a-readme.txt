/**********************************************************************
Linear Feedback Shift Register (part A)

A Simple SFML app.
Computing IV - Assignment - PS0
Instructor: Prof. Yelena Rykalova
Author/Name: Anurag Akella (anurag_akella@student.uml.edu)
Due Date: 20/09/21

Operating system you're using (Linux, OS X, or Windows): Host OS - Windows, running Linux on Virtual Box

IDE or text editor you're using: Visual Studio Code to edit files, terminal commands/g++ to compile and run

Hours to complete assignment: ~2 hours (give or take 15 minutes)
 **********************************************************************/

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 This assignment requires an implementation of a Linear Feedback Shift Register, specifically the Fibonacci LFSR.
 The inital seed (16 bit string) is used and left shifted.
 The shifted bit that is removed is used to perform an XOR operation with 3 fixed tap values (at 13, 12 and 10, given in the assignment problem)

 To perform the XOR, I directly used the string and used the '!=' operator, which is the same as performing an XOR operation.
 There was no need to perform any converstions, using this method.

 To perform an XOR with an int bit value (0, 1) and a character ('0', '1') a simple helper function was used which returns 0 or 1 using a simple if comparision.

 To perform the left shift, substr() was used, which is a part of std::string.
 The right most substring of the current string, excluding the first character (or bit in this case) is a simple left shift - this gives a 15 bit string.

 The calculated (XOR operations) end bit was appended to the subtring later to complete the shift operation, which returns it to its original 16 bits.

This logic was used in the step() function which can be called, and is also internally called when the generate(int) function is called.
 **********************************************************************/


/**********************************************************************
 *  Explain the representation you used for the register bits
 *  (how it works, and why you selected it)

 For the register bits, I decided to use the string itself, directly.
 The individial bits can be used by using [] since it is a character array - each bit is one character.

 I selected this because - its simple.
 It might not be the most efficient way to do it (not sure) but it is simple to implement and understand.

 built-in string functions and a simple XOR function were used to do the calculations.
 **********************************************************************/


/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests

 In my additional boost tests, I tested
 1. A 20 bit random seed.
 2. Another 16 bit random seed

 This makes sure that the implementation is working. The tests would fail if there's a logical error in the calculations.
  **********************************************************************/


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.

 I wrote all of the code on my own.
 I took some help from the link given in the assignment PDF, to overload the << operator.
 from here: http://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
 (this was given in the assignment PDF)
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.

I did not encounter any serious problems.
 **********************************************************************/
