/*
 This is lab 4. You have 4 menu option: print all students, insert a student, delete a student, and find a student.
 A linked list is already created with one node. The program will determine where to insert and delete based on GPA
 and last name. Code that I referenced from the internet is above the function.
*/

//import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants
#define MAX_LEN 50

//Structure Node: contains fName, lName, major, and GPA
struct Node
{
    char fName[MAX_LEN];
    char lName[MAX_LEN];
    char major[MAX_LEN];
    float gpa;
    struct Node *next;
};

//CreateListNoNodes function: create list with no nodes, just a start pointer
void createListNoNodes(struct Node **head)	//parameters: head pointer
{
    *head = NULL;
}

//CreateListNode function: create list with a single node
void createListNode(struct Node **head, char *fName, char *lName, char *major, float gpa)	//parameters: head pointer and data
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));	//create new node and allocate space
    strcpy(newNode->fName, fName);	//insert data into new node
    strcpy(newNode->lName, lName);
    strcpy(newNode->major, major);
    newNode->gpa = gpa;
    newNode->next = NULL;	//set node pointer to null
    *head = newNode;	//set head pointer to new node address
}

//InsertFront function: insert a node at the front of the list
void insertFront(struct Node **head, char *fName, char *lName, char *major, float gpa)	//parameters: head pointer and data
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));	//create new node and allocate space
    strcpy(newNode->fName, fName);	//insert data into new node
    strcpy(newNode->lName, lName);
    strcpy(newNode->major, major);
    newNode->gpa = gpa;
    newNode->next = *head;	//set node pointer to head value(pointer address)
    *head = newNode;	//set head to new node address
}

//InsertMiddle function: insert a node in the middle of the list
//ChatGPT was used for this function
void insertMiddle(struct Node **head, int position, char *fName, char *lName, char *major, float gpa)	//parameters: headpointer, position, and data
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));	//create new node and allocate space
    strcpy(newNode->fName, fName);	//insert data
    strcpy(newNode->lName, lName);
    strcpy(newNode->major, major);
    newNode->gpa = gpa;
    newNode->next = NULL;	//set node pointer to null 

    if(*head == NULL)   //if the head is null
    {
        *head = newNode;    //set it to the new node
        return;
    }

    int len = 1;
    struct Node *current = *head;   //create a new node and
    while(current->next != NULL)    //find the length of the list
    {
        current = current->next;    //loop through the list
        len++;  //increment len
    }

    if(position > len)  //if the position is greater than the length
    {
        printf("\nInvalid position try again!\n");  //print message and return
        return;
    }

    current = *head;
    int i = 1;
    while(i < position) //loop to get to the desired position
    {
        current = current->next;    //go to next node
        i++;    //increment
    }

    newNode->next = current->next;  //set new node pointer to the current node pointer
    current->next = newNode;    //set current pointer to new node addess
}

//InsertEnd function: insert a node at the end of a list
//ChatGPT was used for this function
void insertEnd(struct Node **head, char *fName, char *lName, char *major, float gpa)	//parameters: head pointer and data
{
    struct Node *newNode = NULL;	//create new node and set to null
    createListNode(&newNode, fName, lName, major, gpa);	//call create node function to set values

    struct Node *lastNode = *head;	//create temp node starting at head
    while(lastNode->next != NULL)	//loop until at the end of linked list
    	lastNode = lastNode->next;	//traversing the linked list

    lastNode->next = newNode;	//set last node pointer to new node(last list)
}

//DeleteFront function: delete the first node on the list
//https://qnaplus.com/c-program-to-delete-the-first-node-of-a-linked-list/
void deleteFront(struct Node **head)
{
    struct Node *tmp;   //new temp node

    if(head == NULL || *head == NULL)
        return; //return if linked list is empty

    tmp = *head;    //store head to temp variable
    *head = (*head)->next;  //move head to next node
    free(tmp);  //delete first node
}

//DeleteMiddle function: delete a node in the middle of the list.
//ChatGPT was used to create this function
void deleteMiddle(struct Node **head, int position)
{
    if (*head == NULL) {    //check if the linked list is null
        return;
    }

    struct Node *temp = *head;  //create temp node

    if (position == 0)  //if position is 0
    {
        *head = temp->next; //set head to temp pointer
        free(temp); //free memory
        return;
    }

    int i = 0;
    struct Node *prev = NULL;   //create anothe node

    while(temp != NULL && i < position)
    {
        prev = temp;    //set prev to temp
        temp = temp->next;  //set temp to temp pointer
        i++;    //increment
    }

    if (temp == NULL)   //return if temp is null
        return;

    prev->next = temp->next;    //set prev pointer to temp pointer
    free(temp); //free memory
}

//DeleteEnd function: delete a node at the end of the list
void deleteEnd(struct Node **head)
{
    if(head == NULL || *head == NULL)   //return of no nodes in the linked list
    {
        printf("\nThe linked list is empty!\n");
        return;
    }

    struct Node *temp = *head;  //store head to temp variable
    struct Node *secondLastNode = NULL;   //set secondLastNode to null

    while(temp->next->next != NULL)	//loop until second to last of linked list
        temp = temp->next;	//traversing the linked list

    secondLastNode = temp->next;  //set temp to second last node
    free(secondLastNode);  //delete last node
    temp->next = NULL;	//set new last node pointer to NULL
}

