# GameBooster [![Build Status](https://travis-ci.org/LBYPatrick/GameBooster.svg?branch=master)](https://travis-ci.org/LBYPatrick/GameBooster)
### About
A more effective solution for imporving gaming performance than Windows 10's brand-new Game Mode.
This is a 64-bit only program.

### How to Use
1.Simply Launch **GameBooster.exe** located under **build**.</p>
2.In the command prompt, you can use:

    GameBooster -i [INTERVAL]               //[INTERVAL] should be a number, in seconds.
	GameBooster --interval [INTERVAL]       //[INTERVAL] should be a number, in seconds.

To launch with a custom scanning interval. Longer interval might affect overall experience (Not boosting your game on time...).
Shorter interval gives your better performance, but might cause battery-sensitive devices to drain battery quicker
since shorter interval would stop your device from going to idle(low power) mode.
	
In general speaking, 30 seconds is the best (This is now the default value), or you can set to Android's notification interval, 4 minutes.

### How to add games that are not in the list

In ``processList.h``, there are three variables:
- ``num_games``  
- ``game_names``
- ``game_processNames``

1. Add the game name into ``game_names``
2. Add the process name of the game into ``game_processNames``
3. Finally, count the games in total and change ``num_games`` value.
4. Compile all cpp&h files under ``src`` with your favorite compiler.

Similar method applies to add programs that might have negative effect on compute performance 

