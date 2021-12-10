**********************************************************************                                                                       
A Simple SFML app.
Computing IV - Assignment - PS0
Instructor: Prof. Yelena Rykalova
Author: Anurag Akella
Due Date: 13/09/21

Operating system you're using (Linux, OS X, or Windows): Host OS - Windows, running Linux on Virtual Box

IDE or text editor you're using: Visual Studio Code to edit files, terminal commands/g++ to compile and run

Hours to complete assignment: ~1 hour (give or take 15 minutes)

**********************************************************************



**********************************************************************
 *  Part of Assignment 0 is to read the collaboration policy in syllabus.
 *  
 *  If you haven't done this, please do so now.
 *
 *  Read the University policy Academic Integrity,
 *  and answer the following question:
 *
 * There are six examples of academic misconduct, labeled (a) through
 * (f). Other than (a), "Seeks to claim credit for the work or efforts
 * of another without authorization or citation," which of these do you
 * think would most apply to this class, and why? Write approx. 100-200
 * words.
 *
 * Note: there is no single correct answer to this. I am looking for
 * your opinion.
 
 ---
 
 In my opinion, examples (b), (e), (f) would apply to this class.
 Unauthorized code could be used by anyone, for any of the assignments. 
 For any future assignments, if applicable, any student can falsely represent grades and points.
 And for any of these, a student can assist another student. 
 A lot of free code is available online and depending on the licenses, some code cannot be freely used.
 Some need atrribution/citation and some can be used freely. 
 Not citing any external sources properly would probably come under academic misconduct.
 **********************************************************************



/**********************************************************************
 *  List whatever help (if any) you received from TAs, the instructor,
 *  classmates, or anyone else - 
 
I used the SFML website and the assignment instructions to understand how it works and wrote everything on my own.
 **********************************************************************



/**********************************************************************
*  Describe any serious problems you encountered -

I recently changed my battery, which reset my CMOS settings, and virtualbox wouldn't run any VMs because it thought VT-x was disabled (even when it was ON).
Wasn't a big issue though, took me a minute, changed my BIOS settings and it was done.   
 **********************************************************************



/**********************************************************************
The app's reqirements were:
1. drawing an image sprite 
2. make the image sprite move 
3. make the image sprite respond to keystrokes 
4. make it do something else

This app is a simple SFML app that loads an image as a texture and displays that image as a sprite (requirement 1).
The movement keys can be used to move the sprite around the screen (requirements 2 and 3), but cannot be moved outside the viewing window.  

Additional Feautures:
1. When the user presses the spacebar key, a bullet/projectile is launched from the sprite's body - in the last moved direction.
   e.g. If the sprite was moving left and the user presses space right then, the bullet will be launched towards the left of the screen. (reqirement 4)
   
2. Disco Mode: If the user presses the 'D' key when the app is running, the background will cycle through different colors.
   To disable disco mode, the user can press 'F' on the keyboard. (just a fun additional feature)                               
 **********************************************************************
