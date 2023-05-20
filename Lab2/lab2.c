/*
 This is Lab 2. We have a menu with 5 options. The 5 options correspond to 5 functions. I use a case statement
 for the selection of different options. The user enters a number and then the program runs a function. In this
 program you can calculate the volume and water cost to fill a pool or hottub, calculate the factorial of a number,
 count the number of moves with the Tower of Hanoi, calculate the fibonacci sequence of a number,
 calculate the sum of N, or end the program.
*/

//import libraries
#include <stdio.h>

//define constants
#define PI 3.1415

//Global variables
int functionCounter = 0;

function prototypes
int hottubOrPool();
float poolCalculation(float, float, float, float, float, float, float);
float hottubCalculation(float, float);
float calculateGallons(float);
int factorial(int);
void runHanoi(int, char, char, char);
int fibonacci(int);
int sum(int);

//main function
int main()
{
    //choice variables
    int hottubPoolChoice;
    int switchChoice;
    int over = 1;

    //Case variables
    int fact;
    int factResult;
    int hanoi;
    int fib;
    int sumVal;

    //hottub variables
    float hottubWidth;
    float hottubDepth;
    float hottubVolume;

    //Pool variables
    float poolWidth;
    float poolDepth;
    float poolLength;
    float poolDeepLength;
    float poolShallowLength;
    float poolShallowDepth;
    float poolwalkinLength;
    float walkinMaxLength;
    float shallowEndMexLength;
    float poolVolume;

    //code is enclosed in a do while to keep running until the user selects 6
    do{
        printf("\n\nWhat would you like to calculate?\n");
        printf("========================================\n");
        printf("1. Run pool or hottub function.\n");
        printf("2. Run factorial function.\n");
        printf("3. Run tower of hanoi function.\n");
        printf("4. Run fibonacci sequence function.\n");
        printf("5. Run sum of n function.\n");
        printf("6. End program.\n\n");
        printf("Enter a number between 1 and 6: ");
        scanf("%d", &switchChoice);

        //switch statement to pick options
        switch(switchChoice)
        {
            //option 1 pool or hottub menu, and calculations
            case 1:
                //called hottub/pool menu function
                hottubPoolChoice = hottubOrPool();

                //pool dimensions
                if(hottubPoolChoice == 1)
                {
                    //pool shallow end depth, loop/check
                    do{
                        printf("\nEnter the pool shallow end depth (0-5 feet): ");
                        scanf("%f", &poolShallowDepth);
                    }while(poolShallowDepth > 5 || poolShallowDepth < 0);

                    //Pool deep end depth, loop/check
                    do{
                        printf("\nEnter the pool deep end depth (6-15 feet): ");
                        scanf("%f", &poolDepth);
                    }while(poolDepth > 15 || poolDepth < 6);

                    //Pool width, loop/check
                    do{
                        printf("\nEnter the pool width (15-30 feet): ");
                        scanf("%f", &poolWidth);
                    }while(poolWidth > 30 || poolWidth < 15);

                    //Pool length, loop/check
                    do{
                        printf("\nEnter the pool length (40-70 feet): ");
                        scanf("%f", &poolLength);
                    }while(poolLength > 70 || poolLength < 40);

                    //to calculate the walkin and shallow max length
                    walkinMaxLength = poolLength / 3;
                    shallowEndMexLength = poolLength / 2;

                    //Pool walkin length, loop/check
                    do{
                        printf("\nEnter the pool width (5-%.2f feet): ", walkinMaxLength);
                        scanf("%f", &poolwalkinLength);
                    }while(poolwalkinLength > walkinMaxLength || poolwalkinLength < 5);

                    //Pool shallow end length
                    do{
                        printf("\nEnter the pool shallow end length (10-%.2f feet): ", shallowEndMexLength);
                        scanf("%f", &poolShallowLength);
                    }while(poolShallowLength > shallowEndMexLength || poolShallowLength < 10);

                    //Pool deep end length, loop/check
                    do{
                        printf("\nEnter the pool deep end length (12-%.2f feet): ", shallowEndMexLength);
                        scanf("%f", &poolDeepLength);
                    }while(poolDeepLength > shallowEndMexLength || poolDeepLength < 12);

                    poolVolume = poolCalculation(poolWidth, poolDepth, poolLength, poolDeepLength,
                                                 poolShallowLength,
                                                 poolShallowDepth,
                                                 poolwalkinLength);
                    printf("\nPool volume: %.2f\n", poolVolume);
                    printf("Gallons: %.2f\n", calculateGallons(poolVolume));
                    functionCounter++;
                }

                //hottub dimensions
                if(hottubPoolChoice == 2)
                {
                    //hottubWidth, loop/check
                    do{
                        printf("\nEnter the hottub width (8-14 feet): ");
                        scanf("%f", &hottubWidth);
                    }while(hottubWidth > 14 || hottubWidth < 8);

                    //hottub depth, loop/check
                    do{
                        printf("\nEnter the hottub depth (3-5 feet): ");
                        scanf("%f", &hottubDepth);
                    }while(hottubDepth > 5 || hottubDepth < 3);

                    hottubVolume = hottubCalculation(hottubWidth, hottubDepth);
                    printf("\nHottub Volume: %.2f\n", hottubVolume);
                    printf("Gallons: %.2f\n", calculateGallons(hottubVolume));
                }
                break;

                //option 2 which runs the factorial function
            case 2:
                printf("\nEnter a number to find the factorial: ");
                scanf("%d", &fact);
                factResult = factorial(fact);
                printf("Input: %d\nOutput: %d\n", fact, factResult);
                functionCounter++;
                break;

                //option 3 which runs the function towner of hanoi function
            case 3:
                printf("\nEnter the amount of disks you want to use: ");
                scanf("%d", &hanoi);
                runHanoi(hanoi, 'A', 'B', 'C');
                functionCounter++;
                break;

                //option 4 which runs the fibonacci function
            case 4:
                printf("\nEnter the amount of numbers for the sequence: ");
                scanf("%d", &fib);
                printf("Sequence to %d term(s): ", fib);

                for(int i = 0; i < fib; i++)
                {
                    printf("%d ", fibonacci(i));
                }
                functionCounter++;
                break;

                //option 5 which runs the sum of N function
            case 5:
                printf("\nEnter a number to find the sum of all integers: ");
                scanf("%d", &sumVal);
                printf("\nSum: %d", sum(sumVal));
                functionCounter++;
                break;

                //option 6 which end the program
            case 6:
                over = 0;
                break;

                //default is used in case of a invalid number
            default:
                printf("\nEnter a valid number!\n");
        }
    }while(over);
    printf("\n%d function(s) ran!\n\n", functionCounter);

    return 0;
}

