/**********************************************************************
 *  readme.txt
 *  PS4a
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Computing IV - Assignment - PS4a
Instructor: Prof. Yelena Rykalova
Author/Name: Anurag Akella (anurag_akella@student.uml.edu)
Due Date: 10/25/21

Operating system you're using (Linux, OS X, or Windows): Host OS - Windows, running Linux on Virtual Box

IDE or text editor you're using: Visual Studio Code to edit files, terminal commands/g++ to compile and run

Hours to complete assignment: ~30 minutes

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

I wrote a CircularBuffer that takes in input from one side and goes to the other side.
The API functions take care of the calculations and it can be used without knowing any internal detaisl

Extra Credit: used a lambda function for CircularBuffer::isEmpty()
 **********************************************************************/



/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.

This assignments uses a queue, a circular queue in particular.
I used a C array to internally represent the queue.

Used head and tail variables to keep track of the head and tail of the queue.

Used exceptions to handle the case when the queue is empty.
 **********************************************************************/



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.

enqueue() adds an element to the end of the queue.
dequeue() removes an element from the front of the queue.
isEmpty() returns true if the queue is empty.
isFull() returns true if the queue is full.
size() returns the size of the queue.

the constructor takes in a size and initializes the queue.

Included #include<exceptions> in the header file and used the exceptions to handle the errors.
1. when the init capacity is < 1 - makes no sense, queue cannot be size 0, so it throws an std::invalid_argument
2. when the queue is full and someone tries to enqueue more stuff, it throws a runtime_error (std::runtime_error).
3. similarly when the queue is empty and someone tries to peek or dequeue, it throws a runtime_error (std::runtime_error).

Testing was done with BOOST.
with #include <boost/test/unit_test.hpp>
and then used multiple BOOST_AUTO_TEST_CASE() to test the functions.

BOOST_REQUIRE_THROW was used to check for exceptions.
BOOST_CHECK_EQUAL was used to check for equality.
BOOST_REQIRE was used to check rest of the queue API.

Extra Credit: Used a lambda to check if the queue is empty.
 **********************************************************************/



/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.

Yes I completed the whole assignment.
Everything works as expected.

All of the API functions from the assignment are is working.

The BOOST tests show that the code is working as expected.
Ran a tests for the API functions with a few different inputs (test cases).
 **********************************************************************/



/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.

 Yes, it passes the unit tests.
 I know this from the terminal, the executable runs the boost tests.
 The output for ./ps4a is:
Running 7 test cases...

*** No errors detected

which shows that the boost tests have returned no errors, i.e all of the expected results are correct.
 **********************************************************************/



/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation

I used a C array, which should be good for performance and space.

the helper API functions are simple and they don't take up any space.
they just compare values and return the result, so they run in O(1) time and space.

the isEmpty function uses a lambda just for the extra credit so it might be a little slower than the other functions, and takes some extra space.
but it still is O(1) time and space.
(this difference is negligible)

The main functions of the queue, enqueue and dequeue, are O(1) time and O(1) space,
since they always insert at the end and remove from the front.

The size of the queue is fixed, so space complexity is O(n) for the whole queue, depending on what's passed to the constructor.

The prettyPrint function is O(n) time and O(1) space, since it prints the whole queue, depending on the size of the queue and what's in it at function call time.
 **********************************************************************/



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.

 None. Wrote everything myself.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.

 None, this was a simple assignment.
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.

 I used cpplint to check the code.
 cpplint expects header guards to be named with the full file path, but I didn't use the full path because it would be different for each PC.
 cpplint also checks for a git repo in the current directory, which doesn't return any errors.

 I added the git repo when I ran cpplint, but removed it before submission.
 **********************************************************************/
