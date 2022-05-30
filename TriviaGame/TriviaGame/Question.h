#pragma once
#include <string>
using namespace std;

class Question
{
private:
	string trQuestion;
	string a1;
	string a2;
	string a3;
	string a4;
	int numOfTheCorrectAnswer;
	string correctAnswer;

public:
	Question()
	{
		trQuestion = "";
		a1 = "";
		a2 = ""; 
		a3 = ""; 
		a4 = "";
		numOfTheCorrectAnswer = 0;
		correctAnswer = "";
	}
	Question(string trQ, string aa1, string aa2, string aa3, string aa4, int nca, string corrAnsw)
	{
		trQuestion = trQ;
		a1 = aa1;
		a2 = aa2;
		a3 = aa3;
		a4 = aa4;
		numOfTheCorrectAnswer = nca;
		correctAnswer = corrAnsw;
	}
	~Question()
	{
	}
	void  setTriviaQuestion(string trQ);
	void setAnsw1(string aa1);
	void setAnsw2(string aa2);
	void setAnsw3(string aa3);
	void setAnsw4(string aa4);
	void setNumOfTheCorrectAnswer(int nca);
	void setCorrectAnswer(string corrAnsw);
	string getTriviaQuestion() const;
	string getAnsw1() const;
	string getAnsw2() const;
	string getAnsw3() const;
	string getAnsw4() const;
	string getCorrectAnswer() const;
	int getNumOfTheCorrectAnswer() const;
};

