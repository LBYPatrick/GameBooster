# GameBooster
### About
A more effective solution for imporving gaming performance than Windows 10's brand-new Game Mode.
This is a 64-bit only program.

### How to Use
1.Simply Launch **GameBooster.exe** located under **build**.
2.In the command prompt, you can use:

    GameBooster -i [INTERVAL]               //[INTERVAL] should be a number, in seconds.
	GameBooster --interval [INTERVAL]       //[INTERVAL] should be a number, in seconds.

to launch with your preferred scanning interval(Longer interval may help to alleviate CPU usage)

You should close the program when it boosted the game you want (since the scanning process actually consumes a lot of CPU power).

### How to add games that are not in the list

In **gameList.h**, there are three variables:
- **num_games**  
- **game_names**
- **game_processNames**

1. Add the game name into **game_names**
2. Add the process name of the game into **game_processNames**
3. Finally, count the games in total and change **num_games** value.
4. Compile all cpp&h files under **src** with your favorite compiler.


