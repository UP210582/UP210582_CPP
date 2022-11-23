<div align= "center">

<h1 style="font-weight:normal">
  <a href="https://sourcerer.io">
    <img src=https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/tic-tac-toe-robot.gif 
    alt="Sourcerer" width=70>
  </a>
  &nbsp;TicTacToe Game&nbsp;
</h1>


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
<details close="open">

</div align="center">

In order to enjoy the single player and multiplayer game modes, you first need to follow the steps below depending on the operating system.
<h2> Windox </h2>

1. Download or clone my repo with the following command in the terminal:
   
~~~
"git clone https://github.com/UP210052/UP210052_CPP.git"
~~~

2. Download and install the compiler in this link https://sourceforge.net/projects/mingw/files/OldFiles/ 
3. Open the terminal at the direction of the file with the command:

~~~
cd C:\Documents\...
~~~

4. To compile use command:

~~~
gcc  04_Gato.cpp -o 04_Gato.exe
~~~

5. To run type this code:

~~~
04_Gato.exe
~~~

<h2> Linux (Ubuntu)</h2>

1. Download or clone my repo with the following command in the terminal:
   
~~~
"git clone https://github.com/UP210052/UP210052_CPP.git"
~~~

2. Install GNU c/c++ compiler, open the terminal and type:

~~~
$ sudo apt-get update
$ sudo apt-get install build-essential manpages-dev
~~~

3. To compile this program, type:

~~~
gcc 04_Gato.c -o 04_Gato
~~~

4. To run this program, type:
   
~~~
./04_Gato
~~~

</div>

this game has 2 game modes, solitaire mode which is against the computer and multiplayer mode which allows you to play against your friends, the game has a total of 9 moves, to select the game mode just type 1 for single player and 2 for multiplayer, on the other hand the player 1 is always the O and the player X is the player 2 or Pc depending on the selected mode.
</details>

<div align= "center">

## General considerations
</div>
<details close="open">
To play you have to keep in mind that to select the game mode you only have to put 1 or 2 if you try to put another value that is not one of these 2 the program will ask you to enter a valid mode and you will have to run the program again, also already inside the game in the grid you will see the number corresponding to each square, likewise if you put a move in a square that is occupied, you will be asked to enter a valid square.

#### Player 1 is always O
#### Player 2 is always X
#### Player Pc is always X
#### Negative values and decimals are not accepted.
#### Singleplayer mode Player 1 always starts the game
#### Only integer values are accepted, do not enter letters or special characters as the program is not designed to interpret letters or special characters.

</details>

<div align= "center">

## Flow Diagram
</div>
<details close="open">
abcdefghijklmnñopqrstuvwxyz
</details>

<div align= "center">

## Development
</div>
<details close="open">

<div align= "center">

### Player vs Pc

#### To start we select the game mode, in this case it is singleplayer since we are going to play against the pc.
<img src=https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/1.png 
alt="Sourcerer" width=300>
#### After selecting 1 we will enter in singleplayer mode and this we will be able to know thanks to the header that will tell us in which mode we are in case we forget in which mode we are playing.
<img src=https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/2.png
alt="Sourcerer" width=300>
#### Now we select the square to play, the squares to select are from 1 to 9 and just type a number and the move will be reflected on the board.
<img src=https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/3.png 
alt="Sourcerer" width=300>
#### Now the next turn is the computer's turn, it will randomly select a square.
<img src=https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/4.png 
alt="Sourcerer" width=300>
#### After this we can continue playing to beat the computer.
<img src=https://github.com/UP210582/UP210582_CPP/blob/main/Imagenes/5.png 
alt="Sourcerer" width=300>

</div>
</details>

<div align= "center">

## Conclusions
</div>
<details close="open">

This project was a real challenge because for the creation of the singleplayer game mode we had to develop an intelligence which could predict the moves and use this prediction in their favor, for that we use a copy of the cat with the moves already set, this intelligence checks each of the boxes and determines which of them will provide the victory, and with this the difficult was solved. 

The code has nothing of order is not consecutive since we used the creation of functions which we can call to use them later and thus not having to be repeating many times the same code which will do the same thing over and over again, for that we had to create functions which were concise and precise to be able to call them over and over again and thus to be more fluid and efficient work.

Throughout all the work I was presented with several challenges, one of them was trying to understand and analyze the operation of the functions as I had missed 2 classes which were in which the use of these was explained, but I had to learn how to use the functions in a very short period of time. 

</details>


Leonardo Ausencio Martinez Torres UP210582