#include<iostream>
using namespace std;

// CS311 YOSHII F23 partition.cpp
// You may not change my code in any manner.  0 pts if you do!!!!!!
// Simply add your code for **
//  NEVER delete my comments!!
//----------------------------------------
//CS311 HW2P2 Partition
//Name: Kayla Le
//Compiler: g++
//File Type: partition implementation file partition.cpp
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// a is the array 
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition( int a[], int f, int r)
{
  int pivot = a[f];  // pivot is the first element
  int small = f; // pointer from the left
  int large = r; // pointer from the right 

  while (small <= large)//until they cross
    {
      // loop for finding out of place pairs and swap them
      //    until the small and large cross
      //    if small OK, move left
      //    if large OK, move right
      //    if both are bad, swap and then move

     if(a[small] < pivot){
        small++; //if the pointer is at a small -  move
      }
     else if(a[large] >= pivot){
       large--;//if the pointer is at a large - move
      }
     else if(a[small] >= pivot && a[large] < pivot){//if both pointers are mismatched swap 
    
     int temp = a[small];//temp holder for small int in large section
     a[small] = a[large];//one swap
     a[large] = temp;//other swap   

     small++; //arrow moves
     large--;//arrow moves
     } 
    }//end of while

   // return the partition point where
   // those smaller than pivot are before what is returned
   // there is a special cases and a regular case
   if(small == 0){
      return 1;//special case  - no larger section 
    }
   else{
     return (large + 1);//return first slot of larger section 
    }
 
}
//Purpose: take 1 array, partition the array in place into the small and large parts, using the first element of the list as the pivot 
//Design: prompt user to input amount of elements, enter elements one per line, print out pivot, print out small part of array and then large part of array with a seperator 
int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}
