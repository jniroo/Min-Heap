/*
        This is the heap.cpp which I have all my methods for the heap class
        @creature James Niroomand
        @date 03152018
*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "heap.h"

using namespace std;



/*
    Class Constructor
    @params heapCapacity    capacity of the heap
    @params heapSize        size of the heap 
    @params H[]             Element Array
*/
HEAP::HEAP(int heapCapacity, int heapSize, Element H[])
{
    capacity = heapCapacity;
    size = heapSize;
    element = new Element[heapCapacity];
    
    for(int i = 0 ; i < heapSize ; i ++ )
    {
        element[i] = H[i];
    }
}

/*
    Default Class Constructor

*/
HEAP::HEAP()
{  
}

/*
    Class Constructor
    @params heapCapacity    capacity of the heap
    @params heapSize        size of the heap 
*/
HEAP::HEAP(int heapCapacity, int heapSize)
{
    capacity = heapCapacity;
    element = new Element[heapCapacity];
    size = heapSize;
}

/*
    Class Distructor to empty the space
*/
HEAP::~HEAP(void)
{
    element = new Element[1];
    delete[] element;
}



/*
    Initizlie               This starts the heap
    @params heapCapacity    capacity of the heap
    @return                 returns the heap object   
*/
HEAP Initialize(int heapCapacity)
{
    HEAP heap(heapCapacity, 0);
    return heap;
}

/*
    Insert                  Helper function to insert ot heap
    @params heap            Heap object
    @@params keyElement     key of Element              
*/

void HeapInsert(HEAP &heap, Element keyElement)
{
    heap.IncreaseSize();
    heap.setElement(heap.getSize(), keyElement);


}

/*
    Heapify                 Helper Functiont to maintain min heap property
    @params heap            takes heap object
    @param element          integer element to  
*/

void Heapify(HEAP &heap, int element)
{
    
 
    int leftKey, rightKey, minimum;
    int current = heap.getElement(element).key;
    int leftNum = heap.Left(element);
    int right_n = heap.Right(element);

    if(leftNum <= heap.getSize())
    {
        leftKey = heap.LeftChildElement(element).key;

        if(leftKey < current)
            minimum = leftNum;
        else
            minimum = element;
    }
    else
        minimum = element;
    if(right_n <= heap.getSize())
    {
        rightKey = heap.RightChildElement(element).key;

        if(rightKey < heap.getElement(minimum).key)
            minimum = right_n;
    }
    if(minimum != element)
    {
        Element minimumElm = heap.getElement(minimum);
        heap.setElement(minimum, heap.getElement(element));
        heap.setElement(element, minimumElm);
        Heapify(heap, minimum);
    }
}

/*
    BuildHeap           This functions build the heap and 
                        outputs the sorted Min-Heap
    @params heap        HEAP object
    @params H           ELement Array
    @params size        size of theh array
*/
void BuildHeap(HEAP &heap, Element H[], int size)
{
    int initialSize = heap.getSize();

    for (int i = initialSize ; i < initialSize + size && i < heap.getCapacity(); i++)
    {
        HeapInsert(heap, H[i-initialSize]);    
    }

    for(int i=floor(heap.getSize()/2); i >= 1 ; i--)
    {
        Heapify(heap, i);
    }
}

/*
    insert                   Functiont to maintain min heap property
    @params heap            takes heap object
    @param element          integer int to  
*/



void Insert(HEAP &heap, int k, int flag)
{
    //Make the new element
    Element newElement;
    newElement.key = k;

    
    //Insert the new element into the Heap
  
        HeapInsert(heap, newElement);

                for(int i=floor(heap.getSize()/2); i >= 1 ; i--)
        {
            Heapify(heap, i);
        }           
}


/*
                     Helper Functiont to maintain min heap property
    @params heap            takes heap object
    @param element          integer element to  
*/


int DeleteMin(HEAP &heap, int flag)
{
    Element deleted_element = heap.getElement(1);


        heap.setElement(1, heap.getElement(heap.getSize()));
        heap.decreaseSize();

        for(int i=floor(heap.getSize()/2); i >= 1 ; i--)
        {
            Heapify(heap, i);
        }  

        return deleted_element.key;
    
}

/*
                     Helper Functiont to maintain min heap property
    @params heap            takes heap object
    @param element          integer element to  
*/
void DecreaseKey(HEAP &heap, int element, int key, int flag)
{
    //Set the element key
    if(flag == 0){
        heap.setKey(element, key);

        while(element > 1 && heap.ParentElement(element).key >= key)
        {
            heap.swap(element);
            element = heap.Parent(element);
        }
    }
    else if(flag == 1){
        cout << "The heap before the decrease" << '\n';
        PrintHeap(heap);
        heap.setKey(element, key);

        while(element > 1 && heap.ParentElement(element).key >= key)
        {
            heap.swap(element);
            element = heap.Parent(element);
        }
        cout << "The heap after the decrease" << '\n';
        PrintHeap(heap);
    }
 }

/*
                     Helper Functiont to maintain min heap property
    @params heap            takes heap object
    @param element          integer element to  
*/
void PrintHeap(HEAP heap)
{
    cout << "The capacity is " << heap.getCapacity() << "\n";
    cout <<  "size is " << heap.getSize() << "\n";
    for (int i=1 ; i <= heap.getSize() ; i++)
    {
        cout << heap.getElement(i).key << "\n";
    }

}
 