//Traverse function: traverse the list based on gpa and return position
//ChatGPT helped with the creation of the function
int traverse(struct Node *head, char lastName[], float gpa) {
    int pos = 0;
    struct Node* current = head;    //create node

    //loop to find the position based on decreasing GPA and last name in alphabetical order
    while (current != NULL && (current->gpa > gpa || (current->gpa == gpa && strcmp(current->lName, lastName) > 0)))
    {
        current = current->next;    //go to next node
        pos++;  //increment
    }
    return pos; //return position
}

//LookUpByIndex function: find a particular node by an index number.
//Return -1 if that index does not exist
int lookUpByIndex(struct Node *head, char name[])
{
    int position = 0;
    struct Node *current = head;    //create node
    while (current != NULL) //loop through linked list
    {
        if (strcmp(current->lName, name) == 0) //return position when last names match
            return position;
        current = current->next;    //go to next node
        position++; //increment
    }
    return -1; // value not found in list
}

//PrintNode function: print linked list
void printList(struct Node *head)
{
    if(head == NULL)
    {
        printf("\nThe linked list is empty!\n");
        return;
    }

    while(head != NULL)
    {
        printf("\nName: %s %s\nMajor: %s\nGPA: %.2f\n", head->fName, head->lName, head->major, head->gpa);
        head = head->next;
    }
}

//print one node
void printNode(struct Node *head, char name[]) {
    struct Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->lName, name) == 0) {
            printf("\nName: %s %s\nMajor: %s\nGPA: %.2f\n", head->fName, head->lName, head->major, head->gpa);
            return;
        }
        current = current->next;
    }
    printf("Node not found\n");
}

//NodeCount function: count the amount of nodes in the linked list
int nodeCount(struct Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

//main function
int main()
{
    //variables
    int choice;
    char temp;
    char fName[MAX_LEN];
    char lName[MAX_LEN];
    char major[MAX_LEN];
    float gpa;
    int gpaPosition;
    int namePosition;
    char deleteName[MAX_LEN];
    char studentName[MAX_LEN];

    //initialize head
    struct Node *head;
    createListNoNodes(&head);

    //initialize list
    createListNode(&head, "Bob", "Smith", "CIT", 3.7);

    //while loop in case user wants to run functions again
    do{
        //menu options
        printf("\n\nSelect a menu option!\n");
        printf("=========================\n");
        printf("1. Print all students\n");
        printf("2. Insert a student\n");
        printf("3. Delete a student\n");
        printf("4. Find a particular student\n");
        printf("5. End program\n");
        printf("\nEnter a number between 1 and 5: ");

        //input validation
        if(scanf("%d", &choice) != 1)
        {
            printf("Please enter a number between (1-5).\n");
            scanf("%s", &temp); //clear input buffer
            continue;
        }

        //switch case for menu options
        switch(choice)
        {
            //print all students case
            case 1:
                printList(head);
                break;

            //insert a student case
            case 2:
                printf("Enter first name: ");
                scanf("%s", fName);
                printf("Enter last name: ");
                scanf("%s", lName);
                printf("Enter major: ");
                scanf("%s", major);
                printf("Enter GPA: ");
                scanf("%f", &gpa);

                if(nodeCount(head) == 0)
                {
                    printf("\nThere are no nodes in the list!");
                    insertFront(&head, fName, lName, major, gpa);
                    break;
                }
                gpaPosition = traverse(head, lName, gpa);

                if(gpaPosition == 0)
                    insertFront(&head, fName, lName, major, gpa);
                else if(gpaPosition == nodeCount(head))
                    insertEnd(&head, fName, lName, major, gpa);
                else
                    insertMiddle(&head, gpaPosition, fName, lName, major, gpa);
                break;

            //delete a student case
            case 3:
                if(nodeCount(head) == 0)
                    printf("\nThere are no nodes to delete in the list!\n");

                printf("\nEnter the last name of the person you want to delete!");
                printf("\nEnter: ");
                scanf("%s", deleteName);

                namePosition = lookUpByIndex(head, deleteName);

                if(namePosition == -1)
                    printf("\nThere is nobody in the list with that name!\n");
                else if(namePosition == 0)
                    deleteFront(&head);
                else if(namePosition == nodeCount(head))
                    deleteEnd(&head);
                else
                    deleteMiddle(&head, namePosition);
                break;

            //find a particular student case
            case 4:
                printf("\nEnter the last name of a student: ");
                scanf("%s", studentName);
                printNode(head, studentName);
                break;

            //end program case
            case 5:
                printf("Exiting the program.\n");
                break;

            //if user selects invalid option
            default:
                printf("Please enter a number between (1-5).\n");
                break;
        }   //end switch
    } while(choice != 5);

    return 0;
}   //end main