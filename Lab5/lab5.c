/*
 This is lab 5. The program will ask the user if they want to pop, push, enqueue, dequeue, add element(push/enqueue),
 remove element(pop/dequeue), empty queue, empty stack, print queue, print stack, or print moves for a linked list
 and array. When the user wants to push or enqueue, the program will ask for a first name, last name, PUID, and age.
 The program will then create a node of the structure and either add it to the stack or queue. When the user is done
 with the program, they can enter 12 to exit the program.
*/

//imported libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defined constants
#define MAX_LEN 50

//global variables for counting moves
int movesStackLL = 0;
int movesStackA = 0;
int movesQueueLL = 0;
int movesQueueA = 0;

//Structures
//====================================================================================================================
//Structure NodeLL: contains fName, lName, PUID, Age, and next pointer for linked list
struct NodeLL
{
    char fName[MAX_LEN];
    char lName[MAX_LEN];
    char puid[MAX_LEN];
    char age[MAX_LEN];
    struct NodeLL *next;
};

//Structure NodeA: contains fName, lName, PUID, and Age for array
struct NodeA
{
    char fName[MAX_LEN];
    char lName[MAX_LEN];
    char puid[MAX_LEN];
    char age[MAX_LEN];
};

//Stack data structure with linked list
//====================================================================================================================
//Function PushLL: pushed a data node onto the top of the stack.
void pushLL(struct NodeLL **top, char *fName, char *lName, char *puid, char *age)
{
    struct NodeLL *newNode = (struct NodeLL *) malloc(sizeof(struct NodeLL));    //create node/allocate space
    strcpy(newNode->fName, fName);	//insert data into new node
    strcpy(newNode->lName, lName);
    strcpy(newNode->puid, puid);
    strcpy(newNode->age, age);
    newNode->next = *top;	//set next pointer to top
    *top = newNode;	//set top to new node address
    printf("\nNode added to the stack linked list\n");
    movesStackLL++;
}

//Function PopLL: takes the top node off the stack and returns the data
void popLL(struct NodeLL **top)
{
    struct NodeLL *tmp;   //new temp node
    if(top == NULL || *top == NULL)
    {
        printf("\nCan't perform pop action, stack linked list is empty!\n");
        return; //return if linked list is empty
    }

    tmp = *top;    //store top to temp node
    printf("\nStack linked list node deleted!\n");
    printf("===========================\n");
    printf("Name: %s %s\nPUID: %s\nAge: %s\n", tmp->fName, tmp->lName, tmp->puid, tmp->age);
    *top = (*top)->next;  //move head to next node
    free(tmp);  //delete first node
    movesStackLL++;
}

//Function SizeLL: returns the size of the stack
int sizeLL(struct NodeLL *top)
{
    int count = 0;
    while(top != NULL)  //traverse linked list
    {
        top = top->next;
        count++;    //increment counter
    }
    return count;
}

//Function EmptyLL: returns a boolean (true = 0 nodes | false = > 0 nodes)
int emptyLL(struct NodeLL *top)
{
    int num = sizeLL(top);  //use size function to return empty or not
    if(num == 0)
        return 1;
    return 0;
}

//Stack data structure with arrays
//====================================================================================================================
//Function PushA: pushed a data node onto the top of the stack.
int pushA(struct NodeA *stack, int index, char *fName, char *lName, char *puid, char *age) {
    if (index == MAX_LEN - 1)
    {
        printf("Error: stack overflow\n");  //stack is full
        return index;
    }
    index++;    //increment index
    strcpy(stack[index].fName, fName);	//insert data into new node
    strcpy(stack[index].lName, lName);
    strcpy(stack[index].puid, puid);
    strcpy(stack[index].age, age);

    printf("Node added to the stack array!\n");
    movesStackA++;
    return index;
}