//function to pick pool or hottub
int hottubOrPool()
{
    int choice;
	printf("\nSelect an option!\n");
	printf("========================\n");
	printf("1. Calculate a pool.\n");
	printf("2. Calculate a hottub.\n");
	printf("\nEnter 1 or 2: ");
	scanf("%d", &choice);
	return choice;
}

//function to calculate volume and water cost of pool
float poolCalculation(float width, float depth, float length, float deepLength, float shallowLength, float shallowDepth, float walkinLength)
{
	float deepEnd;
	float deepTransition;
   	float shallowEnd;
	float walkinTransition;
	float totalVolume;

    //deep end calculation
	deepEnd = ((depth - .5) * deepLength) * width;

	//transition calculation
	deepTransition = (((depth - .5) + (shallowDepth - .5)) * ((length - (shallowLength + walkinLength + deepLength)) / 2)) * width;

	//shallow end calculation
	shallowEnd = ((shallowDepth - .5) * shallowLength) * width;

	//entrence calculation
	walkinTransition = ((shallowDepth - .5) * (walkinLength - .5)) / 2 * width;

	//total calculation
	totalVolume = deepEnd + deepTransition + shallowEnd + walkinTransition;
	return totalVolume;
}

//function to calculate volume and water cost of hottub
float hottubCalculation(float width, float depth)
{
	float volume;
	volume = ((.5 * width) * (.5 * width) * PI * (depth - .5));
	return volume;
}

//function to calculate gallons
float calculateGallons(float volume)
{
	float gallons;
	gallons = volume * 7.481;
    return gallons;
}

//function to calculate the factorial of a number
int factorial(int n)
{
	if(n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

//Tower of hanoi function
void runHanoi(int n, char fromRod, char midRod, char toRod)
{
	if(n == 1)
        printf("\nMove disk 1 from rod %c to rod %c", fromRod, toRod);

    else
    {
		runHanoi(n - 1, fromRod, toRod, midRod);
		printf("\nMove disk %d from rod %c to rod %c", n, fromRod, toRod);
		runHanoi(n - 1, midRod, fromRod, toRod);
    }
}

//fibonacci function
int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

//Sum of N function
int sum(int n) {
    if (n <= 1)
        return n;
    else
        return n + sum(n - 1);
}