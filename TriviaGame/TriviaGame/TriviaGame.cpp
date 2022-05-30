// TriviaGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Question.h"
#include <windows.h>
#include <stdlib.h>

void displayQue(Question test);

int main()
{
	int pointsFirstPlayer = 0;
	int pointsSecondPlayer = 0;
	const int numQ = 10;

	Question questions[numQ] = { Question("1. What is the name of the capital of American California?", "Riso", "Sacramento", "Brigio", "Luvares", 2, "Sacramento"),
						   Question("2. In 1952, Albert Einstein was proposed as president of which country?", "Latvia", "Germany", "France", "Israel", 4, "Israel"),
						   Question("3. How many elements are in the periodic table?", "118 elements", "113 elements", "91 elements", "124 elements", 1, "118 elements"),
						   Question("4. Who discovered penicillin?", "Boris Figirald", "Alexander Fleming", "Nokayo Tokishi", "Robert Nottinger", 2, "Alexander Fleming"),
						   Question("5. Who is the only musician ever to win the Nobel Prize in Literature?", "Brian Harold May", "Alice Cooper", "Bob Dylan", "James Marshall (Jimi) Hendrix", 3, "Bob Dylan"),
						   Question("6. Which city is known as the birthplace of hip-hop?", "Bronx, New York", "New Jersey", "Cleveland", "Oakland", 1, "Bronx, New York"),
						   Question("7. Which boxer fought Muhammad Ali and won?", "Joe Frazier", "Michael Gerard Tyson", "Floyd Mayweather Jr", "Roy Levesta Jones Jr", 1, "Joe Frazier"),
						   Question("8. What soft drink was the first to be taken into space?", "Pepsi", "Fanta", "Snaple", "Coca Cola", 4, "Coca Cola"),
						   Question("9. How much does the Chewbacca suit weigh?", "3,6 kg", "7,7 kg", "2,7 kg", "6,8 kg", 1, "3,6 kg"),
						   Question("10. Which of the planets is closest in size to our moon?", "Mercury", "Venus", "Mars", "Jupiter", 1, "Mercury")
							};

	int questionNum = 0;
	while (questionNum < 10)
	{
		int answer;
		cout << "Question for player 1:\n";
		cout << "-----------------------\n";
		displayQue(questions[questionNum]);
		cout << "Enter the correct answer: "; cin >> answer;

		if (answer == questions[questionNum].getNumOfTheCorrectAnswer())
		{
			cout << "Correct!\n";
			pointsFirstPlayer++;
		}
		else
		{
			cout << "Sory, that's incorrect. The correct answer is: "
				<< "(" << questions[questionNum].getNumOfTheCorrectAnswer() << ")" << " - "
				<< questions[questionNum].getCorrectAnswer() << endl << endl;
		}
		questionNum++;
		Sleep(4000);
		system("cls");
		cout << "Question for player 2:\n";
		cout << "-----------------------\n";
		displayQue(questions[questionNum]);
		cout << "Enter the correct answer: "; cin >> answer;

		if (answer == questions[questionNum].getNumOfTheCorrectAnswer())
		{
			cout << "Correct!\n";
			pointsSecondPlayer++;
		}
		else
		{
			cout << "Sory, that's incorrect. The correct answer is: "
				<< "(" << questions[questionNum].getNumOfTheCorrectAnswer() << ")" << " - "
				<< questions[questionNum].getCorrectAnswer() << endl << endl;
		}
		questionNum++;
		Sleep(4000);
		system("cls");
	}
	cout << "Game over! Here are the points: " << endl;
	cout << "Player 1: " << pointsFirstPlayer << endl;
	cout << "Player 2: " << pointsSecondPlayer << endl;
	if (pointsFirstPlayer > pointsSecondPlayer)
	{
		cout << "First player wins!";
	}
	else if (pointsFirstPlayer == pointsSecondPlayer)
	{
		cout << "it's a tie!";
	}
	else
		cout << "Second player wins!" << endl;
    

}

void displayQue(Question test)
{
	cout << test.getTriviaQuestion() << endl;
	cout << "Answers: \n";
	cout << "1. " << test.getAnsw1() << endl;
	cout << "2. " << test.getAnsw2() << endl;
	cout << "3. " << test.getAnsw3() << endl;
	cout << "4. " << test.getAnsw4() << endl;
}