//Function PopA: takes the top node of the stack and returns the data to the program
int popA(struct NodeA *stack, int index)
{
    if(index == -1) //return if linked list is empty
    {
        printf("Can't perform pop action, stack array is empty!\n");
        return index;
    }
    printf("\nStack array node deleted!\n");    //print data of deleted node
    printf("======================\n");
    printf("Name: %s %s\n", stack[index].fName, stack[index].lName);
    printf("PUID: %s\n", stack[index].puid);
    printf("Age: %s\n", stack[index].age);
    index--;
    movesStackA++;
    return index;
}

//Function SizeA: returns the size of the stack
int sizeA(int index)
{
    if(index == -1) //used index to return size
        return 0;
    else
        return index + 1;
}

//Function EmptyA: returns a boolean (true = no nodes | false = > 0 nodes)
int emptyA(int index)
{
    int num = sizeA(index); //used size function to return emtpy or not
    if(num == 0)
        return 1;
    else
        return 0;
}

//Queue data structure using linked list
//====================================================================================================================
//Function EnqueueLL: adds a data node onto the back of the queue.
void enqueueLL(struct NodeLL **top, char *fName, char *lName, char *puid, char *age)
{
    struct NodeLL *newNode = (struct NodeLL *) malloc(sizeof(struct NodeLL));    //create new node and allocate space
    strcpy(newNode->fName, fName);	//insert data into new node
    strcpy(newNode->lName, lName);
    strcpy(newNode->puid, puid);
    strcpy(newNode->age, age);
    newNode->next = NULL;   //pointer = null

    if(*top == NULL)    //if LL null, add node to front
    {
        *top = newNode;
        printf("\nNode added to the queue linked list\n");
        movesQueueLL++;
        return;
    }

    struct NodeLL *lastNode = *top;
    while(lastNode->next != NULL)	//loop until at the end of linked list
    {
        lastNode = lastNode->next;    //traversing the linked list
        movesQueueLL++;
    }
    lastNode->next = newNode;	//set last node pointer to new node(last list)
    movesQueueLL++;
    printf("\nNode added to the queue linked list\n");
}

//Function DequeueLL: takes the front node from the queue and returns the data to the program.
void dequeueLL(struct NodeLL **top)
{
    struct NodeLL *tmp;   //new temp node
    if(top == NULL || *top == NULL) //return if LL is empty
    {
        printf("\nCan't perform dequeue action, queue linked list is empty!\n");
        return;
    }

    tmp = *top;    //store top to temp node
    printf("\nQueue linked list node deleted!\n");  //print data
    printf("===========================\n");
    printf("Name: %s %s\nPUID: %s\nAge: %s\n", tmp->fName, tmp->lName, tmp->puid, tmp->age);
    *top = (*top)->next;  //move head to next node
    free(tmp);  //delete first node
    movesQueueLL++;
}


//Queue data structure with arrays
//====================================================================================================================
//Function EnqueueA: adds a data node onto the back of the queue.
int enqueueA(struct NodeA *queue, int index, char *fName, char *lName, char *puid, char *age) {
    if (index == MAX_LEN - 1)
    {
        printf("Error: stack overflow\n");  //stack is full
        return index;
    }
    index++;    //increment index
    strcpy(queue[index].fName, fName);	//insert data into new node
    strcpy(queue[index].lName, lName);
    strcpy(queue[index].puid, puid);
    strcpy(queue[index].age, age);

    printf("Node added to the queue array!\n");
    movesQueueA++;
    return index;
}

//Function DequeueA: takes the front node from the queue and returns the data to the program.
int dequeueA(struct NodeA *queue, int index)
{
    if (index == -1)
    {
        printf("Can't perform dequeue action, queue array is empty!\n");
        return index; // return if array is empty
    }

    // Print the data of the first element to be removed
    printf("\nQueue array node deleted!\n");
    printf("======================\n");
    printf("Name: %s %s\n", queue[0].fName, queue[0].lName);
    printf("PUID: %s\n", queue[0].puid);
    printf("Age: %s\n", queue[0].age);

    // Shift the remaining elements to the left to overwrite the first element
    for (int i = 0; i < index; i++)
    {
        queue[i] = queue[i + 1];
        movesQueueA++;
    }

    index--; // Decrease the index to reflect the removal of the first element
    return index;
}

