# ANTv2
***
## Table of Contents
1. [General Info](#general-info)
2. [Used Technologies](#used-technologies)
3. [Installation & System Requirements](#installation-&-system-requirements)
4. [Possible Problems](#possible-problems)
5. [Source Code](#source-code)
6. [License](#license)

## General Info
***
* About Antv2Exe: It is a reasearch program with the purpose to collect and analyze informations about human reaction time. The recorded data and the evaluation are saved in a csv file named after the test person. The program is split up in two phases: the Main Window and the Game Window.

### Phases
* In the Main Window you set all necessary informatons about the proband. You can find more detailed informations at [Main.md](/doc/Main.md) 
* In the Game Window you first get an exercise with extra informations, about your reaction. You can find more detailed informations at [Game.md](doc/Game.md)
* Researched Data: The use of the program is free and the data is only stored local at the user. 


## Used Technologies

* MinGW : Version 4.3.4
* Qt5 : Version 5.12.2
* C++ : Version 11

## Installation & System Requirement
***
### Windows
* System Requirement :
    1. Antv2 is build for Windows 10:
        1. [32bit](bin/32bit)
        2. [64bit](bin/64bit)
    2. All needed dlls for C++- and Qt5-libraries are delivered with the program.
    3. With the Source Code you can rebuild the Game for other OS versions and other OS.
* Installation :
    1. Unpack the downloaded archive where you whish to install it.
    2. To start the programm run the executable (Game32bit.exe or Game64bit.exe) in the 32bit or 64bit repository.

## Possible Problems
Avast could block the execution of the ANTv2 game through the Behavior shield.

## Source Code
* [ANTv2 & Qt5](https://github.com/hrafnass/ANTv2)

## License
Licensed under [GPLv3](LICENSE)
