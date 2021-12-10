/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Computing IV - Assignment:PS3
Instructor: Prof. Yelena Rykalova
Author: Anurag Akella
Due Date: 10/18/21

Operating system you're using (Linux, OS X, or Windows): Host OS - Windows, running Linux on Virtual Box

IDE or text editor you're using: Visual Studio Code to edit files, terminal commands/g++ to compile and run

Hours to complete assignment: ~3 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 I used some math to calculate the coordinates for the triangles and then used fTree to recusrively draw the triangles to the screen.
 **********************************************************************/



 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.

 I used a linked list (kind of) to recusrively link each triangle to its 'parent'.
 each triangle has 3 child triangles and each child has 3 more and so on, based on the input depth.

 This data structre is stored in the initialTriangle object, but I don't have to traverse through it because I drew the triangles while calling the functions.

 Basic OO concepts, classes, private public members, etc were also used.
 **********************************************************************/



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.

 - I drew the calculated tree to the window, but did not display it.
 - Then I captured the rendered window into an image, then into a texture and then into a sprite
 - Now I can do anything with the sprite.
 
 - Then I decided to add a simple pendulum animation (extra credit)
 - Then I also added colors to the image, which change randomly in the event loop (extra credit)
   * I also added color directly to the Triangle class, but I removed it later because the colors were being multiplied when I added them to the sprite.
   sf::Vertex line[] = {
        sf::Vertex(a1, sf::Color(100, 100, 150)),
        sf::Vertex(a2, sf::Color(100, 100, 150))
    }; // color add, directly
 **********************************************************************/



 /**********************************************************************
 *  Briefly explain what you learned in the assignment.

 I learned how I could work with sfml, figured out how to pass the window object and draw directly.
 Also looked at some school again math.
 **********************************************************************/



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.

 None, wrote everything myself.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working. 

 I had problems with handling recusrsion with sfml, the data structures and calculating coordinates but I eventually figured it out.             
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.           

 None, thank you                          
 **********************************************************************/