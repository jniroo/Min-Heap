# Min-Heap

Language: C++

The following commands are acceptable with this program:

S 
C n 
R 
W 
I k f
D f 
K i v f
On reading S, the program stops.
On reading C n, the program creates an empty heap with capacity equal to n, and waits for the next command.
On reading R, the program reads in the array A from file HEAPinput.txt, calls the linear time build heap algorithm to build the min-heap based on A, and waits for the next command.
On reading W, the program writes the current heap information to the screen, and waits for the next command. The output should be in the same format as in the file HEAPinput.txt, proceeded by the heap capacity.
On reading I k f, the program inserts an element with key equal to k into the current heap with the corresponding flag set to f, and waits for the next command.
On reading D f, the program deletes the minimum element from the heap with the corresponding flag set to f, and prints the key field of the deleted element on the screen, it waits for the next command.
On reading K i v f, the program decreases the key of element with index i to v with the corre- sponding flag set to f.
The file HEAPinput.txt is a text file. The first line of the file contains an integer n, which indi- cates the number of array elements. The next n lines contain n integers, one integer per line. These integers are the key values of the n array elements, from the first element to the nth element.