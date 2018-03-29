
/*
        This is the heap.cpp which I have all my methods for the heap class
        @creature James Niroomand
        @date 03152018
*/
 #include "heap.h"
 #include "util.h"
 #include <fstream>
 #include <iostream>

 using namespace std;



 string filename = "HEAPinput.txt";

/*
                     Helper Functiont to maintain min heap property
    @params heap            takes heap object
    @param element          integer element to  
*/
 int ReadFile()
 {
 	int size;
 	string line;

 	ifstream inputfile(filename.c_str());
 	if(inputfile.is_open())
 	{
 		inputfile >> line;
 		size = atoi(line.c_str());
 		if(!size || size < 1)
 		{
 			alert(7);
 			return 0;
 		}

 	}
 	else
 	{
 		alert(1);
 		exit(0);
 	}

 	inputfile.close();
 	return size;

 }

/*
                     Helper Functiont to maintain min heap property
    @params heap            takes heap object
    @param element          integer element to  
    @param size  			takes integer size 
*/
 void ReadFile(HEAP &myHeap, Element Arr[], int size)
 {
 	int num;
 	int count = 0;
 	string line;

 	ifstream inputfile(filename.c_str());
 	if(inputfile.is_open())
 	{
 		inputfile >> line;

 		while(inputfile >> line)
 		{	
 			num = atoi(line.c_str());
 			if(!num)
 			{
 				warning(2);
 			}
 			count ++;
 			if(count <= size && count + myHeap.getSize() <= myHeap.getCapacity() )
 			{
 				Element temp;
 				temp.key = num;
 				Arr[count-1] = temp;
 			}
 			
 		}
 		if(count > size)

 			warning(3);
 	}
 	else
 	{
 		alert(1);
 		exit(0);
 	}
 	inputfile.close();
 }

/*
                 COMMANAND FUNCTION it takec char command and prints out based on those characters
    @params i           integer element
    @param v         	integer element 
    @params flag		integer flag if it is one it prints out the heap before and after 
*/
int nextCommand(int& i, int& v, int& flag)
{
  char c;
  while(1)
  {
    scanf("%c", &c);
    if(c == ' ' || c == '\t' || c == '\n')
    {
		continue; 
	}
    if(c == 'S' || c == 'R' || c == 'W' )	
    {
        break;
    }
   
    if(c == 's' || c == 'r' || c == 'w')
    {
    	 scanf("%d", &flag);
		break; 
	}
	 if(c == 'D' || c == 'd')
    {
	 	scanf("%d", &flag);
	 	break;
    }
    if(c == 'K' || c == 'k')
    {
        scanf("%d", &i); 
        scanf("%d", &v);
        scanf("%d", &flag);
        break;
	}
	if (c == 'C' || c == 'c')
	{
		scanf("%d", &i);
		break;
	}
	if(c == 'I' || c == 'i')
	{
		scanf("%d", &i);
		scanf("%d", &flag);
		break;
	}
	if(c == 'D' || c == 'd')
	{
		scanf("%d", &i);
		scanf("%d", &flag);
		break;
	}
    printf("Command is not valid\n");
  }
return c; 
}
/*
                     Helper Functiont to maintain min heap property
    @params e            takes integer for cases 
*/
void alert(int e)
{
	switch(e)
	{
	case 1:
		cout <<"There was a problem opening file HEAPinput.txt for reading\n";
		break;
	case 2:
		cout << "Sorry!!! It can not be done.  Please initialize the heap first\n";
		break;
	case 3:
		cout << "There are only " << e << " element in heap. Hence this operation can not be completed";
		break;
	case 4:
		cout << "Sorry!!! it can not be done. The number of element in the file is less than as specifeid in begining of file \n";
		break;
	case 5:
		cout << "The capacity of heap has to be larger than  0\n";
		break;
	case 6:
		cout << "There is no elements in heap to delete\n";
		break;
	
	case 7:
		cout << "Size should be larger than 0\n";
		break;
	case 8:
		cout << "REQUESTED ELEMENT IS OUTSIDE OF THE SIZE OF THE HEAP\n";
		break;
	case 9:
		cout << "The heap is at maximum capacity\n";
		break;
	
	case 10:
		cout << "Sorry!!! It can not be done.  Please initialize the heap first and put element in it\n";
		break;
	case 11:
		cout << "Sorry!!! It can not be done.  Please initialize the heap first and put value in it\n";
		break;
	case 12:
		cout << "Sorry!!! It can not be done. Please increase the capacity of the heap \n";
		break;

	default:
		cout << "Houston we have a problem";
		exit(0);
		break;
	}
}

/*
                     function which gives warning if other files entered 
    @params integer         take integer w 
*/

void warning(int w)
{
	cout << "WARNING: ";
	switch(w)
	{
		case 1:
			cout << "More line then specified \n";
			break;
		case 2:
			cout << "file is not a number\n";
			break;
		case 3:
			cout << "More lines than the capacity, will only read up to capacity\n";
			break;

		default:
			cout << "Uknown warning\n";
			break;
	}
}


