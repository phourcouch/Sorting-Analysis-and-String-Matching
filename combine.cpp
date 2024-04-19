using namespace std;
#include <iostream>
#include <vector>

// CS311 YOSHII F23 combine.cpp
// Must use the algorithm that is in the notes! 
//  NEVER delete my comments!!
//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Kayla Le
//Compiler: g++
//File Type: combine  implementation file combine.cpp
//--------------------------------------------

// combines two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{

    if(A.size() == B.size()){ // you can find out the size of A using the - checking if lists are same sizes
   
	int ia = 0;//index for A
	int ib = 0;//index for B
      
	   while(ia < A.size() &&  ib < B.size()){//loop until you run out of elements in A or B

			cout << "comparison" << endl;//my apologies i accidentally deleted the original line of code

		if(A[ia] < B[ib]){//if A[ia] is less than B[ib] then push A[ia] to R (keeping it sorted) otherwise push B[ib] to R
			 R.push_back(A[ia]);
			 ia += 1;//increment index for A
		}
		else {
			 R.push_back(B[ib]);
			 ib += 1;//increment index for B
		}
                         // size function. Treat A and B like arrays. 
     // be careful -- R comes in as an empty vector with no slots so you have to use push_back
  	 }//end of  loop
		while(ia < A.size()){//while index is less than A size 
			R.push_back(A[ia]);//pushing to R
			ia += 1;//increment
		}

		while(ib < B.size()){//while index is less than B size
			R.push_back(B[ib]);//pushing to R
			ib += 1;//increment 

		}


     }//end of if 
}//end of combine

//Purpose: take 3 vectors, combine the elements of the first and second list ( A and B) to produce the sorted list R and display comparsion every time an element to element comparison is done
//Design: prompt user for amount of elements in each list, push input to each list, call combine function to combine the two lists and combine them into another, and then print out the combined list
int main()
{  
  vector<int> L1;//list A
  vector<int> L2;//list B
  vector<int> L3;//list R
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  combine(L1,L2,L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
