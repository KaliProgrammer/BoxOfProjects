#include "Question.h"

void Question::setTriviaQuestion(string trQ)
{
	trQuestion = trQ;
}

void Question::setAnsw1(string aa1)
{
	a1 = aa1;
}

void Question::setAnsw2(string aa2)
{
	a2 = aa2;
}

void Question::setAnsw3(string aa3)
{
	a3 = aa3;
}

void Question::setAnsw4(string aa4)
{
	a4 == aa4;
}

void Question::setNumOfTheCorrectAnswer(int nca)
{
	numOfTheCorrectAnswer = nca;
}
void Question::setCorrectAnswer(string corrAnsw)
{
	correctAnswer = corrAnsw;
}
string Question::getTriviaQuestion() const
{
	return trQuestion;
}

string Question::getAnsw1() const
{
	return a1;
}

string Question::getAnsw2() const
{
	return a2;
}

string Question::getAnsw3() const
{
	return a3;
}

string Question::getAnsw4() const
{
	return a4;
}

string Question::getCorrectAnswer() const
{
	return correctAnswer;
}

int Question::getNumOfTheCorrectAnswer() const
{
	return numOfTheCorrectAnswer;
}
