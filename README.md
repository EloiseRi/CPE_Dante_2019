# CPE_Dante_2019
Generate and Solve Mazes in C


### TURN-IN METHODS
You must have 2 folders : solver with a binary named “solver” in it, generator with binary named “generator” in it.
Each folder must contain a Makefile compiling the binary and a Makefile at the root must compile all binaries.
The Makefile at the root must compile all of the binaries.

```
∼/B-CPE-200> ls -R
. ..
solver generator Makefile
./ solver :
solver
[...]
./ generator :
generator
[...]
```
Each solver must be able to function as follows:
```
∼/B-CPE-200> ./solver maze.txt
```
and print the solved maze on the standard output.
If there is no solution you must print “no solution found” on the same output.
The generator must function as follows:
```
∼/B-CPE-200> ./generator x y [perfect]
```
As the perfect argument is optional, the default generation will be an imperfect maze.
You are allowed to add other optional arguments; you must show them during the Review.

### WHAT IS A MAZE ?
Here is the maze format description:
- Mazes are rectangular.
- They are coded in ASCII.
- The ‘X’s represent the walls and the’*’s represent the free spaces.
- It is possible to move to the four surrounding squares (up, down, right, left).
- “Start” is in the upper left-hand corner (0;0)
- “Finish” is in the bottom right-hand corner.
- A solution is a series of free, adjacent squares, from “Start” to “Finish” included.
- “Start” and “Finish” can be occupied. In this case, there is no solution.
- The last line of the maze doesn’t terminate with a return line.
- Resolution: in order to write the solution in the maze, we use ‘o’ for the solution path.
The Maze must be mazy enough.

### EXAMPLE 
Here is a 24x6 maze. . .
```
***** XX **** X ******** XXXX
XX ****** XX *** XXXXX *** XXX
XX *** XXXX ** XXXXX **** XXXX
XX *** XXXXXXXXXXXXXX **** X
***** XXXXXX **** XX *** XXXX
XX ************* XXXX *****
```
...and a way to solve it.
```
oooooXXooooXooooooooXXXX
XX ** ooooXXoooXXXXX * o * XXX
XX *** XXXX ** XXXXX *** oXXXX
XX *** XXXXXXXXXXXXXXo *** X
***** XXXXXX **** XX ** oXXXX
XX ************* XXXXooooo
```

### A PERFECT MAZE...
First, generate a perfect maze.
A perfect maze is a maze that has no loops and no clusters; therefore, following a wall makes us cross the entire maze.
The generation method is up to you, but it must work in an acceptable amount of time.
Input: maze size (width/height).
Output: a maze with the required size on the standard output.
The maze must have a solution.
The maze should be really perfect.
The maze should be really really perfect.

### LET’S MAKE A IMPERFECT MAZE... 
An imperfect maze must contain clusters.
The requirements are the same as for perfect mazes.
The generation method is up to you, but it must work in an acceptable amount of time.
Input: maze size
Output: a maze with the required size on the standard output.
The maze must have at least one solution.

### ESCAPING THE MAZE... 
Now it’s time to solve those mazes you’ve generated . . . and some more that our very very efficient AI generated for you.
Your resolution program should take the name of a file containing the maze and write the solution on the standard output.
You can choose the algorithm you want but be careful, you will be ask to solve perfect and imperfect mazes.

### PERFORMANCE
Generating and solving mazes is good, but how efficient are the algorithms you use?
Will you be able to deal with very large mazes?
Will you be able to do it quickly enough?
You will have to choose between RAM and CPU. . . think about it.
Measuring the speed of your program raises some points:
- the system-dependency: your machine is not always strictly in the same state when the program is launched (resource consumption, sticky bit,. . .),
- the maze-dependency: you will get different results for different types of mazes
- randomness: if it turns out that your algorithm uses randomness, the results will vary constently, even for the same maze.
You must take this into consideration when thinking about your analysis.
Your ability to objectively estimate your progress depends on it.

### FURTHER INTO OPTIMIZATION
Here you are, faced with yourselves for this ultimate test.
You are already equipped with the basics, but you have now to go faster!
There are a lot of possible optimizations, whether it be heuristic searches, data strcuture work, local optimizations, maze preprocessing,. . .
The maze complexity will be measured.
Be creative!

### HEURISTIC
When we simply scan our state space, you might get the idea to scan it in a slightly more enlightened manner.
You probably alrealdy integrated a heuristic! Didn’t you?
Be sure you are using the best possible heuristic.
Don’t forget to measure the newly obtained performance.
Is it more efficient? For all of the mazes?
