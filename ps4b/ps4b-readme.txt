/**********************************************************************
 *                                                  
 *  PS4b: StringSound implementation and SFML audio output 
 **********************************************************************/


Computing IV - Assignment - PS4b
Instructor: Prof. Yelena Rykalova
Author/Name: Anurag Akella (anurag_akella@student.uml.edu)
Due Date: 10/25/21

Hours to complete assignment : 1 hour (approx.)

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.

 Yes, everything works. 
 I know they work because the app produces a sound. And the sound is identical to the musical notes that can be played at
 that frequency.
 **********************************************************************/



/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  

    Yes, I attempted the extra credit parts.
    I did not modify the main algorithm that averages the buffer's end points, but I changed the initial buffer value.
    Instead of using random noise, I used a sine wave. I generated this in the pluck() function using <math.h>'s sin function.

    This sound resemebles a piano (close).

    This was the only extra credit task that was mentioned in the assignment rubic, and since modifyng the algorithm in anyway 
    to produce a different sound was the extra credit part, I think this counts as extra credit.
 **********************************************************************/


/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.

    Yes, I implemented the exceptions.
    I did this by throwing an exception when the class recieves an invalid API call or input, in the CircularBuffer class.
    -> std::invalid_argument
    -> std::runtime_error

    I also implemented the exceptions in the StringSound class -> it catches the exceptions thrown in the CircularBuffer class.
    using something like this, for dequeue.
    It'll catch an error when you try to dequeue from an empty buffer.
    try {
        int16_t val = buffer -> dequeue();
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    Similarly, it'll catch an error when you try to peek from an empty buffer and
    it'll catch an error when you try to enqueue to a full buffer.
 **********************************************************************/



/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.

 Yes, I used a simple lambda in the CircularBuffer class, when I check if the queue is empty.
 **********************************************************************/



/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.

 Yes, it did. I just ran cpplint <filenae> to check the code.
 It might throw an error about the header guards, but that is computer specific and I think it shouldn't be
 considered a cpplint error.
 If 0 errors are needed, then init a sample git repo in the root dir and it should pass.
 **********************************************************************/


/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.

 None.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.        
 None.              
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.            
 None.                         
 **********************************************************************/
