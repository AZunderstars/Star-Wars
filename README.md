# Star-Wars

Space shooting game implemented in C++

A game like Chicken Invaders using [RSDL library](https://github.com/UTAP/RSDL).

Fifth assignment for Advanced Programming course.

## Prerequisites

### Mac OS

1. Install HomeBrew

```
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

2. Install SDL packages with HomeBrew


```
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

### Linux

Run the command below to install SDL packages:

```
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev 
```

## How to Play

First compile the project using the command below:

```
make
```

Then use this command to run the game:
```
./starwars.out map.txt
```

<i>(You can edit the map too.)</i>

Controls are WASD and space. Destroy all enemies and watch out for friendly spaceships. Enjoy!

[Description](APS01-A1-Description.pdf)
