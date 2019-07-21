#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::sort;


struct activities
{
	int start;
	int finish;
	int num;
	bool chosen;
};

bool myfunction (activities left, activities right){
	return (left.start > right.start);
}

void greedyActivity(activities list[], int size){
	// this greedy algorithm gets passed an array of activites, each with their own start and finish time
	// assume the list of activities is sorted by start time in descending order
	int itr = 0;
	int total = 1; //keep track of number of activities chosen

	// the first activity is always chosen
	list[0].chosen = true;

	// consider the rest of the activities:
	for( int i = 1; i < size; i++){
		// if this activity's finish time is less than or equal to the previous activity's start time, choose it
		if(list[i].finish <= list[itr].start){
			list[i].chosen = true;
			total++;
			itr = i;
		}
	}

	// print list of chosen activities:
	cout << "Number of activities selected = " << total << endl;
	cout << "Activities: ";
	for(int i = 0; i < size; i++){
		if(list[i].chosen){
			cout << list[i].num << " ";
		}
	}
	cout << endl;

}

int main()
{

	int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int f[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

	struct activities list[20];

	int n = 11;
	int i, j, k;
	for(i = 0; i < 11; i++){
		list[i].start = s[i];
		list[i].finish = f[i];
		list[i].num = i+1;
		list[i].chosen = false;
	}

	sort(&list[0], &list[11], &myfunction);

	greedyActivity(list, n);
	return 0;
}
