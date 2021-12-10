/**********************************************************************
 *  Linear Feedback Shift Register (part B)
                                                                     
Computing IV - Assignment - PS1b
Instructor: Prof. Yelena Rykalova
Author: Anurag Akella
Due Date: 27/09/21

Operating system you're using (Linux, OS X, or Windows): Host OS - Windows, running Linux on Virtual Box

IDE or text editor you're using: Visual Studio Code to edit files, terminal commands/g++ to compile and run

Hours to complete assignment: ~1 hour (give or take 15 minutes)
**********************************************************************/

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 This assignment aims to encode an image using a Linear Feedback Shift Register (Fibonacci).
 It XORs each pixel with a newly generated LSFR value.

 This encodes the image -> and this image is unique to the seed that was used to encode it, that is, if a new seed is given for the same input image,
 the output image will change.

 To decode an encoded image, the initial seed is needed. This seed has to be same seed that was used to encode the image.
 XORing each pixel value of the encoded image with bits generated from the same seed would reverse the encoding and 'decodes' 
 the image back to the original image.

 Additional feature: instead of accepting a seed, my program accepts an alphanumeric password which gets hashed into a binary string, which is used as a seed.
 **********************************************************************/


/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.

 Additional feature: instead of accepting a seed, my program accepts an alphanumeric password which gets hashed into a binary string, which is used as a seed.
 The hash function just does a logical operation with a fixed prime number constant and keeps multiplying it to extend the string.
 **********************************************************************/


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.

I wrote evertying on my own
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered. 

 None                   
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.        

 None                             
 **********************************************************************/
