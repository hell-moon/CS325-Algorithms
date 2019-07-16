#CS325 Algorithms HW2 Stooge Sort
Included are both the stoogeSort and stoogeTime programs.  The stoogeSort program reads lines of lists from data.txt and sorts the lists into a file, stooge.txt.  The stoogeTime program prints the running time of the sorting algorithm on 8 randomly generated lists.  The size of the lists it generates are hardcoded in a sizelists[] array inside the main function. 

##Compiling And Running Programs
The stoogeSort program can be compiled in terminal with `gcc -g -o stoogeSort stoogeSort.c -lm`, and can be run with the command `./stoogeSort`.  This will write the sorted lists read-in from data.txt into a file named stooge.txt. 

The stoogeTime program can be compiled in terminal with `gcc -g -o stoogeTime stoogeTime.c -lm`, and can be run with the command `./stoogeTime`.  This will generate 8 lists, with random integers between 0 and 10,000, with various sizes from n=3000 to 5000 and print the time to sort those lists to terminal.  

