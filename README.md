Tic Tac Toe Games
A collection of three Tic Tac Toe games developed to demonstrate and apply object-oriented programming (OOP) principles, with the ability to play against AI.

📜 Overview
The Tic Tac Toe Games repository contains three variations of the classic Tic Tac Toe game, designed and implemented using object-oriented programming (OOP) principles. The project features AI opponents, offering a challenging experience for users while maintaining clean, modular, and reusable code.

✨ Features
Multiple Game Variants: Three unique implementations of Tic Tac Toe, each offering a different style of play.
AI Opponent: Play against an AI opponent with varying levels of difficulty.
Object-Oriented Design: Utilizes OOP principles such as encapsulation, inheritance, and polymorphism for modular and maintainable code.
User-Friendly Interface: Simple and intuitive console-based interface for easy gameplay.
Scalable Structure: Designed to easily extend or modify game rules, AI difficulty, and mechanics.
🛠️ Technologies Used
Programming Language: C++
Object-Oriented Programming (OOP): The project uses classes, objects, inheritance, and other OOP principles to create clean and maintainable code.
AI Logic: Implemented using basic algorithms to provide varying levels of difficulty.

📚 Usage
Game 1:Four-in-a-row
  You will recognize four-in-a row as a two-dimensional version of the classic game, Connect Four. The game board consists of a 7 x 6 grid. Seven columns of six squares each. Instead of dropping counters as in Connect Four, players mark the grid with Xs and Os as in tic-tac-toe.
  Rules: The first player places an X in the bottom square of any column. Taking turns, players make their mark in any column, as long as it is in the lowest square possible. See image below for an example of possible first six moves.
  Winning: The first player to get four-in-a-row vertically, horizontally, or diagonally wins.
  ![photo_5978877312969590065_y](https://github.com/user-attachments/assets/91586e9e-4511-423c-a5bc-e02879e41ae2)

  
Game 2:Pyramic Tic-Tac-Toe
  The game board is shaped like a pyramid. Five squares make the base, then three, then one. Players take turns marking Xs and Os as in traditional tic-tac-toe.
  Winning: The first player to get three-in-a-row vertically, horizontally, or diagonally wins. See two examples of winning positions, below.
  ![photo_5978877312969590068_m](https://github.com/user-attachments/assets/ea767df1-e95e-4d35-9bde-9e160b1d4c74)

  
Game 3: 5 x 5 Tic Tac Toe 
  This tic-tac-toe variation is played on a 5 x 5 grid. As in the traditional game, players are Xs or Os.
  Rules: Players take turns placing an X or an O in one of the squares until all the squares except one are filled. (Each player has 12 turns for a total of 24 squares.) 
  Winning: Count the number of three-in-a-rows each player has. Sequences can be vertically, horizontally, or diagonally. Whoever has the most, wins. Can one mark be counted in more than one three-in-a-row sequence? Decide ahead of time, yes or no. It is easier in implementation to allow counting more than once. 
  Group Task 3 (1 mark) – OOP System Integration    
  The team will integrate their work and deliver an app that gives a menu of choices with the games available and if the user chooses a game, it opens the board for him to play against another player or a random computer player. 
  Group Task 4 (1 mark) – Code Review and Code Quality    
  Code review is an essential part of software development to ensure its quality and readability and reduce the bugs. Each team member will read the code of the other members and produce a report about it. Develop a suitable code review process that involves.
  ![photo_5978877312969590067_x](https://github.com/user-attachments/assets/901d93eb-db4c-4aad-9821-3622979200ca)

  
🧑‍💻 For Developers
The project is structured using OOP principles:

Encapsulation: Each game has its own class to manage its state and behavior.
Inheritance: Common features are implemented in a base class, which is extended by game-specific subclasses.
Polymorphism: Allows for different game behaviors through a common interface.
The AI logic is implemented using simple algorithms to offer varying levels of challenge.

Fork the repository, make changes, and submit pull requests to enhance the games or add new features.

  

  
