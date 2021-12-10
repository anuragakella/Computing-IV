/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt
 **********************************************************************/

 *  N-Body Simulation (Universe) [Part A]
                                                                     
Computing IV - Assignment:PS2a
Instructor: Prof. Yelena Rykalova
Author: Anurag Akella
Due Date: 10/04/21

*-*-*-*-*-*-*-*
Readme Edit, Update - Submission #2 - I forgot to add a screenshot.png in my previous submission. 
I apologise for this, I have updated the folder with a screenshot.png and I submitted it again (submission #2)

Thank You.
*-*-*-*-*-*-*-*

Operating system you're using (Linux, OS X, or Windows): Host OS - Windows, running Linux on Virtual Box

IDE or text editor you're using: Visual Studio Code to edit files, terminal commands/g++ to compile and run

Hours to complete assignment: 2 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.


This assignment aims to create render a static universe (celestial bodies) on screen.
It takes in poistion values for each planet/celestial bodies from a text file (using input redirects) and converts them to SFML coordinates.

These calculated values are then used to render the planets, in Part A.

A background 'stars' image was used to render a background.

 **********************************************************************/

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or
 *  OO designs that were central to the assignment.

 - A C++ Vector (dynamic array) was used to store the celestial bodies inside a 'Universe' (class) object.
 - An Iterator was used to draw the CelestialBody objects in the SFML main loop.
 
 - No complex algorithms were used, except for some simple math, which includes scaling coordinates from planets.txt to SFML coordinates.
 
 - OO design: A CelestialBody class (or its objects, rather) holds all the data required to render a planet.
              Since it is an sf::Drawable class (inherited) it can be used by the window.draw() method to render stuff on the screen.

              All of these CelestialBody objects are stored in a vector (pointers) inside a Universe class object. 
              This object also contains some other info needed to render the universe

 **********************************************************************/





/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.

The rendering uses simple math to calculate the SFML coordinates.
The images/planets are stored as CelestialBody objects inside a vector inside a Universe object.

This is the calculation:

    rx = ((x/univRadius) * (screenw / 2)) + (screenw/2);
    ry = ((y/univRadius) * (screenh / 2)) + (screenh/2);

I have not used smart pointers in Part A, but will refactor for Part B of PS2a.

 **********************************************************************/




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.

 I wrote and designed everything myself.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.     

 I had no serious problems               
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.          

 I have no other comments                           
 **********************************************************************/