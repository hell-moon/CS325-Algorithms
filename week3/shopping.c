#include<stdio.h>
#include<stdlib.h>

void error(const char *msg)
{
	perror(msg);
	exit(0);
} // Error function used for reporting issues

int main(){
	// open file 'shopping.txt'
	FILE *data = fopen("shopping.txt", "r");
	if(data == NULL){
		error("unable to open shopping.txt");
	}
	FILE *outFile = fopen("results.txt", "w");
	if(outFile == NULL){
		error("unable to open results.txt");
	}
	// first line is the number of test cases
	// first line of each test case is number of items, N
	// after N lines read, the next line is number of family members, M
	// after M lines read, next test case starts

	return 0;
}
