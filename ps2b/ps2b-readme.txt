/**********************************************************************
 *  N-Body Simulation ps2b-readme.txt
 **********************************************************************/

 *  N-Body Simulation (Universe) [Part B]
                                                                     
Computing IV - Assignment:PS2b
Instructor: Prof. Yelena Rykalova
Author: Anurag Akella
Due Date: 10/11/21

Operating system you're using (Linux, OS X, or Windows): Host OS - Windows, running Linux on Virtual Box

IDE or text editor you're using: Visual Studio Code to edit files, terminal commands/g++ to compile and run

Hours to complete assignment: 2 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

This assignment aims to create render a universe on screen.
It takes in poistion values for each planet/celestial bodies from a text file (using input redirects) and converts them to SFML coordinates.

These calculated values are then used to render the planets, in Part A.

Now, in part B, the code has a simple Physics Engine that can calculate forces and render movement for the planets

Extra
- A background 'stars' image was used to render a background.
- I added music (bgm.wav, Star Wars Theme)
- I added text that shows the elapsed time on the top left corner
- Own Universe: I used the same planets but added an extra comet that revolves around the sun in a smaller orbit.

 **********************************************************************/

  /**********************************************************************
 *  If you created your own universe for extra credit, describe it
 *  here and why it is interesting.

 I used the same planets and data that was given to me in PS2a, but I added an extra comet/asteroid with aribitary (non real world) data, that moves like a comet.
 I played around with the data and came up with some numbers that worked. These numbers make the body move like a coment.
 I'm not an expert and I'm not sure if its scietifically accurate but the path looks like a comet. (in 2D)

 To run this, use the planets.txt that I inclued in my submission and also make sure that the comet.gif file (also included in my submission)
 is in the same directory.

 this is the command I used, to test and run:
 ./NBody 157788000.0 25000.0 < planets.txt
 **********************************************************************/


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.

 I wrote everything myself.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.  

 I had some issues with the force calculations, I had to reset the force every frame, but I initially did not do that.
 I then figured it out and wrote an extra function that resets the forces and now it works.

 I also realised later that I had to flip the x and y axes to make the planets move counter clockwise. 
 (This was not an actual problem, but it was something I overlooked initially)                  
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.     

 No comments.                                
 **********************************************************************/