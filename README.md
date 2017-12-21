# StateStack-and-ECS
[WIP] Demo of utility of state stacks to manage screens for a game.

## Goal of the project
Demonstrate use of state stacks to manage screens in a game project. Ultimately, this will be the game Pong, designed
with an Entity-Component-System architecture, wrapped in a screen management system built on a stack structure.

### The State Stack System
The system I'm using to manage screens works as a structure of nested state stacks. The top level state stack
moves from TitleScreen to MenuScreen to GameScreen. 

The Menu screen is broken down itself into two states: a MenuHome and MenuSettings screen. From MenuHome, you can
start a game, go to settings, or exit the application. 

Each state stack updates screens top to bottom, but renders them bottom to top. This provides the ability for lower
screens to be seen through upper screens, while upper screens retain control over what user functionality 
is allowed to fall through to lower screens. This is familiar in the case of a pause screen that shows animations
of the underlying screen continuing to run while game logic is paused.

### The Context struct
Context is a structure that is passed to every screen. It supplies data useful to every screen - the control layout,
the color scheme, resources like fonts, the window and user input events.

### Input handling
The input for this project is handled in the following way: 
1) An Input class catches events from the SFML window. This class, deriving from Subject, distributes the event 
   information to all registered Observers.
2) A screen that would like to use user input has a InputController class. The InputController instances observe
   the same single Input instance provided to them from the Context. Each screen provides their input controller
   with a structure mapping user input actions such as DOWN, UP, SELECT, to some screen action essentially using 
   lambda functions as callbacks.
3) The InputController combines the events received with the current control layout present in the context to
   execute the appropriate screen action.
   
In this way, input events are decoupled from input handling, and control layouts are decoupled from screen actions. 


## Todo
 * be able to move between game, pause screen, and menu
 * play an infinite game of pong against dummy AI
 * develop game structure (Games composed of rounds composed of [starting phase->game]), keep track
   of score, winner/loser screens, and such
 * add 2 player functionality by simply setting a flag in the Context that tells game to use two player controllers instead
   of one player and one AI controller.
