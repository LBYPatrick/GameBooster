# GameBooster [![Build Status](https://travis-ci.org/LBYPatrick/GameBooster.svg?branch=master)](https://travis-ci.org/LBYPatrick/GameBooster)
### About
A more effective solution for imporving gaming performance than Windows 10's brand-new Game Mode.


The release version is for 64-bit Windows OS exclusively. You might need to build it by yourself if you are using 32-bit Windows OS. 

### How to Use
1.Download the latest release (exe file).</p>
2.In the command prompt, you can use:

    GameBooster -i [INTERVAL]               //[INTERVAL] should be a number, in seconds.
	GameBooster --interval [INTERVAL]       //[INTERVAL] should be a number, in seconds.

To launch with a custom scanning interval. Longer interval might affect overall experience (Not boosting your game on time...).
Shorter interval gives your better performance, but might cause battery-sensitive devices to drain battery quicker
since shorter interval would stop your device from going to idle(low power) mode.
	
In general speaking, 30 seconds is the best (This is now the default value), or you can set to Android's notification interval, 4 minutes.

### Build

Compile all cpp&h files under ``src`` with your favorite compiler **OR** just use ``Compile_MinGW.bat`` if you have MinGW or MinGW-W64 installed.


