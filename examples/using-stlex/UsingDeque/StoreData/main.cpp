
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <deque>

using namespace std;

void TzDequeStoreDataCase01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}

	cout << endl;

	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
}

void TzDequeStoreDataCase02()
{
	// using at().
	std::deque<int> data = {1, 2, 4, 5, 5, 6};
	// Set element 1
	data.at(1) = 88;

	// Read element 2
	std::cout << "Element at index 2 has value " << data.at(2) << '\n';

	std::cout << "data size = " << data.size() << '\n';

	try
	{
		// Set element 6
		data.at(6) = 666;
	}
	catch (std::out_of_range const &exc)
	{
		std::cout << exc.what() << '\n';
	}

	// Print final values
	std::cout << "data:";
	for (int elem : data)
		std::cout << " " << elem;
	std::cout << '\n';
}

// using [] to access the element.
void TzDequeStoreDataCase03()
{
	std::deque<int> numbers{2, 4, 6, 8};

	std::cout << "Second element: " << numbers[1] << '\n';

	numbers[0] = 5;

	std::cout << "All numbers:";
	for (auto i : numbers)
	{
		std::cout << ' ' << i;
	}
	std::cout << '\n';
}

int main(int argc, char *argv[])
{
	TzDequeStoreDataCase01();
	TzDequeStoreDataCase02();
	TzDequeStoreDataCase03();

	system("pause");
	return 0;
}