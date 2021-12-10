/**********************************************************************
 *  readme.txt template                                                   
 *  Markov Model
 **********************************************************************/

Name: Anurag Akella

Hours to complete assignment: ~8-10 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The Markov Model predicts the next characters in a sequence of k length words called kgrams,
using statistical information about the kgrams that have been seen before.

The RandWriter class takes a string and order k as input and maps each kgram in the string to each
character following that kgram and it's frequency.

This class can now generate strings of any given length, using the kgrams that have been seen before.
The string's characters are based on the probabilities of the k-length strings that were stored in the hashmap

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The RandWriter class uses a 'nested' hashmap to store the kgrams and their frequencies.
The nested hashmap is a hashmap of hashmaps, where the outer hashmap is the kgram and the inner hashmap stores each character and its frequency.

Apart from that, rest of the class is pretty straightforward, and uses simple linear and O(n^2) algorithms.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
RandWriter's constructor takes a string and and the order of the kgrams as input.
It initializes and constructs the hashmap.

The k_Rand function generates a string of length n, using the hashmap that was generated.
The function just iterates through a kgram's character map (the nested, inner map) and appends them in a string.
Then it randomly returns a char from this string.

The freq function returns the frequency of a kgram by searching/traversing the string.
The second overloaded function returns the frequency of a character, which is simple and just looks it up in the hashmap;
> return ktable.at(k_gram).at(c);

The generate function generates a new string by just calling the rand function, until the desired output lenght is reached.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I think I did, although I'm not sure about minor errors that might occur with larger text inputs / text files and various character combinations.
I know they work, at least the basic functionality, because of the BOOST tests that I wrote in test.cpp



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, the BOOST tests pass.
I know it works because it outputs a success message and exits the program.


 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
Excptions are in the RandWriter class, and are used to handle the case where a the kgram and order lenghts are not compatible.

 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
Yes, I used a lambda expression at line 54 on RandWriter.cpp
It has no actual purpose, just returns the order variable 'k'


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
None.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None. Just took me some time to figure it out.

/**********************************************************************
 *  List any other comments here.
 **********************************************************************/
 None.