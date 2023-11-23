# Hunt-the-Wumpus
Assignment4-CS162

I am creating a video game called Hunt the Wumpus. 
At the base level, this program contains/requires 5 classes: Game, Event, Wumpus, Stalactites, and Bats. 
The user traverses through a cave that is the size specified by the user(Cannot be less than 4x4).
An adventurer can move around using W, A, S, and D, and fire an arrow with F. 
In this cave, there are 4 “events”, each with their own properties. 
The First event is our antagonist, the Wumpus, which will kill you, ending the game if you wake him up. 
Your adventurer will wake him up by either: 
  walking into the room the Wumpus is sleeping in, 
  or by firing an arrow: He can move anywhere, even in the room you are in. 
The Second event is our goal, the Pot of Gold, once you find this pot of gold and retrieve it you must return to your starting point where you will use the same escape rope you used to get in.
The Third event is a hazard called, Super Bats. 
There are 2 rooms with Super Bats in the whole cave in total.
These Super Bats will disorient you, meaning you move in the opposite direction every time you move.
The Fourth event is a hazard called, Stalactites. There are 2 rooms with Stalactites in the whole cave total.
Rooms with Stalactites have a 50%-50% chance of a Stalactite falling. If it falls it will kill you, and you lose the game. 
There are percepts for each of these events that will print a message when the adventurer is in a room directly adjacent(east, south, west, or north).
The program continues until the adventurer dies or brings the gold home.
