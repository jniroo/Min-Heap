
/*
        This is the heap.cpp which I have all my methods for the heap class
        @creature James Niroomand
        @date 03152018
*/

/************************************This is the main Program ****************************************/

// includes files 
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdio.h>

#include "heap.h"
#include "util.h"

// using namespace to make things easier
using namespace std;

// initial command is set to false
bool command = false;


// defining element Arra of A 
Element *A;


/*
     Defining heap Array w
     @param size       it takes size of the array 
*/
void heapArray(int size)
{   
    // defining the element A array with integer size 
    A = new Element[size];
}

/*
      The Main function 
*/
int main() {

    // defining verbals 
    int i, k;
    int flag = 0;
    // the heap object 
    HEAP heap;
    
    // variables to read command 
    bool createHeap = false;
    char command = '\n';
    char exit = 's';

    while( command != exit)
    {
        command = nextCommand(i, k, flag);
        int size = 0;
        
        switch (command)
        {
            case 'c':
            case 'C':
                if(command){printf("COMMAND: %c %d\n", command, i);}
                if(createHeap){
                        heap = Initialize(i);
                    }
                if(!createHeap)
                {
                    if(i > 0)
                    {
                        heap = Initialize(i);
                        createHeap = true;
                    }
                    else 

                        alert(5);
                }
               
                break;
            case 'r':
            case 'R':
                if(command){printf("COMMAND: %c\n", command);}
                if(createHeap)
                {
                 
                    size = ReadFile();
                    if(size == 0)
                        break;
                    if(heap.getCapacity() > size + heap.getCapacity()){
                        alert(4);
                    }
                    else if(heap.getCapacity() < size + heap.getSize()){
                        alert(12);
                    }else {
                        heapArray(size);
                        ReadFile(heap, A, size);
                        BuildHeap(heap, A, size);
                    }
                    
                
            }
                else
                    alert(2);
                break;

            case 'w':
            case 'W':
                if(command){printf("COMMAND: %c\n", command);}
                if(createHeap)
                    PrintHeap(heap);
                else

                    alert(2);
                break;

            case 'i':
            case 'I':
                if(command){printf("COMMAND %c %d %d \n", command, i, flag);}
                if(createHeap)
                {
                    if(flag == 0){
                    if(heap.getSize() < heap.getCapacity())
                        Insert(heap, i, flag);
                    else{
                        heap.setCapacity();
                        Insert(heap, i, flag);
                    }
                }
                if(flag == 1){
                    PrintHeap(heap);
                    if(heap.getSize() < heap.getCapacity())
                        Insert(heap, i, flag);
                    else{
                        heap.setCapacity();
                        Insert(heap, i, flag);
                    }
                    PrintHeap(heap);
                }
                       
                }
                else
                    alert(2); 
                break;
            case 'k':
            case 'K':
                if(command){printf("COMMAND: %c %d %d %d \n", command, i, k, flag);}
                if(createHeap)
                {
                    if(flag == 0){
                        if(i > heap.getSize())
                        {
                        alert(3);
                        }
                    //CHECK IF VALUE IS LARGER THAN EXISTING VALUE
                        if(k > heap.getElement(i).key)
                        DecreaseKey(heap, i, k, flag);
                    }
                    if(flag == 1){
                        PrintHeap(heap);
                        if(i > heap.getSize())
                        { 
                        alert(3);
                        }
                    //CHECK IF VALUE IS LARGER THAN EXISTING VALUE
                    if(k > heap.getElement(i).key)
                        DecreaseKey(heap, i, k, flag);
                        PrintHeap(heap);
                    }

                }
                else
                    alert(11);

                break;

            case 'd':
            case 'D':
                if(command){printf("COMMAND: %c %d\n", command, flag);}
                if(createHeap)
                {
                    if(flag == 0){
                    if(heap.getSize() <= 0)
                    {
                        alert(6);
                        break;
                    }
                    else
                        cout <<  DeleteMin(heap, flag) << "\n";
                    }
                    if(flag == 1){
                        PrintHeap(heap);
                    if(heap.getSize() <= 0)
                    {
                        alert(6);
                        break;
                    }
                    else
                        cout <<  DeleteMin(heap, flag) << "\n";
                        PrintHeap(heap);
                    }
                }

                else
                    alert(10);
                break;
            case 's':
            case 'S':
                if(command)
                {
                    cout << "COMMAND: " << command << "\n";
                    cout << "\nThe program going to be terminated!\n";
                }
                command = 's';
                break;
            default: break;
        }
    }   
    delete[] A;
    return 0;   
}







