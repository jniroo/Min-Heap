/*
* @Title This is C++ Min-Heap Project for CSE 310 Classs
* @author James Niroomand
* @date  03152018
* 
*/

// packeges to include with this project 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

// using name space to make things easier 
using namespace std;

#ifndef HEAP_H
#define	HEAP_H
 

// using struct Element Objct with integer key data
struct Element
{
    int key;
};

/*
    This is the main class Heap 
    This class takes three data points capacity, size and Element Array
*/
class HEAP {
    private:
        // private data 
        int capacity;
        int size;
        Element *element;
    public:
        // defualt constructor 
        HEAP ();
        // constructors 
        HEAP (int, int, Element[]);
        HEAP (int, int, int);
        HEAP (int, int);
        // distructors 
        ~HEAP();
        
        
        // Getters 
        // get the size 
        int getSize() 
        {
            return size;
        }
        // get the capacity
        int getCapacity() 
        {
            return capacity;
        }
        // get the element
        Element getElement(int n)
        {
            return element[(n-1)];
        }


        // function to increase the size 
        void IncreaseSize() 
        {
            size++;
        }
        // function to decrease the size
        void decreaseSize() 
        {
            size--;
        }
        // setter for capacity
        void setCapacity()
        {
                capacity = capacity * 2;
        }
        // setting the element and  pointing to index of ELement
        void setElement(int n,  Element keyElement) {this->element[(n-1)] = keyElement;}
        // pointing to value of the element
        void setKey(int n, int key) {this->element[(n-1)].key = key;} 
        /********************* Helper functions to make heap property ****************************/
        // parent function returns the root 
        int Parent(int n)
        {
            if(n == 1)
                return 0;
            else
                return floor(n/2);
        }
        // parenet element points to the struct element
        Element ParentElement(int n)
        {
           return (this->getElement(this->Parent(n)));
        }
        // returns the right child
        int Right(int n)
        {
                return n*2+1;
        }
        // points to the right child of struct element
        Element RightChildElement(int n)
        {
            return this->getElement((2*n)+1);
        }
        // returns the left child
        int Left(int n)
        {
                return n*2;
        }
        // points to the let child of the struct element
        Element LeftChildElement(int n)
        {
            return this->getElement(2*n);
        }
        
        // functions to swap elements 
        void swap(int n)
        {
            Element parentElm = this->ParentElement(n);
            this->setElement(this->Parent(n), this->getElement(n));
            this->setElement(n, parentElm);
            return;
        }        
    
}; 

/*
    *****************   This are the fuctions which are supported with heap class  *************************
*/

/*
    starts the heap
    @param int
*/
HEAP Initialize(int);

/*  
    Builds the heap
    @param heap, element array, int
*/
void BuildHeap(HEAP&, Element[], int);

/*  
    Inserts into heap a new element
    @param heap, int , int
*/
void Insert(HEAP&, int, int);
/*  
    Deletes the Minimum ket
    @param heap, int 
*/
int  DeleteMin(HEAP&, int);

/*  
    Decrease Key  
    @param heap, int, int
*/
void DecreaseKey(HEAP&, int, int, int);

/*  
    PrintHeap       This function printts the contenet of the heap 
    @param heap     
*/

void PrintHeap(HEAP);

/*  
    HeapInsert          Helper function to insert element into the heap
    @param heap, int , int
*/

void HeapInsert(HEAP&,  Element);

/*  
    Heapfiy             This function turns the array into minheap 
    @param heap, int
*/
void Heapify(HEAP&, int);




#endif	/* HEAP_H */