//Print Functions
//====================================================================================================================
//Function PrintStackLL: prints entire linked list stack
void printStackLL(struct NodeLL *top)
{
    if(top == NULL)
    {
        printf("The stack linked list is empty!\n");
        return;
    }

    while(top != NULL)
    {
        printf("\nName: %s %s\nMajor: %s\nGPA: %s\n", top->fName, top->lName, top->puid, top->age);
        top = top->next;
    }
}

//Function PrintStackA: prints entire array stack
void printStackA(struct NodeA *stack, int index)
{
    if(index == -1)
    {
        printf("The stack array is empty!\n");
        return;
    }

    for (int i = 0; i <= index; i++)
    {
        printf("\nName: %s %s\n", stack[i].fName, stack[i].lName);
        printf("PUID: %s\n", stack[i].puid);
        printf("Age: %s\n", stack[i].age);
    }
}

//Function PrintQueueLL: prints entire linked list queue
void printQueueLL(struct NodeLL *top)
{
    if(top == NULL)
    {
        printf("The queue linked list is empty!\n");
        return;
    }

    while(top != NULL)
    {
        printf("\nName: %s %s\nMajor: %s\nGPA: %s\n", top->fName, top->lName, top->puid, top->age);
        top = top->next;
    }
}

//Function PrintQueueA: prints entire array queue
void printQueueA(struct NodeA *stack, int index)
{
    if(index == -1)
    {
        printf("The queue array is empty!\n");
        return;
    }

    for (int i = 0; i <= index; i++)
    {
        printf("\nName: %s %s\n", stack[i].fName, stack[i].lName);
        printf("PUID: %s\n", stack[i].puid);
        printf("Age: %s\n", stack[i].age);
    }
}

//Menu/input
//====================================================================================================================
//Function Menu: displays a menu with options for the user to pick from
void menu()
{
    printf("\n\nSelect a menu option!\n");
    printf("=========================\n");
    printf("1. Pop\n");
    printf("2. Push\n");
    printf("3. Enqueue\n");
    printf("4. Dequeue\n");
    printf("5. Add element\n");
    printf("6. Remove element\n");
    printf("7. Empty queue\n");
    printf("8. Empty stack\n");
    printf("9. Print queue\n");
    printf("10. Print stack\n");
    printf("11. Print moves\n");
    printf("12. Exit\n");
    printf("\nEnter a number between 1 and 12: ");
}

//Function input: asks the user for input of data
void input(char *fName, char *lName, char *puid, char *age)
{
    printf("Enter first name: ");
    scanf("%s", fName);
    printf("Enter last name: ");
    scanf("%s", lName);
    printf("Enter PUID: ");
    scanf("%s", puid);
    printf("Enter Age: ");
    scanf("%s", age);
}

