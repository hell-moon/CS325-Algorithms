# CS325 HW 4, Greedy Algorithms
This program implements the greedy-selection method to choose an optimal solution to the activity selection problem.  This implementation chooses the last compatible activity to start, from a list of activities sorted by decreasing start time.  

## Compilation and Execution of Program
To compile, we need to specify the C++ 11 standard.  Type in terminal: 
`g++ -g -o greedy greedyAlgorithm.cpp -std=c++11`

The source file is named `greedyAlgorithm.cpp` and the program name is `greedy`.
To execute the program, type in terminal: `./greedy`, and it will read the provided `act.txt` file containing the activities.  
