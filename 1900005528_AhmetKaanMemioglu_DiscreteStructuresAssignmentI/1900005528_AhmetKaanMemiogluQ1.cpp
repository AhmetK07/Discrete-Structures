#include <iostream>

#include <vector> //Using vector library for our RandomArray.

#include <algorithm> //For the sort function we are using algorithm library.

using namespace std;

int LineerSearch(vector<int>RandomArray, int SizeOfArr, int SearchNum, int *CompNum);

int BinarySearch(vector<int>RandomArray,int BeginningOfArray, int EndOfArray, int SearchNum, int *CompNum);

vector<int> RedistributionOfArray(vector<int>RandomArray); //Because that we cannot declare a dynamic array we have to use vectors.

int main(void)

{
    cout << "Q1 - Number of Comparisons for Searching Algorithms " << endl;

    cout <<endl;

    int SizeOfArr; //We devlare a variable for the size of the array.

    cout << "Size of the Sorted Array> ";

    cin >> SizeOfArr; //We get the size of the array from the user.

    vector<int> RandomArray(SizeOfArr); //And we store the value to our vector array if we did not use vector array we couldn't store it because c++ does not allow dynamic arrays.
                                        
                                        //It requires constant values.

    for (int i=0; i < SizeOfArr; i++)

    {

            RandomArray[i]=rand()%SizeOfArr+0; //Our Random array is filled with random numbers.
       
    }

    cout << endl;
 
    int SearchNum; //We have declared a variable for the desired number that we want to search.

    cout << "Enter a number to search: ";

    cin >> SearchNum;  //We get the desired input from the user for our number.

    int CompNum=0; //We have declared a variable for how many times we have searched and went on a loop.

    RandomArray = RedistributionOfArray(RandomArray); //We are recalling the redistribition function to use it then convert our array into our sorted one.

     cout <<"******Sequential Search******" <<endl;

    int LineerResult = LineerSearch(RandomArray, SizeOfArr, SearchNum, &CompNum); //We are calling the LineerResult function for our process.

    (LineerResult == -1) //After we have returned a -1 value from the functions down below.

        ? cout << SearchNum << "is not on the list." //If the function can not find any value that is equal to our number from the array it displays this message.

        : cout << "Item founded at position " << LineerResult; //If it does we display its position.

        cout << endl;

        cout << "Number of Comparisons " << CompNum; //How many number of times we have went and looked for a number is given below.


    cout << endl;

    cout <<"******Binary Search******" <<endl;

    CompNum = 0;

    int BinaryResult = BinarySearch(RandomArray, 0, SizeOfArr-1, SearchNum, &CompNum); //We once again call our BinarySearch function.

    (BinaryResult == -1) // When we call the return value -1 we go on from here as we are checking whether or not we have the number we are looking for or not.

    ? cout << SearchNum << "is not on the list." //This line basically looks and says we do not have any equal number we are looking for at the moment.

    : cout << "Item founded at position " << BinaryResult; // This line searches and looks, after it finds an equal value we are displaying its index from the organized array.

    cout << endl;

    cout << "Number of Comparisons " << CompNum; //Number of comparisons are displayed right here.



    return 0;

}



int LineerSearch(vector<int>RandomArray, int SizeOfArr, int SearchNum, int *CompNum) //Our lineer search function.

{

    int i; //A variable for our for loop.

    for (int i=0; i <= SizeOfArr; i++) // As long as our size of array is greater and equal to we are searching.
    {
        if (RandomArray[i]==SearchNum) //If the RandomArray's index is equal to our desired search number we are returning the index.
        {
            return i;
            
        }
        (*CompNum)++; //Every time we go on from our loop CompNum is increased by one.
    }
    return -1; //Out of the loop we are sending a -1 value to our LineerResult in order to evaluate our values.
}




int BinarySearch(vector<int>RandomArray ,int BeginningOfArray, int EndOfArray, int SearchNum, int *CompNum)

{


    while (BeginningOfArray <= EndOfArray) //We are using a while loop for our BinarySearch as long as EndofArray is equal to BeginningOfArray and EndOfArray is greater than BeginningOfArray we are in a loop.

    {
        (*CompNum)++; //Every time we complete a loop the comparison number gets updated.

        int index = BeginningOfArray + (EndOfArray - BeginningOfArray) / 2; 

        if (RandomArray[index] == SearchNum) //We are checking if our desired number is in the middle index of the array.

        {

            return index; //If it in the middle we are returning the value of index.

        }

        if (RandomArray[index] < SearchNum) //If Search number that we are searching is greater then we are ignoring the left side of the array and look from the right side.

        {

            BeginningOfArray = index + 1; //After finding the value BeginningOfArray is updated to the index that we found + 1.

        }

        else //Otherwise if the number we are searching is smaller we ignore the right side of the array and look from the left side.

        {

            EndOfArray = index -1; //After finding it we are Setting the end of the array to the index we have found -1.

        }
        

    }
    
     return -1; //If we have come to this point that means the number was not present in the array we created.

}



vector<int> RedistributionOfArray(vector<int>RandomArray) //We are organizing our vector array because it is performing better in binary search and after redestribition we are avoiding errors when searching.

{

    sort(RandomArray.begin(), RandomArray.end()); //This sort functions sorts our RandomArray in a non decreasing order with the help of algorithm library.


    return RandomArray; //And after that we are returning the RandomArray value to be set to a new sorted value.

}


//I was going to use VisualStudio for the code but i couldnt it kept giving me error in the case of not having on the list instead i have used VisualStudioCode.

//I have added ScreenShots of the error and the working screenshots in the rar.