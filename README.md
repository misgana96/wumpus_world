Wumpus world
===============
A program to demonstrate the well-known game in artificial intelligence, Wumpus World. This game is used to show different concepts in AI like proof theory, Decision making, Intelligent Agent and heavily utilize Deductive systems and semantic tableaux in proof theory.
## Game Description (Model)
In the game world (environment) there are 16 Rooms, 1 Agent, 1 Wumpus, 1 Gold, 3 pits and the following rules apply.
1. Rooms adjacent to Wumpus Stench.
2. Rooms adjacent to pit Breath.
3. Rooms with gold Glitter.
4. Agent has one Arrow.
5. If wumpus and Agent are in same room Wumpus will kill the Agent.
6. The wumpus, Agent, Gold and Pits are instantiated randomly in different rooms.
## Intelligent Agent
An agent is anything that can perceive and act on an Environment (World). It uses a procedure (Agent Function) to map a perception to action. The actual implementation of Agent Function is called Agent Program. Percept History, a complete history that the agent perceived is also used to decide what action the agent will perform next.
## Model based Reflex Agent
This type of agent will consider three things to its Decision making.
1. Model: - A general knowledge of the rules of the environment. Similar to the game model above.
2. Agent Internal State: - It represents current state of the agent based on percept History.
3. Deductive System: - The Agent Function must contain a deductive system that uses the current internal state and the model to make a decision.     
![Agent](https://github.com/misgana96/wumpus_world/Media/Agent.jpg)
## Actuators
The agent is controlled by the following signals
. Move forward: - The agent will get in the room in front of it, if there is no wumpus or pit.
. Turn Right: - the agent will turn to the right. 
. Turn left: - the agent will turn to the left.
. Shoot: - the agent will Shoot It's arrow to the room in front of it.
## Sensors 
The following sensor values dictate the current state of the Agent. 
. Stink: - Triggered when there is a wumpus in a room adjacent to the Agent. 
. Glitter: - Triggered when the agent is in the same room to the Gold.
. Breath: - Triggered when there is a Pit in a room adjacent to the Agent. 
. Bump: - Triggered if the Agent hits a wall.
. Scream: - Triggered if the Wumpus is hit by an arrow.
![Wumpus World](https://github.com/misgana96/wumpus_world/Media/Wumpus World.jpg)

 ## Knowlage Base
. Pij is true if there is a pit at room ij
. Bij is true if agent percive breath from room ij
. Wij is true if there is a wumpus at room ij
. Sij is true if agent percive stink a from room ij
. Vij is true if room was visited by the agent
. Gij is true if there is a glitter at room ij
. Ok ij is true if room ij is ok to visit


  

