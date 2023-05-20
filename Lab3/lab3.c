/*
 This is Lab 3. It provides the user with a menu selection for an int array of numbers,
 char array of words, and the option to end the program. For option 1, the user will be
 asked to enter the array size and numbers for the array. The program will then sort the
 array of numbers in descending order using a bubble, selection, and quick sort. The
 functions will return the amount of moves it took for the sorts to complete.
 The second menu option will ask the user for a char array(sting) of words. The program
 will reverse the string with pass by value and pass by reference. The program will
 then tell the user if the word is a palindrome or not. Code for the bubble sort function
 was from, https://www.tutorialspoint.com/c-program-for-recursive-bubble-sort.
 Code for the selection and quick sort functions was from ChatGPT. The string reversal
 pass by reference code was from https://www.geeksforgeeks.org/reverse-a-string-using-recursion/.
 The string reversal pass by value code was from ChatGPT. The palindrome function code was from
 https://www.geeksforgeeks.org/c-program-check-given-string-palindrome/.

 Analysis
 =======================
 Arrays used:
    Completely sorted: 6 5 4 3 2 1
    Almost sorted: 6 5 4 3 1 2
    Half sorted: 6 5 4 9 4 6
    Completely unsorted: 1 2 3 4 5 6

 Bubble sort moves:
    Completely sorted: 0
    Almost sorted: 1
    Half sorted: 6
    Completely unsorted: 15

 Selection Sort moves:
    Completely sorted: 5
    Almost sorted: 5
    Half sorted: 5
    Completely unsorted: 5

 Quick Sort moves:
    Completely sorted: 2
    Almost sorted: 2
    Half sorted: 5
    Completely unsorted: 4
*/

//import libraries
#include <stdio.h>
#include <string.h>

