/*
This program will calculate the volume, gallons, and cost to fill a pool and hottub.
The program will ask the user to enter many dimensions which will be used to calculate
the volume, gallons, and cost to fill a hottub and pool.
*/

//import libraries
#include <math.h>
#include <stdio.h>
#include <string.h>

//define constants
#ifndef M_PI
#define M_PI acos(-1.0)
#endif

//function to calculate the volume of a hottub
float hottubVolume(float width, float depth)
{
	float volume;
	volume = ((.5 * width) * (.5 * width) * M_PI * (depth - .5));
	
	return volume;
}

//function to calculate the volume of a pool
float poolVolume(float width, float depth, float length, float deepLength, float shallowLength, float shallowDepth, float walkinLength)
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

//function to calculate the amount of gallons from cubic feet
float calculateGallons(float volume)
{
	float gallons;
	gallons = volume * 7.481;
	return gallons;
}

//function to calculate the cost
float calculateCost(float gallons)
{
	float cost;
	float quart;
	quart = gallons * 4;
	cost = quart * .07;
	return cost;
}

//Displays the dimensions of the hottub and pool
void displayInfo(float hWidth, float hDepth, float pShallowDepth, float pDepth, float pWidth, float pLength, float pwalkinLength, float pShallowLength, float pDeepLength)
{
	printf("\nHottub width: %.2f", hWidth);
	printf("\nHottub depth: %.2f", hDepth);
	printf("\nPool shallow end depth: %.2f", pShallowDepth);
	printf("\nPool deep end depth: %.2f", pDepth);
	printf("\nPool width: %.2f", pWidth);
	printf("\nPool length: %.2f", pLength);
	printf("\nPool walkin length: %.2f", pwalkinLength);
	printf("\nPool shallow end length: %.2f", pShallowLength);
	printf("\nPool deep end length: %.2f", pDeepLength);
}

