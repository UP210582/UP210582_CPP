<div align= "center">

## Conect 4

## Index
</div>

[Instruccions of  ejecution](#Instruccions-of-ejecution)  
[General considerations](#General-considerations)  
[Flow Diagram](#Flow-Diagram)  
[Development](#Development)  
[Conclusions](#Conclusions)  

<div align= "center">

## Instruccions of  ejecution
</div>
In order to enjoy the single player and multiplayer game modes, you first need to follow the steps below depending on the operating system.
<h2> Windows </h2>

1. Download or clone my repo with the following command in the terminal:
   
~~~
"git clone https://github.com/UP210582/UP210582_CPP.git"
~~~

2. Download and install the compiler in this link https://sourceforge.net/projects/mingw/files/OldFiles/ 
3. Open the terminal at the direction of the file with the command:

~~~
cd C:\Documents\...
~~~

4. To compile use command:

~~~
gcc  Conect4.cpp -o Conect4.exe
~~~

5. To run type this code:

~~~
Conect4.exe
~~~

<h2> Linux (Ubuntu)</h2>

1. Download or clone my repo with the following command in the terminal:
   
~~~
"git clone https://github.com/UP210582/UP210582_CPP.git"
~~~

2. Install GNU c/c++ compiler, open the terminal and type:

~~~
$ sudo apt-get update
$ sudo apt-get install build-essential manpages-dev
~~~

3. To compile this program, type:

~~~
gcc Conect4.c -o Conect4
~~~

4. To run this program, type:
   
~~~
.Conect4
~~~

This game has 2 modes, multiplayer and single player, to choose them just select 1 for multiplayer and 2 for single player, this will put it when the program requests it, if you have no idea how to play just select option 3 and it will show a small manual which will explain how to play it.

[Index](#Index) 

<div align= "center">

## General considerations
</div>

to start the game you can only put 1, 2 or 3 if you try to put another value which is not one of these the program will ask you to put a correct value to start the game, also when you are playing you can only select the columns because the game of connect 4 is played only by selecting the columns, the values of the columns go from 1 to 7 and have a height of 6 when the whole column is filled the program will tell you that this column is full and please select another one, also you have to take into account that only whole values are allowed, no decimals and special characters and letters because the program is not designed to work with these characters.
#### Player 1 is O
#### Player 2 is 0
#### Player Pc is 0
#### Negative values and characters are not accepted
#### In all modes Player 1 is the one who starts the games.

[Index](#Index) 

<div align= "center">

## Flow Diagram
</div>

<img src=https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/flowConect.png
alt="Sourcerer" width=300>

[Index](#Index) 

<div align= "center">

## Development
</div>



[Index](#Index) 

<div align= "center">

## Conclusions
</div>

This project was a real challenge because for the creation of the single player game mode we had to develop an intelligence that could predict the moves and use this prediction in their favor, for this we use a copy of the board with the moves already established, this intelligence reviews each of the squares and determines which of them will provide the victory, and with this we solved the difficult.

The code has nothing of order is not consecutive since we use the creation of functions which we can call to use them later and thus not to have to be repeating many times the same code which will do the same thing again and again, for it we had to create functions that were concise and precise to be able to call them again and again and thus to be more fluid and efficient the work.

Another challenge was to create the algorithm which would check all the squares adjacent to the move, since in the part to verify the diagonal moves the accumulator did not work efficiently to solve this we asked the teacher and he solved it.

[Index](#Index) 