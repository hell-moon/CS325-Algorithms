# HW 1 Merge Sort and Insertion Sort Implementations

Both programs are written in C. To compile, use these commands in terminal:
`gcc -g -o merge mergesort.c`, and
`gcc -g -o insert insertsort.c`, respectively. 

Then to run the compiled programs, type in terminal:`./merge` and `./insert`

Both programs will read the line-separated lists in 'data.txt', sort, and write the sorted lists into 'merge.txt' and 'insert.txt', respectively. 

MergeSort implementation was adapted to C from the Java implementation from khanacademy's 'implement challenges' on the subject. GeeksForGeeks was also used as reference for the pseudocode.   

# HW 1 Merge sort and Insert Sort Time Analysis Modifications

Both of the analysis programs were written in C.  To compile, use these commands in terminal:
`gcc -g -o mergeTime mergeTime.c`, and
`gcc -g -o insertTime insertTime.c`, respectively.  

To run the programs, pass in the size of the randomly generated array you want to sort, after the program name. In terminal: `./mergeTime 50000`, and `./insertTime 10000` will result in random lists of size 50,000 and 10,000, respectively to be generated and sorted by each program.  Each sort program is set to generate and sort 5 times, and output those times to standard out.  