//function to print array
void printArray(int arr[], int size)
{
    printf("\nArray: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

//Swap function with int pointers
void intSwap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

//Swap function with char pointers
void charSwap(char *ptr1, char *ptr2)
{
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

//Bubble sort function
int bubbleSort(int arr[], int size) //parameters are array and size of array
{
    int moves = 0;  //declare and initialize moves to count swaps
    if(size == 1)   //if the size of the array is 1
        return moves;   //return moves

    for(int i = 0; i < size - 1; i++)   //loop through the array
    {
        if(arr[i] < arr[i + 1]) //if position 1 is less than position 2
        {
            intSwap(&arr[i], &arr[i + 1]); //swap positions with the intSwap function
            moves++;    //increase moves by 1
        }
    }
    size--; //decrease size by 1
    return moves + bubbleSort(arr, size);   //return the amount of moves and recursive step
}

//selection sort function
int selectionSort(int arr[], int size)  //parameters are array and size of array
{
    int moves = 0;  //declare and initialize moves to count swaps
    if (size <= 1)  //if at the end of array
        return 0;   //return amount of moves

    int max = 0;    //declare and initialize max variable for max element
    for (int i = 1; i < size; i++)  //loop through the remaining array
        if (arr[i] < arr[max])  //find the index of the max element
            max = i;    //set it to max

    intSwap(&arr[max], &arr[size - 1]); //swap positions with the intSwap function
    moves++;    //increase moves by 1
    return moves + selectionSort(arr, size - 1);    //return moves and recursive step
}

//quick sort function
int quickSort(int arr[], int left, int right)   //parameters are the array and beg. and end of array
{
    int i = left; //declare and initialize i to left
    int j = right;  //declare and initialize j to right
    int pivot = arr[(left + right) / 2];    //declare and initialize the pivot position (middle element)
    int moves = 0;   //declare and initialize moves for amount of swaps

    while(i <= j)   //partition the array into two subarrays
    {
        while(arr[i] > pivot)  //find first element on left that's > pivot
            i++;    //increment i by 1
        while(arr[j] < pivot)  //find first element on right that's < pivot
            j--;    //decrement j by 1
        // Swap the two elements
        if(i <= j) //if elements are on wrong side of partition, intSwap
        {
            intSwap(&arr[i], &arr[j]); //swap using intSwap function
            moves++;    //increase moves by 1
            i++;    //increment i by 1
            j--;    //decrement j by 1
        }
    }

    if(left < j)    // Recursively call quickSort() on the subarrays
        return moves + quickSort(arr, left, j); //return moves and recursive step with first subarray
    if(i < right)
        return moves + quickSort(arr, i, right);    //return moves and recursive step with second subarray
    return moves;   //return moves
}

//reverse string (pass by reference)
void reverseStringReference(char *str)  //parameter is pointer to a character array
{
    if (*str) //check if first character of string is null or not
    {
        reverseStringReference(str+1);  //recursion to call function shifted to the next char
        printf("%c", *str); //print character
    }
}

//reverse string (pass by value)
void reverseStringValue(char str[], int start, int end) //parameters are array, start and end index
{
	if(start >= end)    //if start index is greater than end index
		return; //then return
    charSwap(&str[start], &str[end]);   //swap values
	reverseStringValue(str, start + 1, end - 1);    //recursion, start increased by 1, end decreased by 1
}

//palindrome function
int palindrome(char *str, int l, int r){    //parameters: string, start and end elements
    if(NULL == str || l < 0 || r < 0)   //check for invalid strings (null or negative)
        return 0;   //then not palindrome
    if(l >= r)  //if indices meet or cross
        return 1;   //then palindrome
    if(str[l] == str[r])    //if left and fight characters match
        return palindrome(str, l + 1, r - 1);   //then check next set
    return 0;   //if, if does not catch return 0
}

//main function
int main()
{
    //loop variables
    int over = 1;
    int switchChoice;

    //do/while loop in case user wants to run functions again
    do
    {
        //case 1 (array of int) variables
        int arrSize = 5;
        int bubbleArr[arrSize];
        int selectionArr[arrSize];
        int quickArr[arrSize];

        //case 2 (string of words) variables
        char valueStr[50];
        char referenceStr[50];

        //menu options
        printf("\n\nSelect a menu option!\n");
        printf("=========================\n");
        printf("1. Array of numbers\n");
        printf("2. Strings\n");
        printf("3. End program\n");
        printf("\nEnter a number between 1 and 3: ");
        scanf("%d", &switchChoice);

        //switch case for menu options
        switch(switchChoice)
        {
            //array of numbers option
            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &arrSize);
                printf("Enter a sequence of numbers seperated by a comma or space: ");

                //scan values into array
                for(int i = 0; i < arrSize; i++)
                    scanf("%d,", &bubbleArr[i]);

                //copy original array into two other arrays
                for(int i = 0; i < arrSize; i++)
                {
                    selectionArr[i] = bubbleArr[i];
                    quickArr[i] = bubbleArr[i];
                }

                //print array
                printArray(bubbleArr, arrSize);

                //call and print bubble sort function
                printf("\n\nBubble Sort\n===================");
                printf("\n%d move(s) were made.", bubbleSort(bubbleArr, arrSize));
                printArray(bubbleArr, arrSize);

                //call and print selection sort function
                printf("\n\nSelection Sort\n===================");
                printf("\n%d move(s) were made.", selectionSort(selectionArr, arrSize));
                printArray(selectionArr, arrSize);

                //quick sort
                printf("\n\nQuick Sort\n===================");
                printf("\n%d move(s) were made.", quickSort(quickArr, 0, arrSize - 1));
                printArray(quickArr, arrSize);
                break;

            //strings option
            case 2:
                getchar();
                printf("\nEnter a string of words that are less than 50 characters: ");
                fgets(valueStr, sizeof(valueStr), stdin);
                printf("Original string: %s", valueStr);
                
                //copy value string into reference string
                for(int i = 0; i < sizeof(valueStr); i++)
                	referenceStr[i] = valueStr[i];
                
                //called pass by reference string function
                printf("\nPass by Reference String");
                printf("\n======================");
                reverseStringReference(referenceStr);
                
                //called pass by value string function
                printf("\n\nPass by Value String");
                printf("\n======================");
                reverseStringValue(valueStr, 0, strlen(valueStr) - 1);
                printf("%s", valueStr);

				//palindrome
				if(palindrome(referenceStr, 0, strlen(referenceStr) - 2))
                    printf("\n\nThe string is a palindrome");
                else
                    printf("\n\nThe string is not a palindrome");
                break;

            //end program
            case 3:
                over = 0;
                break;

            //if user selects invalid option
            default:
                printf("\nPlease enter a number between (1-3).\n");
        }
    }while(over);
}