/**********************************************************************
 *  readme.txt template                                                   
 *  PS7 Kronos 
 **********************************************************************/

Name: Anurag Akella (01990503)

Hours to complete assignment: Approx 1 hour

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes the assignment is complete, everything works.
The program reads .log files and generates .rpt files.
I know they work because the executable generates .rpt files with the required output.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
for '(log.c.166) server started' I used '(.*): (\(log.c.166\) server started.*)' 
because the log files have lines that have some time/date meta data followed by a ':' and then the log message -> (.*):

For the boot-end log message 'oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080' I used 
'(.*)\\.\\d*:INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*' to match the log message, which starts after an 'INFO:'

That's it.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/

I read the PDF to understand what kronos does, then looked at the log files and searched for the given log message.
Then built a regex around the message to eliminate the rest of the line from the log (time/date metadata, etc).

Then I opened the file in C++ and matched each line with the regex in a loop.
When I find a match, I print the needed log line + boot time to a .rpt file.

That's it.

/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
Yes, I used a lambda expression to print an error message.
If for some reason the regex contructor fails in the try block, a lambda expression prints the error message.

This has no specific purpose but I just put it there for extra points.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
None.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None. This was simple.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
None.
