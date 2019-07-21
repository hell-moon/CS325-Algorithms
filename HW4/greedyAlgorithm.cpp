#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::sort;
using std::stoi;
using std::string;

struct activities
{
	int start;
	int finish;
	int num;
	bool chosen;
};

bool myfunction(activities left, activities right)
{
	return (left.start > right.start);
}

void greedyActivity(activities list[], int size)
{
	// this greedy algorithm gets passed an array of activites, each with their own start and finish time
	// assume the list of activities is sorted by start time in descending order
	int itr = 0;
	int total = 1; //keep track of number of activities chosen

	// the first activity is always chosen
	list[0].chosen = true;

	// consider the rest of the activities:
	for (int i = 1; i < size; i++)
	{
		// if this activity's finish time is less than or equal to the previous activity's start time, choose it
		if (list[i].finish <= list[itr].start)
		{
			list[i].chosen = true;
			total++;
			itr = i;
		}
	}

	// print list of chosen activities:
	cout << "Number of activities selected = " << total << endl;
	cout << "Activities: ";
	for (int i = 0; i < size; i++)
	{
		if (list[i].chosen)
		{
			cout << list[i].num << " ";
		}
	}
	cout << endl;
}



int main()
{

	ifstream actFile;
	actFile.open("act.txt");

	int charRead = -5;
	string buffer;
	char *lineptr = NULL;
	size_t n = 0;

	int sets = 1;

	// get number of activities from file
	while (getline(actFile, buffer))
	{
		cout << "Set " << sets << endl;
		sets++;
		int num = stoi(buffer);
		activities list[num];

		// cout << "num activities: " << num << endl;
		for (int k = 0; k < num; k++)
		{
			// parse each activity into a struct
			// each activity has the activity number, the start time, and finish time
			getline(actFile, buffer);
			std::stringstream check1(buffer); //turn string into a readable stream to tokenize
			string token;	//store tokens in this string
			getline(check1, token, ' ');	//parse the string stream separated by spaces into token
			list[k].num = stoi(token);		//for each token, convert to integer and insert into appropriate struct member
			getline(check1, token, ' ');
			list[k].start = stoi(token);
			getline(check1, token, ' ');
			list[k].finish = stoi(token);
			list[k].chosen = false;
		}
		// using STL sort because the goal of this program was not to implement a sort algorithm, but a greedy algorithm for selecting activities.  The STL sort runs in O(nlgn) time: https://en.wikipedia.org/wiki/Sort_%28C%2B%2B%29
		// sort will use myfunction to sort start times in descending order
		sort(&list[0], &list[num], &myfunction);

		greedyActivity(list, num);
		cout << '\n';
	}
	return 0;
}
