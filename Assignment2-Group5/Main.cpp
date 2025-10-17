#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

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
	//DJ: int for the amount of money the user has
	int userBalance = 100;

	// AD: Initialize a vector that holds 6 elements that are integers
	vector <int> userLotteryNumbers(6);
	vector <int> bonusLotteryNumbers(6);
	vector <int> winningLotteryNumbers(7);
	// AD: Initialize a variable to hold an integer and push to a vector
	int userLotteryNumber;
	int randomBonusNumber;
	int winningLotteryNumber;

	bool duplicateLotteryNumber = false;

	//DJ: Strings for lottery result messages
	string userLineMsg;
	string bonusLineMsg;

	//DJ: variables for generating a file
	ofstream output_file;

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

			//if the user doesn't have enough money, they cant play
			if (userBalance < 5) {
				playAgain = false;
				cout << "Sorry, " << playerFullName << ", you cant afford to play.\n";
				cout << "Balance: $" << userBalance << "\n\n";
			}

			while (playAgain) {
				//DJ: subtract 5 from the userBalance and tell the user how much they have
				userBalance -= 5;
				cout << "Hello, " << playerFullName << "! You currently have $" << userBalance << ".\n\n";

				// AD: Clear the vector before entering the while loop so we dont save data from previous games
				userLotteryNumbers.clear();
				bonusLotteryNumbers.clear();
				winningLotteryNumbers.clear();

				// AD: Nested for loop to ask for user input 6 times
				for (int i = 1; i <= 6; i++) {
					cout << "Enter your number: ";
					cin >> userLotteryNumber;

					// AD: Check if the user's input is a valid number
					if (userLotteryNumber < 1 || userLotteryNumber > 49) {
						cout << "Invalid number. Please pick a number between 1 and 49" << endl;

						// AD: Decrement the iteration if its invalid to restart that iteration
						i--;
						// AD: Continue will skip the rest of the loop and bring us back to the top, we need to remove 1 iteration from i or else we will not retrieve all 6 inputs
						continue;
					}
					// AD: Initialize the duplicate flag inside the loop, it will clear itself after each game
					duplicateLotteryNumber = false;

					// AD: Use j as another iterator for this nested for loop so that we can try to find if a same number already exists within the vector
					for (int j = 0; j < userLotteryNumbers.size(); j++) {
						if (userLotteryNumbers[j] == userLotteryNumber) {

							duplicateLotteryNumber = true;
							// AD: Break out of the nested loop 
							break;
						}
					}

					if (duplicateLotteryNumber == true) {
						cout << "You have already entered that number." << endl;
						i--;
						continue;
					}

					userLotteryNumbers.push_back(userLotteryNumber);


				}

				// AD: Add Bonus line
				// AD: Use for loop to generate 6 elements from 1-49
				for (int i = 0; i < 6; i++) {
					// AD: Initialize the duplicate flag inside the loop, it will clear itself after each game
					duplicateLotteryNumber = true;
					//DJ: here we will check for duplicates in the bonus line
					while (duplicateLotteryNumber) {
						//DJ: change duplicate lottery number to false
						duplicateLotteryNumber = false;
						//DJ: generate random number
						randomBonusNumber = rand() % 49 + 1;
						//DJ: loop through bonus number list to see if there are dupliates
						for (int j = 0; j < bonusLotteryNumbers.size(); j++) {
							//DJ: if we fine a duplicate, set the variable to true, this will cause the while loop to go one more time
							//until a non duplicate number is generated
							if (randomBonusNumber == bonusLotteryNumbers[j]) {
								duplicateLotteryNumber = true;
							}
						}
					}
					bonusLotteryNumbers.push_back(randomBonusNumber);
				}

				// AD: Generate  6 + 1 random winning numbers
				for (int i = 0; i < 7; i++) {
					// AD: Initialize the duplicate flag inside the loop, it will clear itself after each game
					duplicateLotteryNumber = true;
					//DJ: here we will check for duplicates in the bonus line
					while (duplicateLotteryNumber) {
						//DJ: change duplicate lottery number to false
						duplicateLotteryNumber = false;
						//DJ: generate random number
						winningLotteryNumber = rand() % 49 + 1;
						//DJ: loop through bonus number list to see if there are dupliates
						for (int j = 0; j < winningLotteryNumbers.size(); j++) {
							//DJ: if we fine a duplicate, set the variable to true, this will cause the while loop to go one more time
							//until a non duplicate number is generated
							if (winningLotteryNumber == winningLotteryNumbers[j]) {
								duplicateLotteryNumber = true;
							}
						}
					}
					winningLotteryNumbers.push_back(winningLotteryNumber);
				}

				// AD: Compare user numbers to winning numbers
				int userMatchCount = 0;
				for (int i = 0; i < winningLotteryNumbers.size(); i++) {

					for (int j = 0; j < userLotteryNumbers.size(); j++) {

						if (winningLotteryNumbers[i] == userLotteryNumbers[j]) {
							userMatchCount++;
						}

					}
				}

				// AD: Compare bonus numbers to winning numbers
				int bonusMatchCount = 0;
				for (int i = 0; i < winningLotteryNumbers.size(); i++) {

					for (int j = 0; j < bonusLotteryNumbers.size(); j++) {

						if (winningLotteryNumbers[i] == bonusLotteryNumbers[j]) {
							bonusMatchCount++;
						}

					}
				}
				// AD: Add spacing to text
				cout << endl << endl;

				//DJ: determine the message to display based on the number of matches
				//also add the money to user balance
				if (userMatchCount < 3) {
					userLineMsg = "Too bad! Better luck next time.";
				}
				else if (userMatchCount == 3) {
					userLineMsg = "You won $1000!";
					userBalance += 1000;
				}
				else if (matches == 4) {
					userLineMsg = "You won $10,000!";
					userBalance += 10000;
				}
				else if (matches == 5) {
					userLineMsg = "You won $250,000!";
					userBalance += 250000;
				}
				else if (matches == 6) {
					userLineMsg = "You won the grand prize of $5,000,000!";
					userBalance += 5000000;
				}

				//DJ: do the same for the bonus line
				if (bonusMatchCount < 3) {
					bonusLineMsg = "Too bad! Better luck next time.";
				}
				else if (bonusMatchCount == 3) {
					bonusLineMsg = "You won $1000!";
					userBalance += 1000;
				}
				else if (bonusMatchCount == 4) {
					bonusLineMsg = "You won $10,000!";
					userBalance += 10000;
				}
				else if (bonusMatchCount == 5) {
					bonusLineMsg = "You won $250,000!";
					userBalance += 250000;
				}
				else if (bonusMatchCount == 6) {
					bonusLineMsg = "You won the grand prize of $5,000,000!";
					userBalance += 5000000;
				}


				//DJ: This is where we write the generated numbers to a file
				output_file.open("lottery_ticket.txt");

				//DJ: Title and date
				output_file << "================Lotto 6/49 Ticket================\n\n";

				//DJ: mention the name of the player
				output_file << playerFullName << ", here is your lottery ticket.\n\n";

				//DJ: write the first line of numbers
				output_file << "===============Your Picked Numbers===============\n";
				//DJ: Loop through the vector to output numbers
				for (int i = 0; i < userLotteryNumbers.size(); i++) {
					output_file << setw(6) << userLotteryNumbers[i] << " ";
				}
				//DJ: add some new lines for formatting
				output_file << "\n\n";

				//DJ: bonus numbers
				output_file << "===================Bonus Line====================\n";
				//DJ: Loop through the vector to output numbers
				for (int i = 0; i < bonusLotteryNumbers.size(); i++) {
					output_file << setw(6) << bonusLotteryNumbers[i] << " ";
				}
				//DJ: add some new lines for formatting
				output_file << "\n\n";

				//DJ: winning numbers
				output_file << "=================Winning Numbers=================\n";
				//DJ: Loop through the vector to output numbers
				for (int i = 0; i < winningLotteryNumbers.size(); i++) {
					output_file << setw(5) << winningLotteryNumbers[i] << " ";
				}
				//DJ: add some new lines for formatting
				output_file << "\n\n";

				//DJ: Quick summary of the results
				output_file << "=====================Results=====================\n";
				output_file << "Your line: " << userMatchCount << " matches - " << userLineMsg << "\n";
				output_file << "Bonus line: " << bonusMatchCount << " matches - " << bonusLineMsg << "\n\n";
				output_file << "See you next time!\n";

				output_file.close();

				//DJ: we also need to print this to the console
				//DJ: Title and date
				cout << "================Lotto 6/49 Ticket================\n\n";

				//DJ: mention the name of the player
				cout << playerFullName << ", here is your lottery ticket.\n\n";

				//DJ: write the first line of numbers
				cout << "===============Your Picked Numbers===============\n";
				//DJ: Loop through the vector to output numbers
				for (int i = 0; i < userLotteryNumbers.size(); i++) {
					cout << setw(6) << userLotteryNumbers[i] << " ";
				}
				//DJ: add some new lines for formatting
				cout << "\n\n";

				//DJ: bonus numbers
				cout << "===================Bonus Line====================\n";
				//DJ: Loop through the vector to output numbers
				for (int i = 0; i < bonusLotteryNumbers.size(); i++) {
					cout << setw(6) << bonusLotteryNumbers[i] << " ";
				}
				//DJ: add some new lines for formatting
				cout << "\n\n";

				//DJ: winning numbers
				cout << "=================Winning Numbers=================\n";
				//DJ: Loop through the vector to output numbers
				for (int i = 0; i < winningLotteryNumbers.size(); i++) {
					cout << setw(5) << winningLotteryNumbers[i] << " ";
				}
				//DJ: add some new lines for formatting
				cout << "\n\n";

				//DJ: Quick summary of the results
				cout << "=====================Results=====================\n";
				cout << "Your line: " << userMatchCount << " matches - " << userLineMsg << "\n";
				cout << "Bonus line: " << bonusMatchCount << " matches - " << bonusLineMsg << "\n\n";
				cout << "See you next time!\n";

				//print out the user balance
				cout << "You have $" << userBalance << ".\n\n";

				//Ask the user if they would like to play again
				cout << "\nDo you want to play again? (y/n): ";
				cin >> choice;

				//if the user doesn't have enough money to play again
				if (userBalance < 5) {
					playAgain = false;
					cout << "Sorry, " << playerFullName << ", you cant afford to play again.\n";
					cout << "Balance: $" << userBalance << "\n\n";
				}

				if (choice == 'n' || choice == 'N') {

					playAgain = false;

				}

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

					// Check if input failed (non-numeric input)
					if (cin.fail()) {
						cin.clear(); // Clear error flag
						cin.ignore(1000, '\n'); // Clear input buffer
						cout << "Error: Please enter only one number between 1 and 6.\n\n";
					}
					else if (dice1 >= 1 && dice1 <= 6) {
						validInput = true;
					}
					else {
						cout << "Error: Please choose a number between 1 and 6.\n\n";
					}
				}

				//reset validInput
				validInput = false;

				while (!validInput) {
					cout << "Input your second number: ";
					cin >> dice2;

					// Check if input failed (non-numeric input)
					if (cin.fail()) {
						cin.clear(); // Clear error flag
						cin.ignore(1000, '\n'); // Clear input buffer
						cout << "Error: Please enter only one number between 1 and 6.\n\n";
					}
					else if (dice2 >= 1 && dice2 <= 6) {
						validInput = true;
					}
					else {
						cout << "Error: Please choose a number between 1 and 6.\n\n";
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
					}
					else {
						roll2 = randomRoll;
					}

				}

				// Display the random roll numbers
				cout << "\nThe computer's rolls are: " << roll1 << " and " << roll2 << endl;

				// Compare user input to random numbers and display win/lose message
				// If either of the user's numbers match either of the random numbers, they win
				if (((dice1 == roll1) && (dice2 == roll2)) || ((dice1 == roll2) && (dice2 == roll1))) {
					cout << "You Win!" << endl;
				}
				else {
					cout << "You Lose!" << endl;
				}

				// Ask user if they want to play again
				bool validPlayAgainChoice = false;
				while (!validPlayAgainChoice) {
					cout << "\nDo you want to play again? (y/n): ";
					cin >> choice;

					// Check if input failed
					if (cin.fail()) {
						cin.clear(); // Clear error flag
						cin.ignore(1000, '\n'); // Clear input buffer
						cout << "Error: Please enter 'y' for yes or 'n' for no.\n";
					}
					else if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
						validPlayAgainChoice = true;
						if (choice == 'n' || choice == 'N') {
							playAgain = false;
						}
					}
					else {
						cout << "Error: Please enter 'y' for yes or 'n' for no.\n";
					}
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

						// Check if input failed (non-numeric input)
						if (cin.fail()) {
							cin.clear(); // Clear error flag
							cin.ignore(1000, '\n'); // Clear input buffer
							cout << "Error: Please enter only one number between 1 and 100.\n\n";
						}
						else if (userGuess >= 1 && userGuess <= 100) {
							validInput = true;
						}
						else {
							cout << "Error: Guess must be between 1 and 100.\n\n";
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
				bool validPlayAgainChoice = false;
				while (!validPlayAgainChoice) {
					cout << "\nDo you want to play again? (y/n): ";
					cin >> choice;

					// Check if input failed
					if (cin.fail()) {
						cin.clear(); // Clear error flag
						cin.ignore(1000, '\n'); // Clear input buffer
						cout << "Error: Please enter 'y' for yes or 'n' for no.\n";
					}
					else if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
						validPlayAgainChoice = true;
						if (choice == 'n' || choice == 'N') {
							playAgain = false;
						}
					}
					else {
						cout << "Error: Please enter 'y' for yes or 'n' for no.\n";
					}
				}

				cout << "________________________________________________________________________________________________________________________\n\n";
			}
			//we wont reset winstreak as they may come back to play.
			//we will, however, reset play again
			playAgain = true;

			break;
		case 4:

			cout << "Goodbye, " << playerFullName << "!" << endl;
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