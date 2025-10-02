#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {

	//Over-arching game variables
	int playerGameChoice;
	bool menu = false;
	bool playAgain = true;
	char choice;
	char gameStart;

	//Variables for lottery game
	// choice between entering their own numbers and having their numbers generated
	int numberInputChoice;
	//user numbers
	int userNum1;
	int userNum2;
	int userNum3;
	int userNum4;
	int userNum5;
	int userNum6;
	int userBonusNum;

	//need to initialize these to get rid of errors
	int number1 = 49;
	int number2 = 48;
	int number3 = 47;
	int number4 = 46;
	int number5 = 45;
	int number6 = 44;
	int bonusNumber = 43;
	
	int matches = 0;
	bool validChoice = false;

	///// Dice Game Variables /////

	// User Input Dice
	int dice1, dice2;		// to hold user input for dice game
	int validInput = false; // fo rinput validation

	// Random Dice
	int randomRoll;			// to hold random roll for dice game
	int roll1, roll2;		// to hold random roll Dice1 and Dice2

	//Guessing game variable
	int numberToGuess;
	int userGuess;
	int numberOfGuesses = 1;
	int winStreak = 0;
	int highScore = 0;

	bool guessed = false;

	//use time() to get an int value
	int elapsed_seconds = time(nullptr);
	//seed the random number generator
	srand(elapsed_seconds);

	//Variables to hole user name
	string playerFirstName;
	string playerLastName;
	string playerFullName;

	//Get the user's first and last name
	cout << "Welcome, please enter your first name: ";
	cin >> playerFirstName;
	cout << "Enter your last name: ";
	cin >> playerLastName;

	//add some space
	cout << "\n\n";

	//Put together the full player name
	playerFullName = playerFirstName + " " + playerLastName;

	//ask the user if they would like to play a game
	while (!validInput) {
		cout << "Hello, " << playerFullName << ".\n\n"
			<< "Would you like to play a game? (y/n) ";
		cin >> gameStart;

		//determine whether their answer was valid and what to do with it if it was
		if (tolower(gameStart) == 'n') {
			menu = true;
			validInput = true;
			cout << "\nAlright, have a nice day!\n\n";
		}
		else if (tolower(gameStart) == 'y') {
			validInput = true;
			cout << "\n________________________________________________________________________________________________________________________\n\n";
		}
		else {
			cout << "Invalid input. You must enter 'y' or 'n'\n\n";
		}

	}

	//reset validInput
	validInput = false;

	/*
	 * While the menu boolean is false run the game, after a case is matched with an input, the corresponding block of code will execute.
	 * Flagging menu to true should break the loop
	 */

	while (!menu) {
		cout << "-----Game Menu-----\n"
			<< "1. Lottery Game\n"
			<< "2. Dice Game\n"
			<< "3. Guessing Game\n"
			<< "4. Exit\n\n";
		cout << "Please type a number to make your selection: ";
		cin >> playerGameChoice;

		//Making it look pretty
		cout << "________________________________________________________________________________________________________________________\n\n";

		switch (playerGameChoice) {

			case 1:
				// CASE 1 - Lottery

				//Game Name
				cout << "\n *** Lottery Number Generator ***" << endl << endl;

				//brief explanation
				cout << "This program is a lottery simulation. You will be asked to either enter 6 + 1 numbers between 1 and 49\n"
					<< "or get the computer to generate you 6 + 1 numbers between 1 and 49. The computer will then generate 6 + 1\n"
					<< "\"Winning\" numbers and your numbers will be compared to them. It will then input the number of matches\n"
					<< "you got. Good luck!\n\n";

				//The games will be in while loops so the user doesn't exit to the main menu after every
				//play

				while (playAgain) {

					//ask the user if they would like to input numbers or have them be randomly generated
					while (!validChoice) {
						cout << playerFullName <<", would you like to:\n1. Enter the numbers manually\n2. Have the numbers be randomly generated\nPlease type 1 or 2: ";
						cin >> numberInputChoice;

						//validate their input
						if (numberInputChoice == 1 || numberInputChoice == 2) {
							validChoice = true;
						}
						else {
							cout << "\nInvalid input. Please type 1 or 2.\n\n";
						}
					}
					//reset validChoice
					validChoice = false;

					/*****MESSY CODE INCOMING*****/

					//switch case based on what the user picked
					switch (numberInputChoice) {
						case 1: //user enters their own numbers
							//Code for validation is going to be long and ugly without arrays and functions.
							//every validation is going to get longer and the code will be mostly reused in case 2.
							while (!validChoice) {
								//get user num then make sure its between 1 and 49
								cout << "Enter your first number: ";
								cin >> userNum1;
								if (userNum1 >= 1 && userNum1 <= 49) {
									validChoice = true;
								}
								else {
									cout << "Number must be between 1 and 49.\n";
								}
							}
							//reset validChoice
							validChoice = false;

							//next number
							while (!validChoice) {
								//get user num then make sure its between 1 and 49
								cout << "Enter your second number: ";
								cin >> userNum2;
								//add that the number cant be equal to the last number to the conditional statement
								if (userNum2 >= 1 && userNum2 <= 49 && userNum2 != userNum1) {
									validChoice = true;
								}
								else {
									cout << "Number must be between 1 and 49 and must not be equal to previous numbers entered.\n";
								}
							}
							//reset validChoice
							validChoice = false;

							//next number
							while (!validChoice) {
								//get user num then make sure its between 1 and 49
								cout << "Enter your third number: ";
								cin >> userNum3;
								//add that the number cant be equal to the last number to the conditional statement
								if (userNum3 >= 1 && userNum3 <= 49 && userNum3 != userNum1 && userNum3 != userNum2) {
									validChoice = true;
								}
								else {
									cout << "Number must be between 1 and 49 and must not be equal to previous numbers entered.\n";
								}
							}
							//reset validChoice
							validChoice = false;

							//next number
							while (!validChoice) {
								//get user num then make sure its between 1 and 49
								cout << "Enter your fourth number: ";
								cin >> userNum4;
								//add that the number cant be equal to the last number to the conditional statement
								if (userNum4 >= 1 && userNum4 <= 49 && userNum4 != userNum1 && userNum4 != userNum2 && userNum4 != userNum3) {
									validChoice = true;
								}
								else {
									cout << "Number must be between 1 and 49 and must not be equal to previous numbers entered.\n";
								}
							}
							//reset validChoice
							validChoice = false;

							//next number
							while (!validChoice) {
								//get user num then make sure its between 1 and 49
								cout << "Enter your fifth number: ";
								cin >> userNum5;
								//add that the number cant be equal to the last number to the conditional statement
								if (userNum5 >= 1 && userNum5 <= 49 && userNum5 != userNum1 && userNum5 != userNum2 && userNum5 != userNum3 && userNum5 != userNum4) {
									validChoice = true;
								}
								else {
									cout << "Number must be between 1 and 49 and must not be equal to previous numbers entered.\n";
								}
							}
							//reset validChoice
							validChoice = false;

							//next number
							while (!validChoice) {
								//get user num then make sure its between 1 and 49
								cout << "Enter your sixth number: ";
								cin >> userNum6;
								//add that the number cant be equal to the last number to the conditional statement
								if (userNum6 >= 1 && userNum6 <= 49 && userNum6 != userNum1 && userNum6 != userNum2 && userNum6 != userNum3 && userNum6 != userNum4 && userNum6 != userNum5) {
									validChoice = true;
								}
								else {
									cout << "Number must be between 1 and 49 and must not be equal to previous numbers entered.\n";
								}
							}
							//reset validChoice
							validChoice = false;

							//next number
							while (!validChoice) {
								//get user num then make sure its between 1 and 49
								cout << "Enter your bonus number: ";
								cin >> userBonusNum;
								//add that the number cant be equal to the last number to the conditional statement
								if (userBonusNum >= 1 && userBonusNum <= 49 && userBonusNum != userNum1 && userBonusNum != userNum2 && userBonusNum != userNum3 && userBonusNum != userNum4 && userBonusNum != userNum5 && userBonusNum != userNum6) {
									validChoice = true;
								}
								else {
									cout << "Number must be between 1 and 49 and must not be equal to previous numbers entered.\n";
								}
							}
							//reset validChoice
							validChoice = false;
							break;

						case 2: //computer generated numbers
							//this time we don't have to ask the user and validate input, we just have to make sure the numbers
							//aren't equal to previous numbers.
							
							//first number doesn't need validation
							userNum1 = rand() % 49 + 1;

							//second number on will need validation to make sure its no the same number as a previous one
							while (!validChoice) {
								userNum2 = rand() % 49 + 1;
								if (userNum2 != userNum1) {
									validChoice = true;
								} //no else statement with an error message is needed as the computer will keep running the loop until the 
								//conditions of this if statement are met
							}
							//reset validChoice
							validChoice = false;

							//third number
							while (!validChoice) {
								userNum3 = rand() % 49 + 1;
								if (userNum3 != userNum1 && userNum3 != userNum2) {
									validChoice = true;
								}
							}
							//reset validChoice
							validChoice = false;

							//fourth number
							while (!validChoice) {
								userNum4 = rand() % 49 + 1;
								if (userNum4 != userNum1 && userNum4 != userNum2 && userNum4 != userNum3) {
									validChoice = true;
								}
							}
							//reset validChoice
							validChoice = false;

							//fifth number
							while (!validChoice) {
								userNum5 = rand() % 49 + 1;
								if (userNum5 != userNum1 && userNum5 != userNum2 && userNum5 != userNum3 && userNum5 != userNum4) {
									validChoice = true;
								}
							}
							//reset validChoice
							validChoice = false;

							//sixth number
							while (!validChoice) {
								userNum6 = rand() % 49 + 1;
								if (userNum6 != userNum1 && userNum6 != userNum2 && userNum6 != userNum3 && userNum6 != userNum4 && userNum6 != userNum5) {
									validChoice = true;
								}
							}
							//reset validChoice
							validChoice = false;

							//bonus
							while (!validChoice) {
								userBonusNum = rand() % 49 + 1;
								if (userBonusNum != userNum1 && userBonusNum != userNum2 && userBonusNum != userNum3 && userBonusNum != userNum4 && userBonusNum != userNum5 && userBonusNum != userNum6) {
									validChoice = true;
								}
							}
							//reset validChoice
							validChoice = false;

							break;

						default:
							cout << "An error has occured.\n\n";

							//Set default values for the numbers if something goes wrong
							userNum1 = 1;
							userNum2 = 2;
							userNum3 = 3;
							userNum4 = 4;
							userNum5 = 5;
							userNum6 = 6;
							userBonusNum = 7;

							break;
					}

					//generate lotto numbers we will be comparing against
					//we will be reusing the code we created to generate user numbers except we will change the variables
					number1 = rand() % 49 + 1;

					while (!validChoice) {
						number2 = rand() % 49 + 1;
						if (number2 != number1) {
							validChoice = true;
						}
					}
					//reset validChoice
					validChoice = false;

					//third number
					while (!validChoice) {
						number3 = rand() % 49 + 1;
						if (number3 != number1 && number3 != number2) {
							validChoice = true;
						}
					}
					//reset validChoice
					validChoice = false;

					//fourth number
					while (!validChoice) {
						number4 = rand() % 49 + 1;
						if (number4 != number1 && number4 != number2 && number4 != number3) {
							validChoice = true;
						}
					}
					//reset validChoice
					validChoice = false;

					//fifth number
					while (!validChoice) {
						number5 = rand() % 49 + 1;
						if (number5 != number1 && number5 != number2 && number5 != number3 && number5 != number4) {
							validChoice = true;
						}
					}
					//reset validChoice
					validChoice = false;

					//sixth number
					while (!validChoice) {
						number6 = rand() % 49 + 1;
						if (number6 != number1 && number6 != number2 && number6 != number3 && number6 != number4 && number6 != number5) {
							validChoice = true;
						}
					}
					//reset validChoice
					validChoice = false;

					//bonus
					while (!validChoice) {
						bonusNumber = rand() % 49 + 1;
						if (bonusNumber != userNum1 && bonusNumber != userNum2 && bonusNumber != userNum3 && bonusNumber != userNum4 && bonusNumber != userNum5 && bonusNumber != userNum6) {
							validChoice = true;
						}
					}
					//reset validChoice
					validChoice = false;

					//print out the numbers
					cout << playerFullName << ", Here are your numbers." << endl << endl
						<< userNum1 << " "
						<< userNum2 << " "
						<< userNum3 << " "
						<< userNum4 << " "
						<< userNum5 << " "
						<< userNum6 << " "
						<< "Bonus Number: " << userBonusNum << endl << endl;

					cout << "Here are the computer's numbers." << endl << endl
						<< number1 << " "
						<< number2 << " "
						<< number3 << " "
						<< number4 << " "
						<< number5 << " "
						<< number6 << " "
						<< "Bonus Number: " << bonusNumber << endl << endl;

					//find the number of matches (this will also be ugly)
					if (userNum1 == number1 || userNum1 == number2 || userNum1 == number3 || userNum1 == number4 || userNum1 == number5 || userNum1 == number6 || userNum1 == bonusNumber) {
						matches++;
					} //this if statement will be copy pasted, replacing userNum1 with the next number up to bonus num

					if (userNum2 == number1 || userNum2 == number2 || userNum2 == number3 || userNum2 == number4 || userNum2 == number5 || userNum2 == number6 || userNum2 == bonusNumber) {
						matches++;
					}

					if (userNum3 == number1 || userNum3 == number2 || userNum3 == number3 || userNum3 == number4 || userNum3 == number5 || userNum3 == number6 || userNum3 == bonusNumber) {
						matches++;
					}

					if (userNum4 == number1 || userNum4 == number2 || userNum4 == number3 || userNum4 == number4 || userNum4 == number5 || userNum4 == number6 || userNum4 == bonusNumber) {
						matches++;
					}

					if (userNum5 == number1 || userNum5 == number2 || userNum5 == number3 || userNum5 == number4 || userNum5 == number5 || userNum5 == number6 || userNum5 == bonusNumber) {
						matches++;
					}

					if (userNum6 == number1 || userNum6 == number2 || userNum6 == number3 || userNum6 == number4 || userNum6 == number5 || userNum6 == number6 || userNum6 == bonusNumber) {
						matches++;
					}

					if (userBonusNum == number1 || userBonusNum == number2 || userBonusNum == number3 || userBonusNum == number4 || userBonusNum == number5 || userBonusNum == number6 || userBonusNum == bonusNumber) {
						matches++;
					}

					//print out the number of matches
					cout << "You got " << matches << " match(es)." << endl;

					//determine the message to be printed out based on the number of matches
					if (matches == 0) {
						cout << "Too bad! Better luck next time.\n\n";
					}
					else if (matches == 1) {
						cout << "At least you got one!\n\n";
					}
					else if (matches == 2) {
						cout << "Nice work!\n\n";
					}
					else if (matches == 3) {
						cout << "Very good job!\n\n";
					}
					else if (matches == 4) {
						cout << "Over half correct! Great job!\n\n";
					}
					else if (matches == 5) {
						cout << "Wow! Very impressive!\n\n";
					}
					else if (matches == 6) {
						cout << "Amazing! Almost perfect!\n\n";
					}
					else if (matches == 7) {
						cout << "Perfect! You won the lottery!\n\n";
					}
					else {
						cout << "You shouldn't be able to see this.\n\n";
					}

					//Ask the user if they would like to play again
					cout << "\nDo you want to play again? (y/n): ";
					cin >> choice;

					if (choice == 'n' || choice == 'N') {

						playAgain = false;

					}

					//reset matches for the next time
					matches = 0;

					cout << "________________________________________________________________________________________________________________________\n\n";
				}

				//reset play again
				playAgain = true;

				break;

			case 2:
				// CASE 2 - Dice Program in a while loop
				// 
				// print program title to console
				cout << "\n *** Dice Guessing Game ***" << endl << endl;

				//brief explanation
				cout << "Input 2 numbers between 1 and 6 and compare to 2 random numbers." << endl;
				cout << "If both numbers match, you win!\n";

				while (playAgain) {

					// Display greeting
					cout << "\nHello " << playerFullName << "!" << endl << endl;

					// Get user input for 2 numbers between 1 and 6
					//keep input in a while loop so the user can only select a valid option

					while (!validInput) {
						cout << "Input your first number: ";
						cin >> dice1;

						if (dice1 >= 1 && dice1 <= 6) {
							validInput = true;
						} else {
							cout << "Please choose a number between 1 and 6.\n\n";
						}
					}

					//reset validInput
					validInput = false;

					while (!validInput) {
						cout << "Input your second number: ";
						cin >> dice2;

						if (dice2 >= 1 && dice2 <= 6) {
							validInput = true;
						}
						else {
							cout << "Please choose a number between 1 and 6.\n\n";
						}
					}
					validInput = false;

					/* 
					 * for loop that will use a counter with i to loop through 2 times
					 * each time the randomRoll variable will be assigned a random number between 1 and 6
					 * Generate and display 2 random numbers between 1 and 6 
					 */
					cout << endl;

					for (int i = 0; i < 2; i++) {

						randomRoll = (rand() % 6) + 1; // rand() % 6 generates a number between 0 and 5, so we add 1 to get a number between 1 and 6

						if (i == 0) {
							roll1 = randomRoll;
						} else {
							roll2 = randomRoll;
						}

					}

					// Display the random roll numbers
					cout << "\nThe computer's rolls are: " << roll1 << " and " << roll2 << endl;
					
					// Compare user input to random numbers and display win/lose message
					// If either of the user's numbers match either of the random numbers, they win
					if (((dice1 == roll1) && (dice2 == roll2)) || ((dice1 == roll2) && (dice2 == roll1))) {
						cout << "You Win!" << endl;
					} else {
						cout << "You Lose!" << endl;
					}

					// Ask user if they want to play again
					cout << "\nDo you want to play again? (y/n): ";
					cin >> choice;

					if (choice == 'n' || choice == 'N') {

						playAgain = false;

					}

					cout << "________________________________________________________________________________________________________________________\n\n";
				}
				
				//reset play again
				playAgain = true;

				break;
			case 3:
				//CASE 3 -- Guessing Game

				cout << "\n *** Number Guessing Game ***" << endl << endl;

				//brief explanation
				cout << "I will generate a number between 1 and 100. You will have 5 guesses to guess the number." << endl
					<< "After each guess, I will tell you if the number is higher or lower. The number of consecutive\n"
					<< "Wins you have will be recorded in as your win streak.\n\n";

				//Print out the user's high score
				cout << "HIGH SCORE: " << highScore << endl << endl;

				while (playAgain) {

					//address the user
					cout << "Hello, " << playerFullName << "!\n\n";

					//generate the number to guess
					numberToGuess = rand() % 100 + 1;

					//Game will take place in a while loop as we can exit it when one of two conditions are met
					while (!guessed && numberOfGuesses <= 5) {
						//Yes we will have input validation inside this loop
						while (!validInput) {
							//Print out the guess the user is on
							cout << "Guess " << numberOfGuesses << ": ";
							cin >> userGuess;

							if (userGuess >= 1 && userGuess <= 100) {
								validInput = true;
							}
							else {
								cout << "Guess must be between 1 and 100.\n\n";
							}
						}
						//reset valid Input
						validInput = false;

						//increase numberOfGuesses
						numberOfGuesses++;

						//check whether the generated number is lower, higher, or correct
						if (userGuess > numberToGuess) {
							cout << "Too high...\n\n";
						}
						else if (userGuess < numberToGuess) {
							cout << "Too low...\n\n";
						}
						else if (userGuess == numberToGuess) { //if the guess is correct, update the winstreak
							cout << "You got it, nice job!\n";
							guessed = true;
							winStreak++;
							//update highScore
							if (winStreak > highScore)
								highScore = winStreak;
							cout << "Win Streak: " << winStreak << endl
								<< "High Score: " << highScore << endl << endl;
						}
					}
					
					//check whether the number was guessed. Let the user know they lost and reset winstreak
					if (guessed == false) {
						cout << "You ran out of guesses!\n"
							<< "The number was: " << numberToGuess << endl << endl;

						winStreak = 0;
					}
					//reset guessed
					guessed = false;
					//reset number of guesses
					numberOfGuesses = 1;
					
					// Ask user if they want to play again
					cout << "\nDo you want to play again? (y/n): ";
					cin >> choice;

					if (choice == 'n' || choice == 'N') {

						playAgain = false;

					}

					cout << "________________________________________________________________________________________________________________________\n\n";
				}
				//we wont reset winstreak as they may come back to play.
				//we will, however, reset play again
				playAgain = true;

				break;
			case 4:

				cout << "Goodbye, "<< playerFullName <<"!" << endl;
				//Change menu flag to true to break out of the loop
				menu = true;
				break;

			default:
				//Message to the user including the valid options
				cout << "Please select a valid option (1, 2, 3, 4)." << endl << endl;
		}
	}

	return 0;
}