//main function
//====================================================================================================================
int main()
{
    //menu variables
    int choice;
    char temp;

    //user input variables
    char fName[MAX_LEN];
    char lName[MAX_LEN];
    char puid[MAX_LEN];
    char age[MAX_LEN];

    //stack, queue, and array variables
    struct NodeLL *stackTop = NULL;
    struct NodeLL *queueTop = NULL;
    struct NodeA stack[MAX_LEN];
    struct NodeA queue[MAX_LEN];
    int stackIndex = -1;
    int queueIndex = -1;

    //while loop in case user wants to run functions again
    do{
        menu();    //called menu function

        if(scanf("%d", &choice) != 1)    //input validation
        {
            printf("Please enter a number between (1-12).\n");
            scanf("%s", &temp);    //clear input buffer
            continue;
        }

        //switch case for menu options
        switch(choice)
        {
            //pop case (delete node from the stack (LL/A))
            case 1:
                popLL(&stackTop);
                stackIndex = popA(stack, stackIndex);
                break;

            //push case (add node to stack (LL/A))
            case 2:
                input(fName, lName, puid, age);
                pushLL(&stackTop, fName, lName, puid, age);
                stackIndex = pushA(stack, stackIndex, fName, lName, puid, age);
                break;

            //enqueue case (add node to the queue (LL/A))
            case 3:
                input(fName, lName, puid, age);
                enqueueLL(&queueTop, fName, lName, puid, age);
                queueIndex = enqueueA(queue, queueIndex, fName, lName, puid, age);
                break;

            //dequeue case (delete node from the queue (LL/A))
            case 4:
                dequeueLL(&queueTop);
                queueIndex = dequeueA(queue, queueIndex);
                break;

            //add element case (both push and enqueue)
            case 5:
                input(fName, lName, puid, age);
                pushLL(&stackTop, fName, lName, puid, age);
                stackIndex = pushA(stack, stackIndex, fName, lName, puid, age);
                enqueueLL(&queueTop, fName, lName, puid, age);
                queueIndex = enqueueA(queue, queueIndex, fName, lName, puid, age);
                break;

            //remove element case (both pop and dequeue)
            case 6:
                popLL(&stackTop);
                stackIndex = popA(stack, stackIndex);
                dequeueLL(&queueTop);
                queueIndex = dequeueA(queue, queueIndex);
                break;

            //empty queue case (remove all nodes from queue)
            case 7:
                //empty queue linked list
                if(emptyLL(queueTop) == 1)  //LL is empty
                    printf("\nNothing to empty, linked list queue is empty!\n");
                else
                {
                    while(!emptyLL(queueTop))
                    {
                        struct NodeLL *temp = queueTop;
                        queueTop = queueTop->next;  //go to next node
                        free(temp); //free memory
                    }
                    printf("\nLinked list queue nodes deleted!\n");
                }

                //empty queue array
                if(emptyA(queueIndex) == 1)
                    printf("\nNothing to empty, array queue is empty!\n");
                else
                {
                    while(!emptyA(queueIndex))
                        queueIndex--;
                    printf("\nArray queue nodes deleted!\n");
                }
                break;

            //empty stack case (remove all nodes from stack (LL/A))
            case 8:
                //empty stack linked list
                if(emptyLL(stackTop) == 1)
                    printf("\nNothing to empty, linked list stack is empty!\n");
                else
                {
                    while(!emptyLL(stackTop)) {
                        struct NodeLL *temp = stackTop;
                        stackTop = stackTop->next;  //go to next node
                        free(temp); //free memory
                    }
                    printf("\nLinked list stack nodes deleted!\n");
                }

                //empty stack array
                if(emptyA(stackIndex) == 1)
                    printf("\nNothing to empty, array stack is empty!\n");
                else
                {
                    while(!emptyA(stackIndex))
                        stackIndex--;
                    printf("\nArray stack nodes deleted!\n");
                }
                break;

            //print queue case (print all nodes in queue order (LL/A))
            case 9:
                printf("\nThe queue linked list:\n");
                printf("====================================\n");
                printQueueLL(queueTop);
                printf("\nThe queue array:\n");
                printf("====================================\n");
                printQueueA(queue, queueIndex);
                break;

            //print stack case (print all nodes in stack order (LL/A))
            case 10:
                printf("\nThe stack linked list:\n");
                printf("====================================\n");
                printStackLL(stackTop);
                printf("\nThe stack array:\n");
                printf("====================================\n");
                printStackA(stack, stackIndex);
                break;

                //print number of moves case (# for LL, # for A)
            case 11:
                printf("\nStack linked list moves: %d", movesStackLL);
                printf("\nStack array moves: %d", movesStackA);
                printf("\nQueue linked list moves: %d", movesQueueLL);
                printf("\nQueue array moves: %d", movesQueueA);
                break;

            //end program case
            case 12:
                printf("Exiting the program.\n");
                break;

            //if user selects invalid option
            default:
                printf("Please enter a number between (1-12).\n");
                break;

        }//end switch
    } while(choice != 12);
    return 0;
}//end main