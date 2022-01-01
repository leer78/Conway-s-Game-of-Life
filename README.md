# Conway-s-Game-of-Life
Conway's Game of Life is a simple but intriguing tile based simulation which develops based on initial conditions

After stumbling upon some interesting Youtube videos regarding this cell game, I challenged myself to code it. The general code was quite easy to program in C, as the rules for the next "stage" of life are simple. Taken from the internet:

In the Game of Life, a few simple rules regarding changes of state result in a mathematical system that is
unpredictable in it’s results. Some very cool configurations are possible as well https://www.youtube.
com/watch?v=R9Plq-D1gEk.
The Rules of the Game of Life are as follows:
  • All cells in the game are either alive or dead.
  • The cells are arranged in a regular grid, in much the same way as pixels in a screen (completely
  co-incidentally as it turns out).
  • If a living cell has fewer than two living neighbours, that cell dies from under-population.
  • If a living cell has greater than three living neighbours, that cell dies from overpopulation.
  • So, if a living cell has exactly two or three living neighbours, that cell remains alive.
  • If a dead cell has exactly three living neighbours, it becomes alive (think reproduction, not zombies).
  • A cell is adjacent if (and only if) it is one cell to the left, right, up, down, or diagonally in any
direction. So, each cell has eight neighbour cells.
The state of the board progresses according to the above rules. When all cells on the board achieve their
next state according to the above rules, we have taken one Conway step.


To play the game, I've included several files. To change the starting inputs, alter the initial conditions where in "gameinput.txt" the first line represents the height of the board, the second line represents the width of the board, and the third line is a 2D representation of a 3D board. The 1s indicate live cells, and the 0s represent dead ones. 

![image](https://user-images.githubusercontent.com/74937113/147858753-ed28aaee-74af-408a-af0a-be884dc6f0f2.png)

....


![image](https://user-images.githubusercontent.com/74937113/147858756-ae13b550-8753-429e-b42f-c427f26059eb.png)