//main function
int main()
{
	//Outter-loop variable
	int over1 = 1;
	
	//Hottub variables
	float hottubWidth;
	float hottubDepth;
	float finalHottubVolume;
	
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
	float finalPoolVolume;

	//total variables
	float hottubGallons;
	float poolGallons;
	float totalGallons;
	float hottubCost;
	float poolCost;
	float totalCost;
	
	//While loop, another pool check
	while(over1)
	{
		//Inner-loop variables
		int over2 = 1;
		int over3 = 1;
		int over4 = 1;
		int over5 = 1;
		int over6 = 1;
		int over7 = 1;
		int over8 = 1;
		int over9 = 1;
		int over10 = 1;
		int choice;

		//Hottub width, loop/check
		while(over2)
		{
			printf("\nEnter the hottub width (8-14 feet): ");
			scanf("%f", &hottubWidth);
			
			if(hottubWidth <= 14 && hottubWidth >= 8)
			{
				over2 = 0;
			}
			
			else
			{
				over2 = 1;
				printf("\nPlease enter a number between 8 and 14!");
			}
		}

		//Tottub depth, loop/check
		while(over3)
		{
			printf("\nEnter the hottub depth (3-5 feet): ");
			scanf("%f", &hottubDepth);
			
			if(hottubDepth <= 5 && hottubDepth >= 3)
			{
				over3 = 0;
			}
			
			else
			{
				over3 = 1;
				printf("\nPlease enter a number between 3 and 5!");
			}
		}

		//pool shallow end depth, loop/check
		while(over4)
		{
			printf("\nEnter the pool shallow end depth (0-5 feet): ");
			scanf("%f", &poolShallowDepth);
			
			if(poolShallowDepth <= 5 && poolShallowDepth >= 0)
			{
				over4 = 0;
			}
			
			else
			{
				over4 = 1;
				printf("\nPlease enter a number between 0 and 5!");
			}
		}

		//Pool deep end depth, loop/check
		while(over5)
		{
			printf("\nEnter the pool deep end depth (6-15 feet): ");
			scanf("%f", &poolDepth);
			
			if(poolDepth <= 15 && poolDepth >= 6)
			{
				over5 = 0;
			}
			
			else
			{
				over5 = 1;
				printf("\nPlease enter a number between 6 and 15!");
			}
		}

		//Pool width, loop/check
		while(over6)
		{
			printf("\nEnter the pool width (15-30 feet): ");
			scanf("%f", &poolWidth);
			
			if(poolWidth <= 30 && poolWidth >= 15)
			{
				over6 = 0;
			}
			
			else
			{
				over6 = 1;
				printf("\nPlease enter a number between 15 and 30!");
			}
		}

		//Pool length, loop/check
		while(over7)
		{
			printf("\nEnter the pool length (40-70 feet): ");
			scanf("%f", &poolLength);
			
			if(poolLength <= 70 && poolLength >= 40)
			{
				walkinMaxLength = poolLength / 3;
				shallowEndMexLength = poolLength / 2;
				over7 = 0;
			}
			
			else
			{
				over7 = 1;
				printf("\nPlease enter a number between 40 and 70!");
			}
		}

		//Pool walkin length, loop/check
		while(over8)
		{
			printf("\nEnter the pool width (5-%.2f feet): ", walkinMaxLength);
			scanf("%f", &poolwalkinLength);
			
			if(poolwalkinLength <= walkinMaxLength && poolwalkinLength >= 5)
			{
				over8 = 0;
			}
			
			else
			{
				over8 = 1;
				printf("\nPlease enter a number between 5 and %.2f!", walkinMaxLength);
			}
		}

		//Pool shallow end length
		while(over9)
		{
			printf("\nEnter the pool shallow end length (10-%.2f feet): ", shallowEndMexLength);
			scanf("%f", &poolShallowLength);
			
			if(poolShallowLength <= shallowEndMexLength && poolShallowLength >= 10)
			{
				over9 = 0;
			}
			
			else
			{
				over9 = 1;
				printf("\nPlease enter a number between 10 and %.2f!", shallowEndMexLength);
			}
		}

		//Pool deep end length, loop/check
		while(over10)
		{
			printf("\nEnter the pool deep end length (12-%.2f feet): ", shallowEndMexLength);
			scanf("%f", &poolDeepLength);
			
			if(poolDeepLength <= shallowEndMexLength && poolDeepLength >= 12)
			{
				over10 = 0;
			}
			
			else
			{
				over10 = 1;
				printf("\nPlease enter a number between 12 and %f.2!", shallowEndMexLength);
			}
		}

		//called the displayInfo function to display dimensions
		displayInfo(hottubWidth, hottubDepth, poolShallowDepth, poolDepth, poolWidth, poolLength, poolwalkinLength, poolShallowLength, poolDeepLength);

		//called the hottube and pool volume functions and displayed the values
		finalHottubVolume = hottubVolume(hottubWidth, hottubDepth);
		finalPoolVolume = poolVolume(poolWidth, poolDepth, poolLength, poolDeepLength, poolShallowLength, poolShallowDepth, poolwalkinLength);
		printf("\n\nThe hottub volume is: %.2f", finalHottubVolume);
		printf("\nThe pool volume is: %.2f", finalPoolVolume);

		//called the calculateGallons function and displayed the values
		hottubGallons = calculateGallons(finalHottubVolume);
		poolGallons = calculateGallons(finalPoolVolume);
		totalGallons = hottubGallons + poolGallons;
		printf("\n\nThe total gallons for the hottub is: %.2f", hottubGallons);
		printf("\nThe total gallons for the pool is: %.2f", poolGallons);
		printf("\nThe total gallons is: %.2f", totalGallons);

		//called the calculateCost function and displayed the values
		hottubCost = calculateCost(hottubGallons);
		poolCost = calculateCost(poolGallons);
		totalCost = hottubCost + poolCost;
		printf("\n\nThe total cost for the hottub is: $%.2f", hottubCost);
		printf("\nThe total cost for the pool is: $%.2f", poolCost);
		printf("\nThe total cost is: $%.2f", totalCost);
		
		//calculate another pool/hottub prompt
		printf("\n\nWould you like to calculate another pool?\n");
		printf("Type 1 for yes and 0 for no: ");
		scanf("%d", &choice);

		if(choice == 1)
		{
			over1 = 1;
		}

		else
		{
			over1 = 0;
		}
	}

	return 0;
}
