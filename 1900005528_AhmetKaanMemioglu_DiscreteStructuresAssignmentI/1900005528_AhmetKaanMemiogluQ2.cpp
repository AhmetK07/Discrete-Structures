#include <iostream>

#include <vector> //Using vector library for our RandomArray.

#include <algorithm>  //For the sort function we are using algorithm library.

using namespace std;

void Swap(int *LeftNumP, int *RightNumP); //A basic swap function for our sorting algorithms to swap the number.

void BubbleSort(vector<int>RandomArray, int SizeOfArray, int *CompNum); 

void InsertionSort(vector<int>RandomArray, int SizeOfArray, int *CompNum);

vector<int> RedistributionOfArray(vector<int>RandomArray); //Because that we cannot declare a dynamic array we have to use vectors.


int main(void)

{




	int CompNum = 0; // We declare a comparison number variable to count how many times we have searched.

	int SizeOfArray;  //To store information about how big the size of our array is.

    int SizeOfArray2; //Making another Size of array so we do not coincide with the other size.

	cout << "Q2 -Number of Comparisons on Sorted  (In Ascending Order) Arrays" << endl;

	cout << "SIZE: "; 

	cin >> SizeOfArray;  //First of all we ge the array size which is sorted from the user.

	vector<int> RandomArray(SizeOfArray); //Because we cannot store a user input for the size of our array we need to use vectors in c++.
	
										  //And we store the value to our vector array if we did not use vector array we couldn't store it because c++ does not allow dynamic arrays.

										  //It requires constant values.

	for (int i = 0; i < SizeOfArray; i++)

	{

		RandomArray[i] = rand() % SizeOfArray + 0; //Our Random array is filled with random numbers.

	}

	cout << endl;

	cout << endl;

    vector<int>SortedArray(SizeOfArray);  //We are making another array so that we differentiate from the random array. 

    SortedArray = RedistributionOfArray(RandomArray); //We declare the Sorted array's values as the sorted version of RandomArray with the use of RedistributionOfArray function.

	BubbleSort(SortedArray, SizeOfArray, &CompNum); //We are calling the BubbleSort function to sort our array.

	cout << "Bubble Sort # of Comparisons   :" << CompNum;  //Comparison number gets displayed.

    CompNum =0;  //After that it gets refreshed so that we can use it on another action.

	cout << endl;

	InsertionSort(SortedArray, SizeOfArray, &CompNum); //InsertionSort gets called and we apply isertion upon the array.

	cout << "Insertion Sort # of Comparisons:" << CompNum; //And the number of Comparisons are displayed here.

    CompNum =0; //We once again clear out the value of CompNum.

	cout << endl;

    cout << "Q-2 Number of Comparisons on Randomly Generated (Unsorted) Arrays"<<endl;

    cout << "SIZE: ";

	cin >> SizeOfArray2; //We get the other array's size from the user once again.

	BubbleSort(RandomArray, SizeOfArray2, &CompNum); //We apply the BubbleSort upon the array.

	cout << "Bubble Sort # of Comparisons   :" << CompNum; //The times of comparisons are getting displayed here.

    CompNum =0; //We clear the value of CompNum once again.

	cout << endl;

	InsertionSort(RandomArray, SizeOfArray2, &CompNum);  //We apply Insertion sort on the random array.
    
	cout << "Insertion Sort # of Comparisons:" << CompNum; //And we once again print out the CompNum.

    CompNum =0; //After that CompNum gets hollowed again.

	cout << endl;
	
}


void Swap(int *LeftNumP, int *RightNumP) //We implament a basic swap function for our BubbleSort function.

{

	int temp = *LeftNumP; //First we create temporary integer value and we store set the value of LeftNumP to it.

	*LeftNumP = *RightNumP; //Then the LeftNumP's value gets set to the RightNumP.

	*LeftNumP = temp; //After that the LeftNumP's value gets set to temp.

					  //We basically carry out the values of our index's value then replace them by value.

}


void BubbleSort(vector<int>RandomArray, int SizeOfArray, int *CompNum)  //We implement a BubbleSort algorithm to c++.

{

	int i; //First we set two values for our loops.

	int j; 

	for (i = 0; i < SizeOfArray - 1; i++) // As long as our size of array -1  is greater then the index  we are searching.

	{
		
		
		for (j = 0; j < SizeOfArray - i - 1; j++) // As long as our size of array -i - 1  is greater then the index  we are searching.

		{

            (*CompNum)++; //We update and increase the value as we enter the loop.
			
			if (RandomArray[j] > RandomArray[j + 1])

			{
                

				Swap(&RandomArray[j], &RandomArray[j + 1]); //We call the swap function to swap the values of indexes.


			}


		}


	}


}


void InsertionSort(vector<int>RandomArray, int SizeOfArray, int *CompNum)

{

	int i;

	int key;

	int j;
    
	for (i = 1; i < SizeOfArray; i++)
    
	{   
        
        (*CompNum)++; //first for all the times that this loop runs we update the CompNum.
		
		key = RandomArray[i];

		j = i - 1;
       
		while (j >= 0 && RandomArray[j] > key) //As long as the varaible j's value is greater or equal to zero and RandomArray's index's value is greater then key we are doing these operations.

		{

            (*CompNum)++; //Second of all we are once again updating the value of CompNum because there is another loop within the loop.
             
			RandomArray[j + 1] = RandomArray[j]; 

			j = j - 1;
            
		}

		RandomArray[j + 1] = key;
      
	}
    
     
}




vector<int> RedistributionOfArray(vector<int>RandomArray) //We are organizing our vector array because it is performing better in binary search and after redestribition we are avoiding errors when searching.

{

	sort(RandomArray.begin(), RandomArray.end()); //This sort functions sorts our RandomArray in a non decreasing order with the help of algorithm library.


	return RandomArray; //And after that we are returning the RandomArray value to be set to a new sorted value.

}

//I was going to use VisualStudio for the code but i couldnt it kept giving me error in the case of not having on the list instead i have used VisualStudioCode.

//I have added ScreenShots of the error and the working screenshots in the rar.