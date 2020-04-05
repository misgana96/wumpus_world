## Wumpus World 

### Introduction

Wumpus world is a knowledge based AI game. In this game  an agent behave intelligently to decide where to go and what to do. He faces wumpus, pits, and other obstacles. When it gets the gold in the room then it gets score and won the game.

## wumpus world coordinates

|   (0,0)       |    (0,1)      |     (0,2)    |      (0,4)    |
|  :------- | :-------: |  :------: |  :-------:|
|       (1,0)   |    (1,1)      |     (1,2)      |       (1,3)    |
|        (2,0)   |     (2,1)      |      (2,2)     |     (2,3)      |
|     (3,0)      |      (3,1)     |     (3,2)      |      (3,3)     |

* four by four wumpus world
* room(3,0) is occupied by an agent
* room(2,0) and room(3,1) are safe room or okroom by default means the game start tis two rooms are not occupied by wumpus or pits and also gold 

### Assumptions

*  each room is represented with coorsinates of points represented with row and col
* row and col counting started from up and goes to down so that zero is min border and three is max border





### How to setup
``` 
mkdir build
```
```
cd build
```
### how to build
```
cmake ../
```
```
cmake --build .
```

				
				
				
				
### Perception

 An agent percept signals from adjacent rooms. If there is a wumpus adjacent to it then an agent percet stench and if there is a pit then it percepts a breeze and if their is a gold then the gold will glitter.