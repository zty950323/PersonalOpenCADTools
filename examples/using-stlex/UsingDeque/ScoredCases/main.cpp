
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// class for person.
class Person {
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name; // the name of the person.
	int m_Score;  // the score of the person.
};

void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		// put the person into the vector.
		v.push_back(p);
	}
}

// make score of the person.
void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//make test score.
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;  // 60 ~ 100
			d.push_back(score);
		}

		// sort the score.
		sort(d.begin(), d.end());

		// remove the hightest and lowest score.
		d.pop_back();
		d.pop_front();

		// get the average score.
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; // add all the score which is get from the deque.
		}

		int avg = sum / d.size();

		// make the score into the person.
		it->m_Score = avg;
	}

}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "Name: " << it->m_Name << " Avage: " << it->m_Score << endl;
	}
}

void TzDequeScoredCase01()
{
	// the rondom seed.
	srand((unsigned int)time(NULL));

	// 1. create five person.
	vector<Person>v;  // store the person.
	createPerson(v);

	// 2. set the score of the persons.
	setScore(v);

	// 3. show the score of the persons.
	showScore(v);
}

int main(int argc, char *argv[])
{
	TzDequeScoredCase01();

	system("pause");
	return 0;
}